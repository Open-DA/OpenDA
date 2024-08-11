import random
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.metrics import *
from sklearn import linear_model
from numpy import random
import numpy as np
import math

def sample(X, y):
    """
    从给定数据中抽取山鸢尾（Setosa）和维吉尼亚鸢尾（Vriginica）的样本, 只保留花瓣长度（petal length） 特征
    """
    index_s = y==0
    index_v = y==2
    index = index_s + index_v
    return X[index][:, 2], y[index]
    

def load_data():
    # 加载数据
    iris_data = load_iris()
    X, y = iris_data.data, iris_data.target
    X, y = sample(X, y)
    # 划分数据集
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
    print("原始图片共有%d张，训练集中包含%d张，测试集中包含%d张。" % (len(X), len(X_train), len(X_test)))

    return X_train, y_train, X_test, y_test


def train(w, b, X, Y, alpha=0.1, epochs=50, batchsize=32):
    num_train = X.shape[0]
    iterations_per_epoch = max(num_train // batchsize +1, 1) # divide data by batchsize

    for epoch in range(epochs):
        num_train = X.shape[0]
        idx = np.array(range(num_train))
        random.shuffle(idx) # shuffle the index
        iterations = [idx[i*batchsize:min((i+1)*batchsize, num_train)].tolist() for i in range(iterations_per_epoch)] # index of each batch
        loss_record = []
        for iter in iterations:
            #print(iter)
            loss,grad = step(w,b,X,Y,iter) # step by each batch
            dw, db = grad # backward
            # gradient descent
            w -= alpha * dw
            b -= alpha * db

            loss_record.append(loss)

        # calculate loss and acc
        average_loss = sum(loss_record)/len(loss_record)
        z = w * X + b
        Y_pred = 1 / (1 + np.exp(-z))
        Y_pred[Y_pred > 0.5] = 1
        Y_pred[Y_pred <= 0.5] = 0
        train_acc = np.mean(Y_pred == Y)
        print(f'Epoch{epoch + 1}, Average Loss:{average_loss}, Train Acc:{train_acc}')

    return w, b


def totest(w, b, X, Y):
    """
    YOUR CODE HERE
    """
    z = w * X + b
    Y_pred = 1 / (1 + np.exp(-z))
    Y_pred[Y_pred > 0.5] = 1
    Y_pred[Y_pred <= 0.5] = 0
    model_evaluate(Y, Y_pred)
    return


def step(w, b, X, Y, idx_batch):
    """
    The function is used to make a single gradient update step
    """
    # Make a minibatch of training data
    X_batch = X[idx_batch]
    Y_batch = Y[idx_batch]
    # Compute the loss and gradient
    z = w * X_batch + b
    h = 1 / (1 + np.exp(-z))
    # loss
    loss = - np.sum(Y_batch * np.log(h) + (1 - Y_batch) * np.log(1 - h)) / len(idx_batch)
    # grad
    dw = np.sum((h - Y_batch) * X_batch) / len(idx_batch)
    db = np.sum(h - Y_batch) / len(idx_batch)
    grad = (dw, db)
    return loss, grad


def model_evaluate(Y, Y_pred):
    # 输出各项评估指标

    TP = np.sum((Y_pred == 1) & (Y == 1))
    TN = np.sum((Y_pred == 0) & (Y == 0))
    FP = np.sum((Y_pred == 1) & (Y == 0))
    FN = np.sum((Y_pred == 0) & (Y == 1))

    Accuracy = (TP + TN) / (TP + TN + FP + FN)
    print("Accuracy: %.4f" % Accuracy)

    BER = 0.5 * (FP / (FP + TN) + FN / (FN + TP))
    print("BER: %.4f" % BER)

    MCC = (TP * TN - FP * FN) / math.sqrt((TP + FP) * (FP + TN)) / math.sqrt((TN + FN) * (FN + TP))
    print("MCC: %.4f" % MCC)

    Sensitivity = TP / (TP + FN)
    print("Sensitivity: %.4f" % Sensitivity)

    Specificity = TN / (TN + FP)
    print("Specificity: %.4f" % Specificity)

    Recall = TP / (TP + FN)
    print("Recall: %.4f" % Recall)

    Precision = TP / (TP + FP)
    print("Precision: %.4f" % Precision)

    F1 = 2 * Precision * Recall / (Precision + Recall)
    print("F1: %.4f" % F1)

    precision, recall, thresholds = precision_recall_curve(Y, Y_pred)
    auPRC = auc(recall, precision)
    print("auPRC: %.4f" % auPRC)

    fpr, tpr, thresholds = roc_curve(Y, Y_pred)
    auROC = auc(fpr, tpr)
    print("auROC: %.4f" % auROC)
    return

if __name__ == "__main__":
    # 加载数据
    x_train, y_train, x_test, y_test = load_data()
    y_train[y_train == 2] = 1
    y_test[y_test == 2] = 1

    # 随机初始化参数
    w = np.random.randn()
    b = np.random.randn()

    # 训练及测试
    # train
    w, b = train(w, b, x_train, y_train)
    # test
    print("My model:")
    totest(w, b, x_test, y_test)

    # sklearn
    clf = linear_model.LogisticRegression(random_state=0).fit(x_train.reshape(-1, 1), y_train)
    y_test_pred = clf.predict(x_test.reshape(-1, 1))
    print("sklearn model:")
    model_evaluate(y_test, y_test_pred)

    