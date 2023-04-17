from sklearn.preprocessing import StandardScaler
import tensorflow as tf
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm


# 레이어 하나 동작하는 함수 순서대로 feature, weight, bias, activation function 을 입력받음
def neuron_layer(X, W, b, activation=None):
    z = tf.matmul(X, W) + b  # 내적
    if activation is None:
        return z
    else:
        return activation(z)


# 여러 레이어를 거처가는 순전파 함수
def Deep_MLP(X_flatten, W, b):
    hidden1 = neuron_layer(X_flatten, W[0], b[0], activation=tf.nn.relu)
    hidden2 = neuron_layer(hidden1, W[1], b[1], activation=tf.nn.relu)
    logits = neuron_layer(hidden2, W[2], b[2])
    return tf.nn.softmax(logits)


(X_train, y_train), (X_test, y_test) = tf.keras.datasets.mnist.load_data()
nTrain = X_train.shape[0]

X_train_std, X_test_std = X_train / 255.0, X_test / 255.0
X_train_std = X_train_std.astype("float32")

X_train[0][0]

y_train_onehot = tf.keras.utils.to_categorical(y_train, 10)
y_test_onehot = tf.keras.utils.to_categorical(y_test, 10)

n_inputs = np.array([28 * 28, 256, 128])
n_nodes = np.array([256, 128, 10])
n_layer = 3
W, b = {}, {}

for layer in range(n_layer):
    stddev = 2 / np.sqrt(n_inputs[layer] + n_nodes[layer])
    W_init = tf.random.truncated_normal((n_inputs[layer], n_nodes[layer]), stddev=stddev)
    W[layer] = tf.Variable(W_init)
    b[layer] = tf.Variable(tf.zeros([n_nodes[layer]]))

n_epoch = 40
batchSize = 200
nBatch = int(nTrain / batchSize)
opt = tf.keras.optimizers.Adam(learning_rate=0.01)

for epoch in range(n_epoch):
    idxShuffle = np.random.permutation(X_train.shape[0])
    for idxSet in range(nBatch):
        X_batch = X_train_std[idxShuffle[idxSet * batchSize : (idxSet + 1) * batchSize], :]
        X_batch_tensor = tf.convert_to_tensor(X_batch.reshape(-1, 28 * 28))
        Y_batch = y_train_onehot[idxShuffle[idxSet * batchSize : (idxSet + 1) * batchSize], :]

        with tf.GradientTape() as tape:
            y_pred = Deep_MLP(X_batch_tensor, W, b)
            loss = tf.reduce_mean(tf.keras.losses.categorical_crossentropy(Y_batch, y_pred))
        gradients = tape.gradient(loss, [W[2], W[1], W[0], b[2], b[1], b[0]])
        opt.apply_gradients(zip(gradients, [W[2], W[1], W[0], b[2], b[1], b[0]]))
    if epoch % 5 == 0:
        correct = tf.equal(tf.argmax(y_pred, 1), tf.argmax(Y_batch, 1))
        accuracy = tf.reduce_mean(tf.cast(correct, tf.float32)).numpy()
        print(accuracy)
