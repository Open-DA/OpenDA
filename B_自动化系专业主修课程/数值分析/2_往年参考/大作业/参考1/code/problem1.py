# -*- coding: UTF-8 -*-
"""
@File ：problem1.py
@Author ：PengCheng
@Date ：2022/12/19 1:20
@Intro: Solve problem 1
"""
import gmpy2
from gmpy2 import mpfr
from gmpy2 import mpz

# 此处指定精度
m = 20

def get_pi(m):
    k = mpz(1)
    e = mpz(10)**(mpz(m/7)+1) # 避免分数指数问题，全部取整加一
    k = k*e  # 1.1×10^m/8
    print(int(8/7*m)+2)
    gmpy2.get_context().precision = (int((int(8/7*m)+2)/3) +1)*10 # 10进制精度转为2进制精度
    sum = mpfr('0')
    for i in range(k):
        sum +=gmpy2.div(1,(i+1)**8)
    # 开8次方
    tmp = (9450*sum)
    tmp = gmpy2.log(tmp)/8
    tmp = gmpy2.exp(tmp)
    # 得到pi
    pi = tmp
    return pi

pi = get_pi(m)
print(f'精确到{m}位的pi值为：')
print(pi)


