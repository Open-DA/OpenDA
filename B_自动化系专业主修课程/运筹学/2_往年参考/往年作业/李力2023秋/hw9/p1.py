import numpy as np
import matplotlib.pyplot as plt

def goldstein_search_with_plot(f, df, alpha=1.3, m1=0.2, m2=0.8, t0=1, tol=1e-5, max_iter=100, x_range=(-np.pi, np.pi)):
    """
    非精确搜索的 Goldstein 法，并绘制示意图。

    :param f: 目标函数。
    :param df: 目标函数的导数。
    :param alpha: 步长增加因子。
    :param m1: Goldstein 条件中的参数。
    :param m2: Goldstein 条件中的参数。
    :param t0: 初始步长。
    :param tol: 收敛容忍度。
    :param max_iter: 最大迭代次数。
    :param x_range: x 的范围。
    :return: 最优步长。
    """
    a_0 = -np.pi
    a_k = -np.pi
    b_k = np.pi
    t_k = t0
    k = 0

    # 用于绘图的数据
    x_values = np.linspace(x_range[0], x_range[1], 400)
    f_values = f(x_values)
    g1_values = f(a_0) + m1 * (x_values-x_range[0]) * df(a_0)
    g2_values = f(a_0) + m2 * (x_values-x_range[0])  * df(a_0)

    while k < max_iter:
        phi_tk = f(a_0+t_k)
        g1_tk = f(a_0) + m1 * (t_k) * df(a_0)
        g2_tk = f(a_0) + m2 * (t_k) * df(a_0)
       # print('k = {}, t_k = {}, phi_tk = {}, g1_tk = {}, g2_tk = {}'.format(k, t_k, phi_tk, g1_tk, g2_tk))

        if phi_tk > g1_tk:
            b_k = a_0+t_k
        else:
            if phi_tk > g2_tk:
                break
            a_k = a_0+t_k
            if b_k < np.inf:
                t_k = 0.5 * (a_k-a_0 + b_k-a_0)
            else:
                t_k = alpha * t_k

        k += 1
        if abs(b_k - a_k) < tol:
            break

    # 绘制函数图和 Goldstein 条件线
    plt.figure(figsize=(10, 6))
    plt.plot(x_values, f_values, label='$f(x)$')
    plt.plot(x_values, g1_values, label='$g_1(x)$', linestyle='--')
    plt.plot(x_values, g2_values, label='$g_2(x)$', linestyle='-.')
    plt.axvline(x=a_0+t_k, color='red', label='Optimal $t_k$')
    plt.xlim(x_range)
    plt.ylim(min(f_values) - 1, max(f_values) + 1)
    plt.title('Goldstein Search Method')
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.legend()
    plt.grid(True)
    plt.show()

    return t_k

# 定义新的目标函数和导数
def f(x):
    return np.sin(x) + 0.5 * x**2

def df(x):
    return np.cos(x) + x

# 执行 Goldstein 搜索并绘制图像
optimal_t = goldstein_search_with_plot(f, df, x_range=(-np.pi, np.pi),t0 = 2)
print("初始设定:","\n初始步长t0 = 2","\nalpha=1.3, m1=0.2, m2=0.8")
print("搜索结果：","步长：",optimal_t,"最优点：",f"x = {-np.pi+optimal_t},y = {f(-np.pi+optimal_t)}")
