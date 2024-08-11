"""
# File       : final_point.py
# Time       ：2023/4/4 15:46
# Author     ：Peng Cheng
# Description：
"""
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import os
from scipy.interpolate import griddata
from myplotutils import mycontourf

plt.rcParams["font.sans-serif"] = ["SimHei"]  # 用来正常显示中文标签
plt.rcParams["axes.unicode_minus"] = False  # 用来正常显示负号

# read data
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

df1 = pd.DataFrame(columns=a)
path = txtpathes[0]
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

xi = np.linspace(min(df1["x"]), max(df1["x"]), 50)
yi = np.linspace(min(df1["y"]), max(df1["y"]), 50)
X, Y = np.meshgrid(xi, yi)
Z = griddata((df1["x"], df1["y"]), data, (X, Y), method='linear')
#plt.figure()
plt.contourf(X,Y,Z)
plt.colorbar()
plt.axis("equal")

# 画出最大值和最小值连线
max_index = np.argmax(data)
min_index = np.argmin(data)
plt.plot([df1["x"][max_index], df1["x"][min_index]], [df1["y"][max_index], df1["y"][min_index]], "r-")
# 画出最大值和最小值点
plt.plot(df1["x"][max_index], df1["y"][max_index], "bo")
plt.plot(df1["x"][min_index], df1["y"][min_index], "bo")
# 取连线的中点标记，圆圈标记
plt.plot([(df1["x"][max_index] + df1["x"][min_index]) / 2], [(df1["y"][max_index] + df1["y"][min_index]) / 2], "ro")
# 打印中点坐标
print("中点坐标：", (df1["x"][max_index] + df1["x"][min_index]) / 2, (df1["y"][max_index] + df1["y"][min_index]) / 2)
plt.title("delta B")
plt.savefig("delta B2.png")
plt.show()