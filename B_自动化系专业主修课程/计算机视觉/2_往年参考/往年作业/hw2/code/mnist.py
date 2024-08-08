"""
# File       : mnist.py
# Time       ：2023/5/2 13:56
# Author     ：Peng Cheng
# Description：
"""

import torch
import torch.nn as nn
import numpy as np
import pandas as pd
import os
import csv
import math
from torch.utils.data import DataLoader, Dataset, random_split
import matplotlib.pyplot as plt
import random
import torchvision
from tqdm import tqdm
import torch.nn.functional as F
import wandb

# Set hyperparameter
# device = 'cuda' if torch.cuda.is_available() else 'cpu'
# config = {
#     'seed': 42,  # Your seed number, you can pick your lucky number. :)
#     'select_all': True,  # Whether to use all features.
#     'valid_ratio': 0.2,  # validation_size = train_size * valid_ratio
#     'n_epochs': 10,  # Number of epochs.
#     'batch_size': 64,
#     'learning_rate': 0.01,
#     'momentum': 0.5,
#     'early_stop': 400,  # If model has not improved for this many consecutive epochs, stop training.
#     'save_path': './models/model.ckpt'  # Your model will be saved here.
# }

sweep_config = {
    'method': 'random'
    }

parameters_dict = {
    'optimizer': {
        'values': ['adam', 'sgd']
        },
    'learning_rate': {
        # a flat distribution between 0 and 0.1
        'distribution': 'uniform',
        'min': 0,
        'max': 0.05
      },
    'batch_size': {
        # integers between 32 and 256
        # with evenly-distributed logarithms
        'distribution': 'q_log_uniform',
        'q': 1,
        'min': math.log(32),
        'max': math.log(256),
      },
    'n_epochs': {
        'value': 10
    },
    'valid_ratio': {
        'value': 0.2
    },
    'stride': {
        'values': [1,2]
    },
    'kernel_size': {
        'values': [3,5]
    }
    }

sweep_config['parameters'] = parameters_dict

sweep_id = wandb.sweep(sweep_config, project="mnist")


def same_seed(seed):
    '''Fixes random number generator seeds for reproducibility.'''
    torch.backends.cudnn.deterministic = True
    torch.backends.cudnn.benchmark = False
    np.random.seed(seed)
    torch.manual_seed(seed)
    if torch.cuda.is_available():
        torch.cuda.manual_seed_all(seed)


