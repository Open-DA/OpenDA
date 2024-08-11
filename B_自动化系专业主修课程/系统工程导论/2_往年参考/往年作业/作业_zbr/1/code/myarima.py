import scipy.io as sio
import numpy as np 
import pandas as pd 
import itertools
import matplotlib.pyplot as plt 
import numpy as np 
import pandas as pd 

DEBUG_MODE = True
def debug_print(info):
    if DEBUG_MODE:
        print(info)

class myarima:
    def __init__(self, data, order):
        '''
        Args:
            data:       ndarray. 1D
            order:      tuple. (p, d, q)
        '''
        self.p, self.d, self.q = order
        self.data = data
        self.len = len(self.data)
        self._weight_init()

        if self.d >= self.len:
            raise KeyError("d can't be larger than the length of data series")
        if self.p >= self.len:
            raise KeyError("p can't be larger than the length of data series")
        if self.q >= self.len:
            raise KeyError("q can't be larger than the length of data series")

        if not isinstance(self.data, np.ndarray):
            self.data = np.array(self.data)
        self.data = self.data.reshape(-1)
        
        # diff
        self.data_diff_d = self.data
        self.diff()

    def _weight_init(self):
        '''
        default weight initation.
        '''
        self.ar_weight = np.ones(self.p) / self.p
        self.ma_weight = np.ones(self.q) / self.q

    def diff(self):
        self.anchor = self.data[0]
        for i in range(self.d):
            self.data_diff_d = np.diff(self.data_diff_d)
            self.anchor = np.append(self.data_diff_d[0], self.anchor)
        debug_print(self.data_diff_d)

    def fit(self):
        '''
        \hat{y_{t}} = \mu + \theta_{1} y_{t-1} + \theta_{2} y_{t-2} + ... + \theta_{p} y_{t-p} 
                          - \alpha_{1} e_{t-1} - \alpha_{2} e_{t-2} - ... - \alpha_{q} y_{t-q}
        e_{t-a} = \hat{y_{t-a}} - y_{t-a}
        '''
        init_index = max(self.p, self.q)
        self.result = self.data_diff_d[0:init_index]
        for i in range(init_index, len(self.data_diff_d)):
            rel_truth = self.data_diff_d[(i - self.p):i]
            rel_residual = self.result[(i - self.q):i] - self.data_diff_d[(i - self.q):i]
            pre_y = np.matmul(rel_truth, self.ar_weight) - np.matmul(rel_residual, self.ma_weight)
            self.result = np.append(self.result, pre_y)
        debug_print(self.result)
    
    def predict(self):
        '''
        According to the origin data, cumsum the diff series.
        '''
        self.data_predict = self.result
        for i in range(self.d):
            self.data_predict = np.append(self.anchor[i+1], self.data_predict)
            self.data_predict = np.cumsum(self.data_predict)
        debug_print(self.data_predict)
        return self.data_predict
    
    
if __name__ == '__main__':
    data = np.array([1, 4, 3, 6, 2, 7, 2, 3, 4, 6, 1])
    arima = myarima(data, (3, 2, 4))
    arima.fit()
    arima.predict()


        