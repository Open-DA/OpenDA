"""
# File       : train.py
# Time       ：2022/11/23 12:39
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
from dataset import *
from sklearn.metrics import precision_score, recall_score, f1_score, confusion_matrix, classification_report


def train(config,model,data):
    criterion = nn.CrossEntropyLoss()
    optimizer = torch.optim.SGD(model.parameters(), lr=config.optimizer.lr, momentum=config.optimizer.momentum)

    if not os.path.isdir(config.save_dir):
        os.mkdir(config.save_dir)  # Create directory of saving models.
    n_epochs, best_loss, step, early_stop_count = config.epoch, math.inf, 0, 0

    x,y = data
    train_dataloader, valid_dataloader = get_Folwer_dataloader(config, x, y)
    model.to(torch.device(config.device))

    for epoch in range(n_epochs):
        # =========================train============================
        model.train()  # Set your model to train mode.
        loss_record = []

        # tqdm is a package to visualize your training progress.
        train_pbar = tqdm(train_dataloader, position=0, leave=True)

        for x, y in train_pbar:
            optimizer.zero_grad()  # Set gradient to zero.
            x, y = x.to(torch.float32).to(torch.device(config.device)), y.to(torch.float32).to(torch.device(config.device))  # Move your data to config.device.
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

        # =========================valid============================
        model.eval()  # Set your model to evaluation mode.
        loss_record = []
        for x, y in valid_dataloader:
            x, y = x.to(torch.float32).to(config.device), y.to(torch.float32).to(config.device)
            with torch.no_grad():
                pred = model(x)
                loss = criterion(pred, y.long())

            loss_record.append(loss.item())

        mean_valid_loss = sum(loss_record) / len(loss_record)
        print(f'Epoch [{epoch + 1}/{n_epochs}]: Train loss: {mean_train_loss:.4f}, Valid loss: {mean_valid_loss:.4f}')

        # ==================early stopping======================
        if mean_valid_loss < best_loss:
            best_loss = mean_valid_loss
            torch.save(model.state_dict(), config.save_dir+f'/epoch{epoch}.pt')  # Save your best model
            print('Saving model with loss {:.3f}...'.format(best_loss))
            early_stop_count = 0
        else:
            early_stop_count += 1

        if early_stop_count >= config.early_stop:
            print('\nModel is not improving, so we halt the training session.')
            return


def test(config, model, data):
    x, y = data
    test_dataloader = get_Folwer_dataloader(config, x, y)
    model.to(torch.device(config.device))
    model.eval()  # Set your model to evaluation mode.
    correct = 0
    test_loss = 0
    test_losses = []
    test_label = []
    test_pred = []
    for x, y in tqdm(test_dataloader):
        x, y = x.to(torch.float32).to(torch.device(config.device)), y.to(torch.float32).to(torch.device(config.device))
        with torch.no_grad():
            out = model(x)
            test_loss += F.cross_entropy(out, y.long())
            pred = out.data.max(1, keepdim=True)[1]
            test_label+=np.array(y.cpu()).astype(int).tolist()
            test_pred+=np.array(pred.reshape([-1]).cpu()).tolist()
            correct += pred.eq(y.data.view_as(pred)).sum()
    test_loss /= len(test_dataloader.dataset)
    test_losses.append(test_loss)
    print('Test set: Avg. loss: {:.4f}, Accuracy: {}/{} ({:.0f}%)\n'.format(
        test_loss, correct, len(test_dataloader.dataset),
        100. * correct / len(test_dataloader.dataset)))

    print('True Label:',test_label)
    print('Predict Label:',test_pred)

    # add more evaluation
    test_label = np.array(test_label)
    test_pred = np.array(test_pred)
    confusion = confusion_matrix(test_label, test_pred)
    report = classification_report(test_label, test_pred)
    Precision = precision_score(test_label, test_pred, labels=[0, 1, 2], average='macro')
    Recall = recall_score(test_label, test_pred, labels=[0, 1, 2], average='macro')
    F1 = f1_score(test_label, test_pred, labels=[0, 1, 2], average='macro')
    print("Precision_macro:  {}".format(Precision))
    print("Recall_macro:  {}".format(Recall))
    print("F1_macro:  {}".format(F1))
    print('Confusion Matrix :\n',confusion)
    print("Report:\n",report)



