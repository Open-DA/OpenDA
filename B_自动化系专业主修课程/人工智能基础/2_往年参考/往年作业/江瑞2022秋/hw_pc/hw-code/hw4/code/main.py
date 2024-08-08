"""
# File       : main.py
# Time       ：2022/11/23 12:47
# Author     ：Peng Cheng
# Description：The main function to control config and call the training or testing process
"""

import argparse
import os
import yaml
from pprint import pprint
from easydict import EasyDict
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn import linear_model
import numpy as np
from trainer import train,test
from model import *
from dataset import *
import torch

def parse_args():
    parser = argparse.ArgumentParser(description='Pytorch implementation of Classification')
    parser.add_argument('--config', default='',help='config file path')
    # exclusive arguments
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument('--train', action='store_true',help='train mode')
    group.add_argument('--test', action='store_true',help='test mode')

    return parser.parse_args()


def same_seed(seed):
    '''Fixes random number generator seeds for reproducibility.'''
    torch.backends.cudnn.deterministic = True
    torch.backends.cudnn.benchmark = False
    np.random.seed(seed)
    torch.manual_seed(seed)
    if torch.cuda.is_available():
        torch.cuda.manual_seed_all(seed)


def load_data():
    # 加载数据
    iris_data = load_iris()
    x, y = iris_data.data, iris_data.target
    # 划分数据集
    x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=42)
    print("原始图片共有%d张，训练集中包含%d张，测试集中包含%d张。" % (len(x), len(x_train), len(x_test)))

    return x_train, y_train, x_test, y_test


def main():
    # parse arguments and load config
    args = parse_args()
    with open(args.config) as f:
        config = yaml.safe_load(f)
    for k, v in vars(args).items():
        config[k] = v
    config = EasyDict(config)
    Flower_classifier = SoftmaxModel()
    x_train, y_train, x_test, y_test = load_data()

    # choose train or test
    if config.train:
        data = (x_train,y_train)
        train(config,Flower_classifier,data)
    elif config.test:
        model_path = config.save_dir
        model_list = os.listdir(model_path)
        model_list.sort(key=lambda x: int(x[5:-3]))  ##文件名按数字排序
        data = (x_test, y_test)
        Flower_classifier.load_state_dict(torch.load(model_path+'/'+model_list[-1]))
        test(config,Flower_classifier,data)


if __name__ == '__main__':
    main()
