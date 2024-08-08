# -*- coding: UTF-8 -*-
"""
@File ：problem3.py
@Author ：PengCheng
@Date ：2022/12/21 8:41
@Intro: Solve problem 3
"""
import gmpy2 as gm
from gmpy2 import mpfr
import numpy as np


# 指定x和精度m
x = 3.5
m = 4

def get_fpp(x):
    a = -1
    b = 3 * (x-1)
    c = - 3 *(x-1)*(x-2)
    d = (x-1)*(x-2)*(x-3)

    p1 = complex(-1,3**(1/2))
    p2 = complex(-1,-3**(1/2))
    tmp = (36*a*b*c-8*b**3-108*a**2*d)
    deltap = (36*a*b*c-8*b**3-108*a**2*d)**2+(12*a*c-4*b**2)**3
    m = (tmp+deltap**(1/2))**(1/3)
    n = (tmp-deltap**(1/2))**(1/3)
    t1 = (-2*b+m+n)/(6*a)
    t2 = -b/(3*a) + p1/(12*a)*m +p2/(12*a)*n
    t3 = -b/(3*a) + p2/(12*a)*m +p1/(12*a)*n
    s = [t1.real,t2.real,t3.real]
    y = [(x**2-3*x+2-2*(x-1)*t+t**2)*t**(x-3)*np.exp(-t) for t in s]
    yp = [abs(m) for m in y]
    return max(yp)


def get_zeta_max(x):
    sum = 0
    k = 10000
    for i in range(k):
        sum += 1/ ((i + 1) ** x)

    sum += k**(1-x)/(x-1)
    return sum


def get_gamma_max(x):
    m = 10000
    T = m * 0.5 * (ft(x, 0) + ft(x, m))
    n = 10
    xk = [0, m]
    for i in range(n):
        print(i)
        T = 0.5 * T
        sum = 0
        h = m / 2 ** (i)
        for j in range(2 ** (i)):
            k = (j + 0.5) * h
            sum += ft(x, k)
        T += 0.5 * h * sum
    return int(T)+1

def get_gamma_max(x):
    m = 10000
    T = m * 0.5 * (ft(x, 0) + ft(x, m))
    n = 10
    for i in range(n):
        T = 0.5 * T
        sum = 0
        h = m / 2 ** (i)
        for j in range(2 ** (i)):
            k = (j + 0.5) * h
            sum += ft(x, k)
        T += 0.5 * h * sum
    return int(T)+1

def get_m(x,z):
    zeta_max = get_zeta_max(x)
    m = 2*np.log(32*zeta_max*10**z)
    return m

def get_i(x,z,m):
    zeta_max = get_zeta_max(x)
    fpp = get_fpp(x)
    i = np.log2(16*m**3*10**z*zeta_max*fpp/12)
    i = int(i)+1
    return i

def get_k(x,z):
    gamma_max = get_gamma_max(x)
    k = (8*10**z*gamma_max/(x-1))**(1/(x-1))
    return k

def get_t(x,z,m,k):
    zeta_max = get_zeta_max(x)
    gamma_max = get_gamma_max(x)
    t1 = np.log10(m/2*8*10**z*zeta_max)
    t2 = np.log10(k/2*8*10**z*gamma_max)
    t = max(t1,t2)
    return t

def ft(x,t):
    return t**(x-1)*np.e**(-t)

def gamma(x,z):
    m=get_m(x,z)
    n = get_i(x,z,m)
    k = get_k(x,z)
    t = get_t(x,z,m,k)
    gm.get_context().precision = (int((int(t) + 1) / 3) + 1) * 20

    T = mpfr(m * 0.5 * (ft(x, 0) + ft(x, m)))
    for i in range(n):
        print(i)
        T = 0.5*T
        sum = mpfr('0')
        h = m / 2 ** (i)
        for j in range(2**(i)):
            k= (j+0.5)*h
            sum += mpfr(ft(x, k))
        T+= 0.5*h*sum
    return T

def zeta(x,z):
    m = get_m(x, z)
    k = get_k(x, z)
    t = get_t(x, z, m, k)
    # print('m',m)
    # print('k',k)
    # print('t',t)
    gm.get_context().precision = (int((int(t) + 1) / 3) + 1) * 20
    sum = mpfr('0')
    k = get_k(x,z)
    k = int(k)+1
    for i in range(k):
        sum += mpfr(1 / ((i + 1) ** x))
    sum += k ** (1 - x) / (x - 1)
    return sum


zeta = zeta(x,m)
gamma = gamma(x,m)
result = zeta * gamma
print(f'x={x},有效位数m={m}')
print('zeta:',zeta)
print('gamma',gamma)
print('result:',result)