"""
# File       : main.py
# Time       ：2023/4/4 10:06
# Author     ：Peng Cheng
# Description：
"""

# 最小二乘法绘图
import numpy as np
import matplotlib.pyplot as plt

y = []
x = []
# 最小二乘拟合
def least_squares(x, y):
    x_mean = np.mean(x)
    y_mean = np.mean(y)
    numerator = 0
    denominator = 0
    for i in range(len(x)):
        numerator += (x[i] - x_mean) * (y[i] - y_mean)
        denominator += (x[i] - x_mean) ** 2
    a = numerator / denominator
    b = y_mean - a * x_mean
    return a, b

# 绘制曲线
def draw_line(x, y, a, b,name):
    # 支持中文
    plt.rcParams['font.sans-serif'] = ['SimHei']
    plt.rcParams['axes.unicode_minus'] = False
    # 标题
    plt.title(name)
    # 坐标轴
    plt.xlabel('位移/mm')
    plt.ylabel('电压/mV')
    plt.scatter(x, y)
    x = np.array(x)
    y = a * x + b
    plt.plot(x, y, color='r')
    # 标出拟合直线，画在左上角
    plt.text(0.95, 0.95, 'y = %.6fx + %.4f' % (a, b), ha='right', va='top', transform=plt.gca().transAxes)
    plt.show()

if __name__ == '__main__':
    y1 = [-1.3,1.7,5.0,8.3,11.4,14.7,18.0,20.7,24.5,27.9,31.4]
    x1 = [0,20,40,60,80,100,120,140,160,180,200]
    a, b = least_squares(x1, y1)
    draw_line(x1, y1, a, b,'实验一：单臂电桥输出电压与所加负载重量关系')
    # 计算非线性误差
    delta_y = np.array(y1)-(a*np.array(x1)+b)
    print('非线性误差：',delta_y)

    x2 = [0,20,40,60,80,100,120,140,160,180,200]
    y2 = [2.417,2.427,2.436,2.445,2.454,2.463,2.472,2.481,2.491,2.499,2.508]

    a, b = least_squares(x2, y2)
    draw_line(x2, y2, a, b,'实验二：半桥输出电压与所加负载重量关系')
    # 计算非线性误差
    delta_y = np.array(y2)-(a*np.array(x2)+b)
    print('非线性误差：',delta_y)

    x3 = [0,20,40,60,80,100,120,140,160,180,200]
    y3 = [6.60,6.62,6.64,6.65,6.68,6.69,6.70,6.72,6.73,6.76,6.78]

    a, b = least_squares(x3, y3)
    draw_line(x3, y3, a, b,'实验三：全桥输出电压与所加负载重量关系')
    # 计算非线性误差
    delta_y = np.array(y3)-(a*np.array(x3)+b)
    print('非线性误差：',delta_y)

    x4 = [0,20,40,60,80,100,120,140,160,180,200]
    y4 =[6.61,6.63,6.65,6.67,6.69,6.71,6.73,6.75,6.77,6.79,6.81]

    a, b = least_squares(x4, y4)
    draw_line(x4, y4, a, b,'实验三：电桥输出电压与所加负载重量关系')
    # 计算非线性误差
    delta_y = np.array(y4)-(a*np.array(x4)+b)
    print('非线性误差：',delta_y)

    x = [6.930,7.130,7.330,7.530,7.730,7.930,8.130,8.330,8.530,8.730,8.930]
    y = [145.7,114.3,87.5,48.4,22.0,-0.4,-43.6,-71.7,-104.6,-136.2,-162.8]
    a, b = least_squares(x, y)
    draw_line(x, y, a, b,'实验四：电容传感器位移与输出电压关系')
    # 计算非线性误差
    delta_y = np.array(y)-(a*np.array(x)+b)
    print('非线性误差：',delta_y)