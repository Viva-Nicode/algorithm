import tensorflow as tf
import numpy as np

layers = [
    tf.keras.layers.Flatten(input_shape=(28, 28)),
    tf.keras.layers.Dense(256, activation=tf.nn.relu),
    tf.keras.layers.Dense(128, activation=tf.nn.relu),
    tf.keras.layers.Dense(10, activation=tf.nn.softmax),
]

myMLP = tf.keras.Sequential(layers)
myMLP.compile(optimizer="Adam", loss="CategoricalCrossentropy", metrics=["accuracy"])
(X_train, y_train), (X_test, y_test) = tf.keras.datasets.mnist.load_data()

X_train_std, X_test_std = X_train / 255.0, X_test / 255.0
X_train_std = X_train_std.astype("float32")

y_train_onehot = tf.keras.utils.to_categorical(y_train, 10)
y_test_onehot = tf.keras.utils.to_categorical(y_test, 10)

myMLP.fit(X_train_std, y_train_onehot, epochs=40, batch_size=200)






