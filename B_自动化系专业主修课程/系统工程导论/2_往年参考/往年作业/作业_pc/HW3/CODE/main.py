import numpy as np
from scipy import stats
import matplotlib.pyplot as plt


def linear(x, y):
    x_mean = np.mean(x)
    y_mean = np.mean(y)
    b = np.dot(x - x_mean, y - y_mean) / np.dot(x - x_mean, x - x_mean)
    a = y_mean - b * x_mean
    print("回归直线为: y = {} + {} * x" .format(a, b))
    theta = (b, a)
    return theta


def F_check(x, y, a, b, alpha):
    # F检验操作
    y_mean = np.mean(y)
    y_estimate = a + b * x
    N = x.shape[0]
    ESS = np.dot(y_estimate - y_mean, y_estimate - y_mean)
    RSS = np.dot(y - y_estimate, y - y_estimate)
    F = (N - 2) * ESS / RSS
    F_alpha = stats.f.isf(alpha, 1, N - 2)
    if F > F_alpha:
        print("F = {} > F_alpha = {}" .format(F, F_alpha))
        print("x与y存在线性关系")
        return 1
    elif F <= F_alpha:
        print("F-value = {} <= F_alpha = {}".format(F, F_alpha))
        print("x与y不存在线性关系")
        return 0


def confidence_interval(x, y, a, b, alpha):
    # 打印置信区间
    y_estimate = a + b * x
    N = x.shape[0]
    RSS = np.dot(y - y_estimate, y - y_estimate)
    S_delta = np.sqrt(RSS / (N - 2))
    Z_alpha_div2 = stats.norm.isf(alpha / 2, 0, 1)
    interval = Z_alpha_div2 * S_delta
    print("置信区间为: (y - {}, y + {})" .format(interval, interval))
    return interval


def figure_print(x, y, a, b, interval):
    # 绘图
    y_estimate = a + b * x
    plt.rcParams['font.sans-serif'] = ['SimHei']
    plt.rcParams['axes.unicode_minus'] = False
    plt.title("确诊病例和治愈病例一元线性回归分析")
    plt.xlabel("确诊病例")
    plt.ylabel("治愈病例")
    plt.scatter(x, y, marker='o', color='red')
    y_low = a + b * x - interval
    y_up = a + b * x + interval
    plt.plot(x, y_estimate, 'k', label="回归直线")
    plt.plot(x, y_low, 'b--', label="置信区间下边界线")
    plt.plot(x, y_up, 'b--', label="置信区间上边界线")
    plt.legend()
    plt.savefig("回归分析.png")
    plt.show()


def linear_regression1(data, alpha):
    """
    输入为N×2的矩阵 data，第一列为 Y，第二列为 X，显著性水平 alpha,进行线性回归操作
    打印出回归直线方程（有必要的话可以输出重要的中间数据）；
    用F检验法进行统计检验，显著性水平为输入 alpha；输出检验结果，如果输入数据满足线性关系，那么继续 5)和 6)，否则结束。
    打印出置信区间。
    在一个 figure 中，给出：所有的数据点，回归直线，置信区间相应的两条边界直线。
    """
    x = data[:, 1]
    y = data[:, 0]
    # 线性回归
    theta = linear(x, y)
    b = theta[0]
    a = theta[1]
    # F检验
    if not F_check(x, y, a, b, alpha):
        return
    # 置信区间
    interval = confidence_interval(x, y, a, b, alpha)
    # 打印figure操作
    figure_print(x, y, a, b, interval)
    return


if __name__ == '__main__':
    f = open('us_covid19_data2021.txt', 'r')
    raw_data = [i[:-1].split(',') for i in f.readlines()]
    # print(raw_data)
    data = np.zeros((len(raw_data) - 1, 2))
    # 取出需要的数据
    for i in range(0, len(raw_data) - 1):
        data[i][0] = raw_data[i + 1][4]
        data[i][1] = raw_data[i + 1][2]
    # print(data)
    linear_regression1(data, 0.05)
