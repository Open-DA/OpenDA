# -*- coding: UTF-8 -*-
"""
@File ：problem2.py
@Author ：PengCheng
@Date ：2022/12/19 17:10
@Intro: Solve problem 2
"""

import gmpy2
from gmpy2 import mpfr
from gmpy2 import mpz
import numpy as np

# 此处指定a值和精度
a = 1.5
m = 4

def get_L(x0,a):
    gmpy2.get_context().precision = 100 # 10进制精度转为2进制精度
    sum0 = mpfr('0')
    sum1 = mpfr('0')
    sum2 = mpfr('0')

    k = 100000
    for i in range(k):
        sum0 += gmpy2.div(1, (i + 1) ** x0)
        sum1 += gmpy2.div(gmpy2.log(i + 1), (i + 1) ** x0)
        sum2 += gmpy2.div(gmpy2.log(i + 1) ** 2, (i + 1) ** x0)
    sum0 -= a
    phi = gmpy2.div(sum0*sum2,sum1**2)
    return phi+0.01


def phi(x,k,a):
    # gmpy2.get_context().precision = 20
    f = mpfr('0',200)
    fp = mpfr('0',200)
    for i in range(k):
        f+=gmpy2.div(1,(i+1)**x)
        fp-=gmpy2.div(gmpy2.log(i+1),(i+1)**x)
    f=f-a
    # print('f:', f)
    # print('fp:', fp)
    phi = x-gmpy2.div(f,fp)

    return phi


def get_result(a,t):
    gmpy2.get_context().precision = 200
    x0 = mpfr((1 + 1 / a))
    x0 = mpfr(2) # 由于级数计算太多，此处调整成2可以在有限时间内算出来
    L = get_L(x0, a)
    k = int(3 / gmpy2.exp(gmpy2.log((1 - L) / (8) * (mpfr(0.1) ** t)) / (x0 - 1))) + 1
    m = int(t * gmpy2.log10(4*(k+1)/(1 - L))) + 1
    print(k)
    print(m)
    gmpy2.get_context().precision = (int(m / 3) + 1) * 10  # 10进制精度转为2进制精度
    x_ = x0
    ep = gmpy2.div(mpfr(1-L),4)*10**(-t)
    print(ep)
    # print(k)
    # print(ep)
    while True:
        x = x_
        x_ = phi(x,k,a)
        # print(x)
        # print(x_)
        # print(gmpy2.cmp(x_,x)*(x_-x))
        if gmpy2.cmp(x_,x)*(x_-x)<ep:
            break


    return x

x = get_result(a,m)
print(f'具有{m}位精度的解为：')
print(x)
