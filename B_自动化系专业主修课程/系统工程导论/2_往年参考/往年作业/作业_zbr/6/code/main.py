#%%
from mykmeans import MyKmeans
import numpy as np 
import pandas as pd 
import os 
import scipy.io as sio
import matplotlib.pyplot as plt 

#%%
### data load
path = os.path.join('../data', 'data.mat')
data = sio.loadmat(path)['data']

#%%
### 3
result = []
num_list = list(range(2, 10))
for num in num_list:
    model = MyKmeans()
    model.clustering(data, num)
    sse = model.sse()
    result.append(sse)
plt.figure('sse')
plt.plot(list(range(2, len(num_list)+2)), result)
plt.grid()
plt.show()

#%%
### 4
# top k
model = MyKmeans()
model.clustering(data, num=3, init='top')
model.visualize()

# random
for i in range(4):
    model = MyKmeans()
    model.clustering(data, num=3)
    model.visualize()

#%%
### 5
num_list = list(range(100, 3100, 100))
time_list = []
for num in num_list:
    sub_time_list = []
    N = 100
    for epoch in range(N):
        model = MyKmeans()
        index = np.random.randint(3000, size=num)
        subdata = data[index, :]
        sub_time_list.append(model.clustering(subdata, 3, return_time=True))
    time_list.append(sum(sub_time_list)/N)
print(time_list)
plt.figure('time')
plt.plot(num_list, time_list)
plt.grid()
plt.show()

pass


# %%
