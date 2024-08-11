import numpy as np
from scipy import stats

def linear_regression1(Y, X, alpha=0.05, error=0.01):
    """
    输入：n×N的矩阵X,1×N的矩阵Y
    输出：N×1的回归系数theta
    功能：实现Y=c^T*X+b的多元线性回归，自适应病态线性回归
    """
    n, N = X.shape

    # 数据规范化
    x_mean = np.mean(X, axis=1, keepdims=True)
    delta_x = np.sqrt(
        np.sum(np.multiply(X - np.mean(X, axis=1, keepdims=True), X - np.mean(X, axis=1, keepdims=True)), axis=1,
               keepdims=True) / (N - 1))
    X_normal = np.divide(X - x_mean, delta_x)
    y_mean = np.mean(Y)
    delta_y = np.sqrt(np.sum(np.multiply(Y - y_mean, Y - y_mean)) / (N - 1))
    Y_normal = (Y - y_mean) / delta_y

    # 根据阈值确定最优维度m
    eigenvalue, eigenvector = np.linalg.eig(np.dot(X_normal, X_normal.T))
    eigen_index = np.argsort(-eigenvalue)  # 返回排序的下标
    eigen_sum = np.sum(eigenvalue)
    for m in range(0, n):
        eigen_error = 0
        for i in range(0, m):
            eigen_error += eigenvalue[eigen_index[n - 1 - i]]
        eigen_error = eigen_error / eigen_sum
        if eigen_error > error:
            break
    m = n - m + 1  # 则前m项是要保留的

    # 计算降维后的回归系数d，从而确定降维前的回归系数c_n,恢复得到归一化前的回归系数c
    Q = eigenvector[:, eigen_index[0: m]]
    Z = Q.T.dot(X_normal)
    d = np.linalg.inv(Z.dot(Z.T)).dot(Z.dot(Y_normal.T))
    c_n = Q.dot(d)
    c = (c_n.T / np.squeeze(delta_x) * delta_y).T
    b = y_mean - np.sum(c * np.squeeze(x_mean))
    print("特征值从大到小依次为：", eigenvalue[eigen_index[:]])
    print("降维后的维度为：", m)
    print("降维后的系数为：", d)
    print("规范化后的系数为：", c_n)
    print("原始系数为：", c)
    print("原始偏移为：{:.4f}".format(b))

    # F检验操作
    Y_estimate = np.dot(c.T, X) + b
    ESS = np.dot((Y_estimate - y_mean), (Y_estimate - y_mean).T)
    RSS = np.dot((Y - Y_estimate), (Y - Y_estimate).T)
    F = ((N - m - 1) * ESS) / (m * RSS)  # ESS自由度为（N-m-1），RSS自由度为m
    F_alpha = stats.f.isf(alpha, m, N - m - 1)
    if F > F_alpha:
        print("F检验结果为：F = {:.4f} > F_alpha = {:.4f}".format(F, F_alpha), " 说明x与y存在线性关系")
    elif F <= F_alpha:
        print("F检验结果为：")
        print("F-value = {} <= F_alpha = {}".format(F, F_alpha))
        print("x与y不存在线性关系")
        return 0

    # 置信区间
    S_delta = np.sqrt(RSS / (N - m - 1))
    Z_alpha_div2 = stats.norm.isf(alpha / 2, 0, 1)
    interval = Z_alpha_div2 * S_delta
    print("置信区间为: (y - {:.4f}, y + {:.4f})".format(interval, interval))

    # 打印回归方程
    equation = "y = %.4f" % b
    for i in range(n):
        equation += " + %.4fX%d" % (c[i], i + 1)
    print("回归方程为: ", equation)

    return


if __name__ == '__main__':
    f = open('data.txt', 'r', encoding='utf-8')
    # raw_data = np.array([list(map(float, i[:-1].split(' '))) for i in f.readlines()[1:]])
    raw_data = np.array([i[:-1].split(' ') for i in f.readlines()[1:]], dtype=float)
    x = raw_data[:, 1: 5]
    y = raw_data[:, -1]
    linear_regression1(y.T, x.T, 0.05, 0.01)
