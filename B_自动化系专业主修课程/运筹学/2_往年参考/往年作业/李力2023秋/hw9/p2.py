import numpy as np
import matplotlib.pyplot as plt
import matplotlib
from scipy.linalg import norm
from scipy.optimize import fsolve

matplotlib.rc("font", family='KaiTi')
matplotlib.rcParams['axes.unicode_minus'] = False


def f(x, y):
    return (1 - x) ** 2 + 2.0 * (x ** 2-y) ** 2


def grad(x, y):
    return 2.0 * (x-1) + 8 * x *(x**2- y), 4 * (y-x**2)


def function_contour(points=None):
    x_min, x_max, y_min, y_max = -1, 1.5, -1, 1.5
    dx, dy = 0.001, 0.001

    x_axis = np.arange(x_min, x_max + dx, dx)
    y_axis = np.arange(y_min, y_max + dy, dy)
    X, Y = np.meshgrid(x_axis, y_axis)
    Z = f(X, Y)
    levels = np.linspace(-0.5, 3, 20)
    # levels 保留两位小数
    levels = np.around(levels, decimals=2)
    contour_set = plt.contour(X, Y, Z, levels=levels, cmap='coolwarm')
    plt.clabel(contour_set, inline=True, fontsize=10)

    if points is not None:
        points = np.array(points, dtype=object).reshape(-1, 2)
        plt.plot(points[:, 0], points[:, 1])

    plt.xlim([x_min, x_max])
    plt.ylim([y_min, y_max])
    plt.xlabel("x")
    plt.ylabel("y")
    plt.title(r"$f(x,y)=(1-x)^2+2(x^2-y)^2$的等值线")

    plt.show()


def FR_D(x_new, y_new, x, y, k, n, D):
    dx_new, dy_new = grad(x_new, y_new)
    dx, dy = grad(x, y)
    if k % n == 0:
        return [-dx_new, -dy_new]

    alpha = (dx_new ** 2 + dy_new ** 2) / (dx ** 2 + dy ** 2)
    D_new = [-dx_new + alpha * D[0], -dy_new + alpha * D[1]]

    return D_new


def PR_D(x_new, y_new, x, y, k, n, D):
    dx_new, dy_new = grad(x_new, y_new)
    dx, dy = grad(x, y)
    if k % n == 0:
        return [- dx_new, - dy_new]
    alpha = (dx_new * (dx_new - dx) + dy_new * (dy_new - dy)) / (dx ** 2 + dy ** 2)
    D_new = [-dx_new + alpha * D[0], -dy_new + alpha * D[1]]

    return D_new


def t_solve(x, y, D):
    def diff_ft(t):
        return (2 * ((x + t * D[0]) - 1) + 8 * (x + t * D[0])*((x + t * D[0])**2-(y + t * D[1])))*D[0]+4*((y + t * D[1])-(x + t * D[0])**2)*D[1]
    result = fsolve(diff_ft, 0, xtol=1e-4)
    print(result)
    return result


def optim(x_0, y_0, epsilon_ref, func_D, conjugate=False):
    x_old, y_old = x_0, y_0
    x_t, y_t = x_0, y_0
    D, t, k, points = [0, 0], 0, 0, [[x_t, y_t]]
    epsilon = norm(grad(x_t, y_t))

    while epsilon > epsilon_ref:
        if conjugate:
            D = func_D(x_t, y_t, x_old, y_old, k, 4, D)
        else:
            D = func_D(x_t, y_t)
        x_old, y_old = x_t, y_t
        t = t_solve(x_t, y_t, D)
        x_t, y_t = x_t + t * D[0], y_t + t * D[1]
        points.append([x_t, y_t])
        k += 1
        epsilon = norm(grad(x_t, y_t))

    return k, x_t, y_t, points


def function_iter(points):
    obj_list = []
    for point in points:
        obj = f(point[0], point[1])
        obj_list.append(obj)
    iters = [i for i in range(len(obj_list))]
    print(iters)
    plt.plot(np.array(iters, dtype=object), np.array(obj_list, dtype=object))
    # x轴单位长度为1，y轴单位长度为0.1
    plt.xticks(np.arange(0, len(obj_list), 1))
    plt.title("目标函数值随迭代次数增加的变化曲线")
    plt.xlabel('iter')
    plt.ylabel(r'$f(x, y)$')
    plt.show()


# 原函数等值线绘制
function_contour()
# 共轭梯度法Fletcher-Reeves迭代过程
k, x_t, y_t, points = optim(0, 0, 1e-4, FR_D, True)
print("F-R：")
print(f"迭代次数：{k}")
print(f"最优解：({x_t}, {y_t})")
print(f"最优目标值：{f(x_t, y_t)}")
function_iter(points)
function_contour(points)

# 共轭梯度法Polak-Ribiere迭代过程
k, x_t, y_t, points = optim(0, 0, 1e-4, PR_D, True)
print("P-R：")
print(f"迭代次数：{k}")
print(f"最优解：({x_t}, {y_t})")
print(f"最优目标值：{f(x_t, y_t)}")
function_iter(points)
function_contour(points)