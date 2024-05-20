import os, sys
import torch
import torch.nn as nn
import torch.nn.functional as F
from tensorboardX import SummaryWriter

class LossWriter(SummaryWriter):
    def __init__(self, logdir):
        super(LossWriter, self).__init__(logdir)
    def log_val(self, epoch, loss, acc):
        self.add_scalar('val_loss', loss, epoch)
        self.add_scalar('val_acc', acc, epoch)

    def log_tr(self, epoch, loss, acc):
        self.add_scalar('loss', loss, epoch)
        self.add_scalar('acc', acc, epoch)
