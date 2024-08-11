import gmpy2
import math
import matplotlib.pyplot as plt
import numpy as np

def zeta(n, x):
    zeta = gmpy2.mpfr(0)
    for k in range(1, n+1):
        zeta += gmpy2.mpfr(1 / (gmpy2.mpfr(k) ** gmpy2.mpfr(x)))
    return zeta

def ft(t, x):
    return t ** (x - 1) * math.exp(-t)


def trapezoid_formula(a, b, n, x):
    h = gmpy2.mpfr((b - a) / n)
    s = gmpy2.mpfr(0.5) * (ft(a, x) + ft(b, x))
    for i in range(1, n):
        s += ft(a + i * h, x)
    return s * h

def integral_gamma(x, A, n):
    return trapezoid_formula(0, A, n, x)

if __name__ == '__main__':
    ga = integral_gamma(3.5, 200, 250000)
    ze = zeta(10000, 3.5)
    result = ga * ze
    print(result)
