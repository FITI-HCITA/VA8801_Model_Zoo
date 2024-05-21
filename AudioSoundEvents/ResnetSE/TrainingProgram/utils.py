import os, sys
import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.utils.data import Dataset, DataLoader
import numpy as np
from tensorboardX import SummaryWriter
import time
import gc
import librosa as lr
from pathlib import Path
from tqdm import tqdm


class Trainer(nn.Module):
    def __init__(self, net, criterion, loader, optimizer, scheduler, writer, args):
        super(Trainer, self).__init__()
        self.net = net
        self.criterion = criterion
        self.tr_loader = loader['tr_loader']
        self.cv_loader = loader['cv_loader']
        self.optimizer = optimizer
        self.scheduler = scheduler
        self.writer = writer
        self.ckpt = Path(args.ckpt)
        self.args = args
        #self.patience = args.patience
        self.best_loss = np.inf
        self.prev_loss = np.inf
        self.dry_run = args.dry_run
        self.ites_dry_run = args.ites_dry_run
        self.verbose = args.verbose
        self.resuming = args.resuming
        start_epoch = 0
        if args.resuming:
            print("{} Resume training from {}".format(time.ctime(), args.ckpt_path))
            ckpt = torch.load(args.ckpt_path)
            self.net.cpu()
            self.net.load_state_dict(ckpt['model'])
            self.net.to(args.device)
            self.optimizer.load_state_dict(ckpt['optimizer'])
            #
            if args.lr < self.optimizer.param_groups[0]['lr']:
                print("change lr of optimizer state {} to {}".format(self.optimizer.param_groups[0]['lr'], args.lr))
                self.optimizer.param_groups[0]['lr'] = args.lr
            #
            self.scheduler.load_state_dict(ckpt['scheduler'])
            self.best_loss = ckpt['best_loss']
            self.prev_loss = ckpt['prev_loss']
            start_epoch = ckpt['epoch']+1
        assert start_epoch < args.epochs
        self.epochs = range(start_epoch, args.epochs)

    def train(self):
        #
        trigger_times = 0
        print("{} Start training".format(time.ctime()))
        for epoch in self.epochs:
            #
            t = time.time()
            tr_loss, tr_acc = self.run_one_epoch(epoch, is_training=True)
            val_loss, val_acc = self.run_one_epoch(epoch, is_training=False)
            self.scheduler.step(val_loss)
            template = '\nETA: {} - epoch: {} loss: {:.5f} acc: {:.5f} val loss: {:.5f} val acc: {:.5f} lr: {}' 
            print(template.format(round(time.time()-t,2), epoch+1, tr_loss, tr_acc, val_loss, val_acc, self.scheduler.get_last_lr()[0]))
            #
            self.writer.log_tr(epoch+1, tr_loss, tr_acc)
            self.writer.log_val(epoch+1, val_loss, val_acc)
            # saving current state_dict
            path = self.ckpt/'current.pt'
            self.net.cpu()
            torch.save({
                'model': self.net.state_dict(),
                'optimizer': self.optimizer.state_dict(),
                'epoch': epoch,
                #'scheduler': self.scheduler.state_dict(),
                'best_loss': self.best_loss,
                'prev_loss': self.prev_loss,
                'val_loss': val_loss,
                }, path)
            self.net.to(self.args.device)
            #
            if val_loss < self.best_loss:
                path = self.ckpt/"best.pt"
                print('loss improved from {:.5f} to {:.5f}, saving model to {}'.format(self.prev_loss, val_loss, path))
                self.best_loss = val_loss
                self.net.cpu()
                torch.save({
                    'model': self.net.state_dict(),
                    'optimizer': self.optimizer.state_dict(),
                    'epoch': epoch,
                    #'scheduler': self.scheduler.state_dict(),
                    'best_loss': self.best_loss,
                    'prev_loss': self.prev_loss,
                    }, path)
                self.net.to(self.args.device)
            if val_loss >= self.prev_loss:
                trigger_times += 1
            else:
                trigger_times = 0
            if trigger_times >= self.args.patience:
                print("Early stopping at epoch: {}".format(epoch+1))
                break
            self.prev_loss = val_loss
        print("{} End training".format(time.ctime()))
        #
    def eval_metrics(self):
        return None

    def run_one_epoch(self, epoch, is_training=True):
        loader = self.tr_loader if is_training else self.cv_loader
        self.net.train() if is_training else self.net.eval()
        total_loss = 0
        total_acc = 0
        cnt = 0

        for idx, batch in enumerate(loader):
            #
            _, feats, target, feats_lengths, label_lengths = batch
            #
            feats = feats.to(self.args.device)
            target = target.to(self.args.device)
            feats_lengths = feats_lengths.to(self.args.device)
            label_lengths = label_lengths.to(self.args.device)
            num_utts = feats_lengths.size(0)

            logits = self.net(feats)
            loss = self.criterion(logits, target)
            #
            pred = logits.max(1, keepdim=True)[1]
            correct = pred.eq(target.long().view_as(pred)).sum()
            acc = correct.item() / logits.size(0)

            total_loss += loss.item()
            total_acc += acc
            cnt += 1
            if is_training:
                self.optimizer.zero_grad()
                loss.backward()
                self.optimizer.step()
                
            if self.args.verbose:
                print("{} Epoch: {} Ite: {} loss: {:.5f} acc: {:.5f}".format(time.ctime(), epoch, idx, loss.item(), acc))
            if self.dry_run and idx == self.ites_dry_run-1:
                print("Only trained {} iterations for dry-run".format(self.ites_dry_run))
                break
        gc.collect()
        torch.cuda.empty_cache()
        return total_loss/cnt, total_acc/cnt
