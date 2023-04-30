import numpy as np


def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoidV2(x):
    return 1 / (1 + np.exp(-x/2))

def sigmoidV3(x):
    return 2 / (1 + np.exp(-x))


def sigmoidPrime(x):
    return sigmoid(x) * (1 - sigmoid(x))


# for i in range(0, 20):
#     print(sigmoidV2(i))

print(sigmoidV2(2))

