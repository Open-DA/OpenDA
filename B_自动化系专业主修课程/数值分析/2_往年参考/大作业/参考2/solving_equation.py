import gmpy2
import math
import matplotlib.pyplot as plt
import numpy as np

def zeta(n, x):
    zeta = gmpy2.mpfr(0)
    for k in range(1, n+1):
        zeta += gmpy2.mpfr(1 / (gmpy2.mpfr(k) ** gmpy2.mpfr(x)))
    return zeta

def zeta_prime(n, x):
    zeta = gmpy2.mpfr(0)
    for k in range(1, n+1):
        zeta -= gmpy2.mpfr(math.log(k) / (gmpy2.mpfr(k) ** gmpy2.mpfr(x)))
    return zeta

def zeta_prime_prime(n, x):
    zeta = gmpy2.mpfr(0)
    for k in range(1, n+1):
        zeta += gmpy2.mpfr(math.log(k) * math.log(k) / (gmpy2.mpfr(k) ** gmpy2.mpfr(x)))
    return zeta

def plot_funtion():
    x = np.arange(1, 10, 0.01)
    zeta_y = np.array([zeta(2000, i) for i in x])
    zeta_prime_y = np.array([zeta_prime(2000, i) for i in x])
    a = np.array([1.5 for i in x])
    plt.plot(x, zeta_y, label='zeta')
    plt.plot(x, zeta_prime_y, label='zeta_prime')
    plt.plot(x, a, label='a=1.5')
    plt.xlim(1, 10)
    plt.ylim(-20, 20)
    plt.legend()
    plt.show()

def get_M1():
    x = np.arange(2, 2.25, 0.01)
    m1 = np.array([abs(-1 / (zeta_prime(2000, i))) for i in x])
    # get max
    print(max(m1))

def get_M2():
    x = np.arange(2, 2.25, 0.01)
    m2 = np.array([abs((zeta(2000, i)-1.5) / (zeta_prime(2000, i) * zeta(2000, i))) for i in x])
    # get max
    print(max(m2))

def get_L():
    x = np.arange(2, 2.25, 0.01)
    L = np.array([(zeta(2000, i)-1.5) * zeta_prime_prime(2000, i) / (zeta_prime(2000, i) * zeta_prime(2000, i)) for i in x])
    # get max
    print(max(L))

def newton(newton_n,zeta_n, x_0, delta):
    x_n = x_0
    for i in range(newton_n):
        x_new = x_n - (zeta(zeta_n, x_n) - 1.5) / zeta_prime(zeta_n, x_n)
        if abs(x_new - x_n) < delta:
            return x_n, i
        x_n = x_new

if __name__ == '__main__':
    # get_M1()
    # get_M2()
    # get_L()
    x_n, n = newton(10,500000,2.2,3e-5)
    print(x_n, n+1)
    # plot_funtion()