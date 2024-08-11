"""
# File       : ode.py
# Time       ：2023/5/13 14:54
# Author     ：Peng Cheng
# Description：
"""
import numpy as np
from scipy.integrate import odeint
import matplotlib.pyplot as plt
from tqdm import tqdm


def step(current_t,current_v,delta_t=1e-10, total_t=4e-5, RON=100,ROFF=1e8, VC=10, T1=0, TF=5e-7, CP1=1.5e-10, CP2=1.5e-10, CF=5e-11, RF=2e5, cx=1e-12):
    alpha = CP1 * cx + CP2 * cx + CP1 * CP2
    # 当前开关电阻
    r1 = RON if (current_t // TF) % 2 == 0 else ROFF
    r2 = RON if ((current_t - T1) // TF) % 2 == 0 else ROFF
    r3 = ROFF if (current_t // TF) % 2 == 0 else RON
    r4 = ROFF if ((current_t - T1) // TF) % 2 == 0 else RON
    A = np.array(
        [[-(r2 + r4) * (CP2 + cx) / r2 / r4 / alpha, -(r1 + r3) * cx / r1 / r3 / alpha, 0],
         [-(r2 + r4) * cx / r2 / r4 / alpha, -(r1 + r3) * (CP1 + cx) / r1 / r3 / alpha, 0],
         [0, -1 / r3 / CF, -1 / RF / CF]]).reshape(3, 3)
    b = np.array([(CP2 + cx) / r2 / alpha * VC, cx / r2 / alpha * VC, 0]).reshape(3, 1)

    # 数值方法(4阶 Runge-Kutta methods)计算下一时刻电压值
    v1 = A.dot(current_v) + b
    v2 = A.dot(current_v + delta_t * v1 / 2) + b
    v3 = A.dot(current_v + delta_t * v2 / 2) + b
    v4 = A.dot(current_v + delta_t * v3) + b
    new_v = current_v + delta_t / 6 * (v1 + 2 * v2 + 2 * v3 + v4)
    new_t = current_t + delta_t

    return new_t, new_v


def plot(t, v):
    # 支持中文
    plt.rcParams['font.sans-serif'] = ['SimHei']
    plt.rcParams['axes.unicode_minus'] = False

    # set grid
    plt.grid(True)
    plt.plot(t, v[:, 0])
    plt.xlabel('时间（s）')
    plt.ylabel('Va（V）')
    plt.show()

    plt.grid(True)
    plt.plot(t, v[:, 1])
    plt.xlabel('时间（s）')
    plt.ylabel('Vb（V）')
    plt.show()

    plt.grid(True)
    plt.plot(t, v[:, 2])
    plt.xlabel('时间（s）')
    plt.ylabel('Vo（V）')
    plt.show()

def ode_solve():
    # 电路参数设置，与课件一致
    CX = 1e-12
    CP1 = 1.5e-10
    CP2 = 1.5e-10

    RF = 2e5
    CF = 5e-11
    TS = 1e-6
    TF = TS / 2
    T1 = 0

    RON = 100
    ROFF = 1e8
    VC = 10

    v = []  # 电压值记录
    v.append(np.array([0, 0, 0]).reshape(3, 1))
    t = [0]  # 时间记录
    alpha = CP1 * CX + CP2 * CX + CP1 * CP2

    delta_t = 1e-10
    total_t = 4e-5

    # 开始仿真
    for i in tqdm(range(int(total_t // delta_t))):
        current_t = t[-1]
        current_v = v[-1]
        new_t, new_v = step(current_t, current_v)
        t.append(new_t)
        v.append(new_v)

    # 画图
    plot(t, np.array(v))




if __name__ == '__main__':
    ode_solve()