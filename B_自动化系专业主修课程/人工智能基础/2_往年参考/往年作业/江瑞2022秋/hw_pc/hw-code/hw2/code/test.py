"""
# File       : test.py
# Time       ：2022/10/26 20:42
# Author     ：Peng Cheng
# Description：
"""
import numpy as np

test = np.zeros([4,4])
test[0,0] = 1
test[1,1] = 2
test[2,2] = 3
test[3,3] = 4
print(test[0:2,0:2])
print(test)