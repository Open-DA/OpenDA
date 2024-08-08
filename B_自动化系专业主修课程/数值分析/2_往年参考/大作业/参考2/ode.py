import gmpy2
import math
import matplotlib.pyplot as plt
import numpy as np
import tqdm

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
    zeta_prime_prime_y = np.array([zeta_prime_prime(2000, i) for i in x])
    plt.plot(x, zeta_y, label='zeta')
    plt.plot(x, zeta_prime_y, label='zeta_prime')
    plt.plot(x, zeta_prime_prime_y, label='zeta_prime_prime')
    plt.xlim(2, 4)
    plt.ylim(-20, 20)
    plt.legend()
    plt.show()

def get_M():
    m = abs(zeta_prime(2000, 2))
    print(m)

def get_L():
    l = abs(zeta_prime(2000, 2) * zeta(2000, 2))
    print(l)

def get_T():
    t = abs(zeta_prime_prime(2000, 2) * zeta(2000, 2) ** 2 + zeta_prime(2000, 2) ** 2 * zeta(2000, 2))
    print(t)

def improved_euler(x_0, y_0, x, n, zeta_n):
    h = (x - x_0) / n
    y_n = y_0
    for i in tqdm.tqdm(range(0, n)):
        y_estimate = y_n + h * zeta(zeta_n, y_n)
        new_y = y_n + h * (zeta(zeta_n, y_n) + zeta(zeta_n, y_estimate)) / 2
        y_n = new_y
        print(y_n)
    return y_n

if __name__ == '__main__':
    gmpy2.get_context().precision = 77
    # get_M()
    # get_L()
    # get_T()
    print(improved_euler(2, 2, 4, 2000, 150000))