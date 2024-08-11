# -*- coding: utf-8 -*-
"""
Created on Tue Dec 21 13:30:01 2021

@author: 12434
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import os

from myplotutils import mycontourf

plt.rcParams["font.sans-serif"] = ["SimHei"]  # 用来正常显示中文标签
plt.rcParams["axes.unicode_minus"] = False  # 用来正常显示负号


# pip install matplotlib
# use pip to install scipy
# pip install scikit-python

rootdir = "demo_data"

txtpathes = []
for (dirpath, dirnames, filenames) in os.walk(rootdir):
    for filename in filenames:

        txtpathes.append(os.path.join(dirpath, filename))

a = [str(i) for i in range(45)]
a[0] = "time"
a[15] = "N"
a[17] = "E"
a[29:32] = ["bx1", "by1", "bz1"]
a[32:35] = ["bx2", "by2", "bz2"]
a[35:38] = ["bx3", "by3", "bz3"]
a[38:41] = ["bx4", "by4", "bz4"]


def press(event):
    global i
    # i=0
    fig.clf()
    print("press", event.key)
    if event.key == "up":
        i = (i - 1) % n
    if event.key == "down":
        i = (i + 1) % n
    print(i)

    try:
        df1 = pd.DataFrame(columns=a)
        path = txtpathes[i]
        df = pd.read_csv(path, sep=",", header=None, names=a, error_bad_lines=False)

        # 去除有问题的行
        df1 = df
        df1 = df1[~df1["N"].isin([0])]

        # 将经纬度转化为坐标
        df1["E"] = (
            np.floor(df1.loc[:, "E"].values / 100)
            + (df1.loc[:, "E"].values - np.floor(df1.loc[:, "E"].values / 100) * 100)
            / 60
        )
        df1["N"] = (
            np.floor(df1.loc[:, "N"].values / 100)
            + (df1.loc[:, "N"].values - np.floor(df1.loc[:, "N"].values / 100) * 100)
            / 60
        )
        raw_x = (df1.loc[:, "E"].values) * np.cos(30.5 / 180 * np.pi) * 111319.54315
        raw_y = df1.loc[:, "N"].values * 110946.65356
        raw_x = raw_x - (max(raw_x) + min(raw_x)) / 2
        raw_y = raw_y - (max(raw_y) + min(raw_y)) / 2
        df1["x"] = raw_x
        df1["y"] = raw_y

        # 提取数据,计算磁场的幅值
        B1 = np.sqrt(df1["bx1"] ** 2 + df1["by1"] ** 2 + df1["bz1"] ** 2)
        B2 = np.sqrt(df1["bx2"] ** 2 + df1["by2"] ** 2 + df1["bz2"] ** 2)
        B3 = np.sqrt(df1["bx3"] ** 2 + df1["by3"] ** 2 + df1["bz3"] ** 2)
        B4 = np.sqrt(df1["bx4"] ** 2 + df1["by4"] ** 2 + df1["bz4"] ** 2)

        data = (B1 + B2 + B3) / 3 - B4

        # data = np.sqrt(
        #     (
        #         (B1 - B2) ** 2
        #         + (B1 - B3) ** 2
        #         + (B1 - B4) ** 2
        #         + (B2 - B3) ** 2
        #         + (B2 - B4) ** 2
        #         + (B3 - B4) ** 2
        #     )
        # )

    except Exception as e:
        # 文字
        plt.subplot(3, 1, 3)
        s1 = "fail!"
        plt.text(0, 0.6, s1, fontsize=25)
        s2 = "data id: " + str(i)
        plt.text(0, 0.4, s2, fontsize=25)
        s3 = "data path: " + txtpathes[i]
        plt.text(0, 0.2, s3, fontsize=12)
        s4 = str(e)
        plt.text(0, 0, s4, fontsize=12)
        plt.axis("off")
        fig.canvas.draw_idle()
        return

    # 绘图
    plt.subplots_adjust(wspace=0.5, hspace=0.5)
    # 散点图
    plt.subplot(3, 3, 1)
    plt.scatter(df1["x"], df1["y"], c=data, s=5)
    plt.colorbar()
    plt.axis("equal")
    plt.title("scatter")



    # 插值图
    plt.subplot(3, 3, 4)
    mycontourf(df1["x"], df1["y"], data)
    plt.title("delta B")

    plt.subplot(3, 3, 2)
    mycontourf(df1["x"], df1["y"], B1)
    plt.title("B1")

    plt.subplot(3, 3, 3)
    mycontourf(df1["x"], df1["y"], B2)
    plt.title("B2")

    plt.subplot(3, 3, 5)
    mycontourf(df1["x"], df1["y"], B3)
    plt.title("B3")

    plt.subplot(3, 3, 6)
    mycontourf(df1["x"], df1["y"], B4)
    plt.title("B4")

    # 文字
    plt.subplot(3, 1, 3)
    s1 = "succeed!"
    plt.text(0, 0.6, s1, fontsize=25)
    s2 = "data id: " + str(i)
    plt.text(0, 0.3, s2, fontsize=25)
    s3 = "data path: " + txtpathes[i]
    plt.text(0, 0, s3, fontsize=12)
    plt.axis("off")

    # 重新绘制
    fig.canvas.draw_idle()


i = 0
n = len(txtpathes)
fig = plt.figure(1)
fig.canvas.mpl_connect("key_press_event", press)
fig.clf()
s1 = "press any key to start"
s2 = "press down to next data "
s3 = "press up to previous data"
plt.text(0, 0.6, s1, fontsize=25)
plt.text(0, 0.5, s2, fontsize=25)
plt.text(0, 0.4, s3, fontsize=25)
plt.axis("off")
fig.canvas.draw_idle()
plt.show()
