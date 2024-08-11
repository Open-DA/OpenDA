# -*- coding: UTF-8 -*-
"""
@File ：problem4.py
@Author ：PengCheng
@Date ：2022/12/20 11:44
@Intro: Solve problem 4
"""

import gmpy2 as gm
from gmpy2 import mpfr
from gmpy2 import mpz
import numpy as np

# 此处指定精度和x
x = 4
m = 4

def zeta(x,k):
    s = sum([1 / (i + 1) ** x for i in range(int(k))])
    return s

def yn_bar(y,h,k):
    return y+h*zeta(y,k)

def yn(y,y_bar,h,k):
    return y+h/2*(zeta(y,k)+zeta(y_bar,k))

def solve(a,t):
    n = gm.ceil(gm.sqrt((8 * (np.e ** (a - 2) - 1) * (a - 2) ** 2) * 10 ** t))
    m = gm.ceil(t + gm.log10(4 * n * (np.e ** (a - 2) - 1) / ((a - 2))))
    k = gm.ceil((4 * n * (np.e ** (a - 2) - 1) / ((a - 2))) * 10 ** t)/1000
    h = (a-2)/n
    print(n,m,k,h)

    gm.get_context().precision = (int((int(m) + 1) / 3) + 1) * 10

    y0 = mpfr('2')
    y = y0
    for i in range(int(n)):
        print(i)
        y_bar = yn_bar(y,h,k)
        y = yn(y,y_bar,h,k)
        # print(y)

    return y



r = solve(x,m)
print(f"x={x}时，具有{m}位精度的y为：")
print(r)