"""
# File       : model.py
# Time       ：2022/11/23 16:06
# Author     ：Peng Cheng
# Description：
"""
import torch
import torch.nn as nn
import torch.nn.functional as F



class SoftmaxModel(nn.Module):
    def __init__(self):
        super(SoftmaxModel, self).__init__()
        self.layers = nn.Sequential(
            nn.Linear(4, 3),
            # nn.Softmax() cross_entrophy included
        )

    def forward(self, x):
        x = self.layers(x)
        return x


# Set your model
class MLPModel(nn.Module):
    def __init__(self):
        super(MLPModel, self).__init__()
        self.layers = nn.Sequential(
            nn.Linear(4, 10),
            nn.ReLU(),
            nn.Linear(10, 3),
            # nn.Softmax() cross_entrophy included
        )

    def forward(self, x):
        x = self.layers(x)
        return x