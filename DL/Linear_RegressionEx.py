from sklearn.preprocessing import StandardScaler
import tensorflow as tf
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm
from google.colab import drive

drive.mount("/content/drive")

dfLoad = pd.read_csv("/content/drive/MyDrive/student_info.csv", index_col="no")

# csv에서 로드한 데이터의 각각의 열을 매트릭스화
HeightRaw = np.array(dfLoad["height_cm"]).reshape(-1, 1)
WeightRaw = np.array(dfLoad["weight_kg"]).reshape(-1, 1)

scaler = StandardScaler()

# feature를 표준편차가 1인 정규분포로 스케일링
scaler.fit(HeightRaw)
Height_std = scaler.transform(HeightRaw)

NData = np.shape(HeightRaw)[0]  # 학습 데이터 총 갯수
X_np = np.c_[np.ones(NData), Height_std]  # 1패딩

Y_np = WeightRaw

# 트레이닝 셋을 상수화
X = tf.constant(X_np, dtype=tf.float32)
y = tf.constant(Y_np, dtype=tf.float32)

# 세타값 두개를 -1에서 1사이 랜덤 수로 초기화
theta = tf.Variable(tf.random.uniform([2, 1], -1, 1), dtype=tf.float32)
learning_rate = 0.1  # 경사하강법 사용할 것이므로 학습률
epoch = 100  # 전체 학습 데이터 반복 횟수

for i in np.arange(epoch):
    with tf.GradientTape() as g:  # 비용함수를 테이프에 기록
        y_predict = tf.matmul(X, theta)  # 전체 train set matrix를 theta와 내적한다. 결과는 y predict 벡터다.
        error = y - y_predict  # 이를 y predict 벡터에 빼서 오차 벡터를 구한다.
        mse = tf.reduce_mean(tf.square(error))  # 오차들의 제곱의 평균을 구하고 이 값이 최소화해야 하는값이다.
    gradients = g.gradient(mse, [theta])  # theta에 대해서 미분해서 기울기 구함
    theta.assign(theta - learning_rate * gradients[0].numpy())  # 기울기에 따라 theta를 업데이트한다.

w1_std = theta.numpy()[1]
w0_std = theta.numpy()[0]

xPlt_std = np.linspace(-2, 2, 100)
f2, ax2 = plt.subplots()
ax2.plot(Height_std, WeightRaw, "r.")
ax2.plot(xPlt_std, w1_std * xPlt_std + w0_std, "b-")

w1 = w1_std / np.sqrt(scaler.var_)
w0 = w0_std - scaler.mean_ * w1_std / np.sqrt(scaler.var_)
xPltRaw = np.linspace(min(HeightRaw), max(HeightRaw), 100)
f3, ax3 = plt.subplots()
ax3.plot(HeightRaw, WeightRaw, "r.")
ax3.plot(xPltRaw, w1 * xPltRaw + w0, "b-")
