"""
# File       : p1.py
# Time       ：2023/5/1 13:12
# Author     ：Peng Cheng
# Description：
"""

import numpy as np

def compute_output(x):
    z1_prime = -x[0] - x[1]
    z2_prime = x[0] + x[1]
    z1 = max(0, z1_prime)
    z2 = max(0, z2_prime)
    y = z1 + z2
    y_0 = abs(x[0] + 1.1 * x[1])
    delta = (y - y_0) ** 2
    return y, delta


import numpy as np


def compute_all(x,W12,W3):
    z_primes = np.dot(W12, x)
    z = np.maximum(z_primes, 0)
    y = np.dot(W3, z)
    y_0 = abs(x[0] + 1.1 * x[1])
    delta = (y - y_0) ** 2

    dW3 = 2 * z * (y - y_0)
    dW12 = np.ones_like(W12)
    dW12 = ((dW12 * x * 2 * (y - y_0)).T * W3 * (z_primes > 0)).T

    return dW3,dW12


def compute_all_with_bn(x_batch,W12,W3):
    # x_batch包含一系列x，分别计算z
    z_primes = []
    for x in x_batch:
        z_primes.append(np.dot(W12, x))
    # 归一化
    z_primes = np.array(z_primes)
    z_primes_mean = np.mean(z_primes, axis=0)
    z_primes_std = np.std(z_primes, axis=0)
    z_primes = (z_primes - z_primes_mean) / z_primes_std

    dW3_ = np.zeros_like(W3).astype(float)
    dW12_ = np.zeros_like(W12).astype(float)
    for z_prime in z_primes:
        z = np.maximum(z_prime, 0)
        y = np.dot(W3, z)
        y_0 = abs(x[0] + 1.1 * x[1])
        delta = (y - y_0) ** 2

        dW3 = 2 * z * (y - y_0)
        dW12 = np.ones_like(W12)
        dW12 = ((dW12 * x * 2 * (y - y_0)).T * W3 * (z_prime > 0)).T
        p1 = len(x_batch)*(z_prime > 0)*W3
        p2 = (z_prime > 0)*W3 + np.flip((z_prime > 0)*W3)
        p3 = z_prime*((z_prime > 0)*W3*z_prime + np.flip((z_prime>0)*W3*z_prime))
        dW12 = ((dW12 * x * 2 * (y - y_0)).T * W3*(p1-p2-p3)).T/(len(x_batch)*z_primes_std)
        dW3_ += dW3
        dW12_ += dW12

    dW3 = dW3_ / len(x_batch)
    dW12 = dW12_ / len(x_batch)

    return dW3,dW12


def compute_loss(x,W12,W3):
    z_primes = np.dot(W12, x)
    z = np.maximum(z_primes, 0)
    y = np.dot(W3, z)
    y_0 = abs(x[0] + 1.1 * x[1])
    delta = (y - y_0) ** 2

    return delta


def compute_bn_loss(x,W12,W3,mean,std):
    z_primes = np.dot(W12, x)
    z_primes = (z_primes - mean) / std
    z = np.maximum(z_primes, 0)
    y = np.dot(W3, z)
    y_0 = abs(x[0] + 1.1 * x[1])
    delta = (y - y_0) ** 2

    return delta


def bp_once(w12,w3,lr=0.01):
    loss = 0
    for i in [1, 0, -1]:
        for j in [1, 0, -1]:
            loss += compute_loss(np.array([i, j]), w12, w3)
    loss = loss / 9
    print(loss)

    dw3 = np.zeros_like(w3).astype(float)
    dw12 = np.zeros_like(w12).astype(float)
    for i in [1, 0, -1]:
        for j in [1, 0, -1]:
            x = np.array([i, j])
            dw3_, dw12_ = compute_all(x, w12, w3)
            dw3 += dw3_
            dw12 += dw12_
    dw12 = dw12 / 9
    dw3 = dw3 / 9

    w3 = w3 - lr * dw3
    w12 = w12 - lr * dw12

    loss = 0
    for i in [1, 0, -1]:
        for j in [1, 0, -1]:
            loss += compute_loss(np.array([i, j]), w12, w3)
    loss = loss/9
    print(loss)


def bp_epochs(w12,w3,epoch = 10000,lr=0.01):
    dw3 = np.zeros_like(w3).astype(float)
    dw12 = np.zeros_like(w12).astype(float)

    for epoch in range(epoch):
        dw3 = np.zeros_like(w3).astype(float)
        dw12 = np.zeros_like(w12).astype(float)
        for i in [1, 0, -1]:
            for j in [1, 0, -1]:
                x = np.array([i, j])
                dw3_, dw12_ = compute_all(x, w12, w3)
                dw3 += dw3_
                dw12 += dw12_
        dw12 = dw12 / 9
        dw3 = dw3 / 9
        # print(dw12)
        # print(dw3)

        w3 = w3 - lr * dw3
        #print(w3)
        w12 = w12 - lr * dw12
        #print(w12)

    print(w12)
    print(w3)

    loss = 0
    for i in [1, 0, -1]:
        for j in [1, 0, -1]:
            loss += compute_loss(np.array([i, j]), w12, w3)
            #print(compute_loss(np.array([i, j]), w12, w3))
    loss = loss / 9
    print(loss)


def bp_with_bn(w12,w3,epoch = 10000,lr=0.01):
    x_list = []
    for i in [1, 0, -1]:
        for j in [1, 0, -1]:
            x_list.append(np.array([i, j]))
    x_batch = np.array(x_list)
    mean = np.mean(x_batch,axis=0)
    std = np.std(x_batch,axis=0)
    for i in range(epoch):
        dW3,dW12= compute_all_with_bn(x_batch,w12,w3)
        w3 = w3 - lr * dW3
        # print(w3)
        w12 = w12 - lr * dW12

    print(w12)
    print(w3)

    loss = 0
    for i in [1, 0, -1]:
        for j in [1, 0, -1]:
            loss += compute_bn_loss(np.array([i, j]), w12, w3,mean,std)
            print(compute_bn_loss(np.array([i, j]), w12, w3,mean,std))





if __name__ == '__main__':

    w12 = np.array([[-1, -1], [1, 1]])
    w3 = np.array([1, 1])
    bp_once(w12,w3)
    bp_epochs(w12,w3)

    w12 = np.array([[-100, -100], [100, 100]])
    w3 = np.array([0.01, 0.01])
    bp_once(w12,w3)
    bp_epochs(w12,w3,epoch=100,lr=0.00005)
    bp_with_bn(w12,w3)





