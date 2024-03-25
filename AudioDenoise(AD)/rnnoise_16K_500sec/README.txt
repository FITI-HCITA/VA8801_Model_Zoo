參照 https://github.com/ARM-software/ML-zoo/blob/master/models/noise_suppression/RNNoise/tflite_int8/recreate_model/data.py
注意Tensor size 改變. 從h5 file load入 preprocess data

def get_tf_dataset_from_h5(h5_path, window_size, batch_size):
    """Returns tf Datasets for training RNNoise.

    This function expects h5 files produced by generate_h5_files() or from original RNNoise repository.
    """
    with h5py.File(h5_path, 'r') as hf:
        all_data = hf['data'][:]
    print("get h5 file from {0}".format(h5_path))
    nb_sequences = len(all_data) // window_size
    logging.info(f"Number of training sequences: {nb_sequences}")
    print("Number of training sequences:{0}".format(nb_sequences))
    # We need data in the order (batch, sequence, features)
    x = all_data[:nb_sequences*window_size, :38]
    x = np.reshape(x, (nb_sequences, window_size, 38))

    y = all_data[:nb_sequences*window_size, 38:56]
    y = np.reshape(y, (nb_sequences, window_size, 18))

    vad_y = all_data[:nb_sequences*window_size, 74:75]
    vad_y = np.reshape(vad_y, (nb_sequences, window_size, 1))

    with tf.device('/CPU:0'):
        tf_dataset = tf.data.Dataset.from_tensor_slices((x, (y, vad_y)))
        tf_dataset = tf_dataset.batch(batch_size, drop_remainder=True).prefetch(tf.data.AUTOTUNE)

    return tf_dataset