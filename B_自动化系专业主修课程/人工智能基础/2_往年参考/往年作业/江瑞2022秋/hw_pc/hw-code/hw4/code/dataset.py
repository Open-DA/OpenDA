"""
# File       : dataset.py
# Time       ：2022/11/23 16:51
# Author     ：Peng Cheng
# Description：
"""

from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn import linear_model
import numpy as np
from torch.utils.data import DataLoader, Dataset, random_split
import torch

def load_data():
    # 加载数据
    iris_data = load_iris()
    X, y = iris_data.data, iris_data.target
    # 划分数据集
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
    print("原始图片共有%d张，训练集中包含%d张，测试集中包含%d张。" % (len(X), len(X_train), len(X_test)))

    return X_train, y_train, X_test, y_test

# Set your dataset
class Flower(Dataset):
    def __init__(self, x, y):
        self.feature = x
        self.label = y

    def __getitem__(self, index):
        return self.feature[index], self.label[index]

    def __len__(self):
        return len(self.feature)

def get_Folwer_dataloader(config,x,y):
    dataset = Flower(x,y)
    if config.train:
        train_size = int(len(x) * config.data.split)
        valid_size = len(x) - train_size
        train_dataset, valid_dataset = torch.utils.data.random_split(dataset, [train_size, valid_size])
        train_dataloader = DataLoader(train_dataset, batch_size=config.train_batch_size, shuffle = True, num_workers=8,drop_last=False)
        valid_dataloader = DataLoader(valid_dataset, batch_size=config.valid_batch_size, shuffle = True, num_workers=8,drop_last=False)
        return train_dataloader, valid_dataloader
    else:
        test_dataloader = DataLoader(dataset, batch_size=config.test_batch_size, shuffle=True, num_workers=8)
        return test_dataloader