# Set your model
class mymodel(nn.Module):
    def __init__(self,stride=1,ker_size=5):
        super(mymodel, self).__init__()
        linear_size1 = ((28 - ker_size + 1)//stride) //2
        linear_size2 = (linear_size1 - ker_size + 1)//stride
        linear = int(linear_size2*linear_size2*20)
        # print(linear)
        self.layers = nn.Sequential(
            nn.Conv2d(1, 10,stride=stride, kernel_size=(ker_size, ker_size)),
            nn.MaxPool2d(2),
            nn.Conv2d(10, 20,stride=stride, kernel_size=(ker_size, ker_size)),
            #nn.Dropout(),
            nn.BatchNorm2d(20),
            # nn.MaxPool2d(2),
            nn.ReLU(),
            nn.Flatten(),
            nn.Linear(linear, 50),
            nn.ReLU(),
            nn.Linear(50, 10),
            nn.Softmax()
        )

    def forward(self, x):
        x = self.layers(x)
        x = x.squeeze(1)  # (B, 1) -> (B)
        return x

def trainer(config=None):
    device = 'cuda' if torch.cuda.is_available() else 'cpu'
    train_d = torchvision.datasets.MNIST('./data/', train=True, download=True,
                                         transform=torchvision.transforms.Compose([
                                             torchvision.transforms.ToTensor(),
                                             torchvision.transforms.Normalize(
                                                 (0.1307,), (0.3081,))
                                         ]))
    test_data = torchvision.datasets.MNIST('./data/', train=False, download=True,
                                           transform=torchvision.transforms.Compose([
                                               torchvision.transforms.ToTensor(),
                                               torchvision.transforms.Normalize(
                                                   (0.1307,), (0.3081,))
                                           ]))
    # Divide train_data into train and valid.
    train_data, val_data = torch.utils.data.random_split(train_d, [50000, 10000])

    with wandb.init(config=None):
        config = wandb.config
        # print(config)
        train_loader = DataLoader(train_data, batch_size=config.batch_size, shuffle=True, pin_memory=True)
        valid_loader = DataLoader(val_data, batch_size=config.batch_size, shuffle=True, pin_memory=True)
        test_loader = DataLoader(test_data, batch_size=config.batch_size, shuffle=True, pin_memory=True)
        # If called by wandb.agent, as below,
        # this config will be set by Sweep Controller
        model = mymodel(config.stride,config.kernel_size)
        model.to(device)
        train(train_loader, valid_loader, model, config, device)
        test(test_loader, model, device)

# Set your trainer.
def train(train_loader, valid_loader, model, config, device):
    criterion = nn.CrossEntropyLoss()
    if config.optimizer == 'adam':
        optimizer = torch.optim.Adam(model.parameters(), lr=config.learning_rate)
    elif config.optimizer == 'sgd':
        optimizer = torch.optim.SGD(model.parameters(), lr=config.learning_rate, momentum=0.5)

    if not os.path.isdir('./models'):
        os.mkdir('./models')  # Create directory of saving models.

    n_epochs, best_loss, step, early_stop_count = config.n_epochs, math.inf, 0, 0

    for epoch in range(n_epochs):
        # =========================train============================
        model.train()  # Set your model to train mode.
        loss_record = []

        # tqdm is a package to visualize your training progress.
        train_pbar = tqdm(train_loader, position=0, leave=True)

        for x, y in train_pbar:
            optimizer.zero_grad()  # Set gradient to zero.
            x, y = x.to(torch.float32).to(device), y.to(torch.float32).to(device)  # Move your data to device.
            pred = model(x)
            loss = criterion(pred, y.long())  # the second parameter must be long
            loss.backward()  # Compute gradient(backpropagation).
            optimizer.step()  # Update parameters.
            step += 1
            loss_record.append(loss.detach().item())

            # Display current epoch number and loss on tqdm progress bar.
            train_pbar.set_description(f'Epoch [{epoch + 1}/{n_epochs}]')
            train_pbar.set_postfix({'loss': loss.detach().item()})

        mean_train_loss = sum(loss_record) / len(loss_record)
        #writer.add_scalar('Loss/train', mean_train_loss, step)

        # =========================valid============================
        model.eval()  # Set your model to evaluation mode.
        loss_record = []
        for x, y in valid_loader:
            x, y = x.to(device), y.to(device)
            with torch.no_grad():
                pred = model(x)
                loss = criterion(pred, y.long())

            loss_record.append(loss.item())

        mean_valid_loss = sum(loss_record) / len(loss_record)
        print(f'Epoch [{epoch + 1}/{n_epochs}]: Train loss: {mean_train_loss:.4f}, Valid loss: {mean_valid_loss:.4f}')
        #writer.add_scalar('Loss/valid', mean_valid_loss, step)
        wandb.log({"loss": mean_valid_loss, "epoch": epoch})

        # # ==================early stopping======================
        # if mean_valid_loss < best_loss:
        #     best_loss = mean_valid_loss
        #     torch.save(model.state_dict(), config['save_path'])  # Save your best model
        #     print('Saving model with loss {:.3f}...'.format(best_loss))
        #     early_stop_count = 0
        # else:
        #     early_stop_count += 1
        #
        # if early_stop_count >= config['early_stop']:
        #     print('\nModel is not improving, so we halt the training session.')
        #     return


def test(test_loader, model, device):
    model.eval()  # Set your model to evaluation mode.
    correct = 0
    test_loss = 0
    test_losses = []
    for x, y in tqdm(test_loader):
        x, y = x.to(device), y.to(device)
        with torch.no_grad():
            out = model(x)
            test_loss += F.cross_entropy(out, y.long())
            pred = out.data.max(1, keepdim=True)[1]
            correct += pred.eq(y.data.view_as(pred)).sum()
    test_loss /= len(test_loader.dataset)
    test_losses.append(test_loss)
    print('\nTest set: Avg. loss: {:.4f}, Accuracy: {}/{} ({:.0f}%)\n'.format(
        test_loss, correct, len(test_loader.dataset),
        100. * correct / len(test_loader.dataset)))


if __name__ == '__main__':
    # Set seed for reproducibility
    same_seed(42)
    # train_d = torchvision.datasets.MNIST('./data/', train=True, download=True,
    #                                      transform=torchvision.transforms.Compose([
    #                                          torchvision.transforms.ToTensor(),
    #                                          torchvision.transforms.Normalize(
    #                                              (0.1307,), (0.3081,))
    #                                      ]))
    # test_data = torchvision.datasets.MNIST('./data/', train=False, download=True,
    #                                        transform=torchvision.transforms.Compose([
    #                                            torchvision.transforms.ToTensor(),
    #                                            torchvision.transforms.Normalize(
    #                                                (0.1307,), (0.3081,))
    #                                        ]))
    # # Divide train_data into train and valid.
    # train_data, val_data = torch.utils.data.random_split(train_d, [50000, 10000])
    #
    # train_loader = DataLoader(train_data, batch_size=config['batch_size'], shuffle=True, pin_memory=True)
    # valid_loader = DataLoader(val_data, batch_size=config['batch_size'], shuffle=True, pin_memory=True)
    # test_loader = DataLoader(test_data, batch_size=config['batch_size'], shuffle=True, pin_memory=True)

    # model = model().to(device)  # put your model and data on the same computation device.
    # train(train_loader, valid_loader, model, config, device)
    # test(test_loader, model, device)

    wandb.agent(sweep_id, trainer, count=20)