import numpy as np
import matplotlib.pyplot as plt
from sympy import *
import math

METHOD = 'PR'
assert METHOD in ['1norm', '2norm', 'infnorm', 'FR', 'PR']

# 三种范数下的最速下降方向
def solve1():
    x, y = 0., 0.
    x_all, y_all, f_all = [], [], []
    num_iter = 0
    while True:
        num_iter += 1
        x_all.append(x)
        y_all.append(y)
        f_all.append(func(x, y))
        delta_x, delta_y = delta(x, y)
        delta_f = math.sqrt(delta_x ** 2 + delta_y ** 2)
        if delta_f < 1e-4:
            print(x, y, func(x, y))
            break

        if METHOD == '1norm':
            if (abs(delta_x) > abs(delta_y)):
                d = np.array([-np.sign(delta_x), 0])
            else:
                d = np.array([0, -np.sign(delta_y)])
        elif METHOD == '2norm':
            d = np.array([-delta_x, -delta_y]) / delta_f
        elif METHOD == 'infnorm':
            d = np.array([-np.sign(delta_x), -np.sign(delta_y)])

        t = Symbol('t')
        delta_xt, delta_yt = delta(x + t * d[0], y + t * d[1])
        result = solve([delta_xt * d[0] + delta_yt * d[1]], [t])
        if len(result) == 1:
            t = result[t]
        elif len(result) > 1:
            t = complex(result[0][0]).real
        x = float(x + t * d[0])
        y = float(y + t * d[1])

    print('Iter Number:', num_iter)
    plot(x_all, y_all, f_all)

# 两种共轭梯度法
def solve2():
    x, y = 0., 0.
    x_all, y_all, f_all = [], [], []
    num_iter = 0
    while True:
        num_iter += 1
        x_all.append(x)
        y_all.append(y)
        f_all.append(func(x, y))
        delta_x, delta_y = delta(x, y)
        delta_f = math.sqrt(delta_x ** 2 + delta_y ** 2)
        if delta_f < 1e-4:
            print(x, y, func(x, y))
            break

        if num_iter == 1:
            d = np.array([-delta_x, -delta_y])
        else:
            if METHOD == 'FR':        
                delta_oldx, delta_oldy = delta(old[0], old[1])
                alpha = (delta_x ** 2 + delta_y ** 2) / (delta_oldx ** 2 + delta_oldy ** 2)
            elif METHOD == 'PR':
                delta_oldx, delta_oldy = delta(old[0], old[1])
                alpha = np.array([delta_x, delta_y]).T @ (np.array([delta_x, delta_y]) - np.array([delta_oldx, delta_oldy])) / (delta_oldx ** 2 + delta_oldy ** 2)
            d = -np.array([delta_x, delta_y]) + alpha * d
        t = Symbol('t')
        delta_xt, delta_yt = delta(x + t * d[0], y + t * d[1])
        result = solve([delta_xt * d[0] + delta_yt * d[1]], [t])
        if len(result) == 1:
            t = result[t]
        elif len(result) > 1:
            t = complex(result[0][0]).real
        old = [x, y]
        x = float(x + t * d[0])
        y = float(y + t * d[1])

    print('Iter Number:', num_iter)
    plot(x_all, y_all, f_all)

# 作图
def plot(x_all=None, y_all=None, f_all=None):
    plt.figure(figsize=(12, 9))
    x, y = np.meshgrid(np.arange(-0.3, 1.5, 0.01), np.arange(-0.3, 1.5, 0.01))
    f = (1 - x) ** 2 + 2 * (x ** 2 - y) ** 2
    plt.style.use('ggplot')
    plt.clabel(plt.contour(x, y, f, [0.01, 0.02, 0.05, 0.1, 0.2, 0.5, 0.8, 1.0, 1.5], cmap='copper'))
    if x_all is not None:
        plt.plot(x_all, y_all, marker='.', color='crimson')
    plt.grid(True)
    plt.xlabel('x')
    plt.ylabel('y')
    plt.show()
    
    if f_all is not None:
        plt.figure(figsize=(12, 9))
        plt.plot(np.arange(0, len(f_all)), f_all, marker='.', color='crimson')
        plt.grid(True)
        plt.show()

def delta(x, y):
    delta_x = 2 * (x - 1) + 8 * x * (x ** 2 - y)
    delta_y = 4 * (y - x ** 2)
    return delta_x, delta_y

def func(x, y):
    return (1 - x) ** 2 + 2 * (x ** 2 - y) ** 2

# 绘制等值线
plot()

if METHOD in ['1norm', '2norm', 'infnorm']:
    solve1()
elif METHOD in ['FR', 'PR']:
    solve2()
