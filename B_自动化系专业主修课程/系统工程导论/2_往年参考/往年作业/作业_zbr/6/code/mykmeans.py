import numpy as np 
import pandas as pd 
import scipy as spy 
from scipy.spatial.distance import cdist
import scipy.io as sio
import os 
import time
import matplotlib.pyplot as plt 

class MyKmeans:
    def __init__(self):
        pass

    def clustering(self, data, num, thresh=1e-6, init='random', tick_tock=True, return_time=False):
        '''
        Args:
            data    (numpy.ndarray):    N x d
            num     (int):              number of clusters.
        Returns:
            label   (numpy.ndarray):    N x 1
        '''
        self.length = len(data)
        self.dim = data.shape[1]
        self.data = data
        self.num = num
        self.thresh = thresh
        self.init = init

        # tick_tock
        if tick_tock:
            start = time.time()

        # initialization
        if self.init == 'random':
            self.centroids = np.random.rand(self.num, self.dim)
        elif self.init == 'top':
            self.centroids = self.data[:self.num, :]
        self.label = None

        # training 
        while(True):
            # compute distance
            dist_mat = cdist(self.data, self.centroids)

            # update labels
            self.label = np.argmin(dist_mat, axis=1)

            # update centroids
            new_centroids = np.stack([np.mean(self.data[self.label==x, :], axis=0) for x in np.sort(np.unique(self.label))])

            thresh_test = np.sum((self.centroids - new_centroids)**2)
            print('Thresh: ', thresh_test)
            if thresh_test < self.thresh:
                print("Kmeans completed")
                break
            self.centroids = new_centroids
        
        if tick_tock:
            end = time.time()
            period = end - start
            print('Cost Time: ', period)
        
        if return_time:
            return period

    
    def visualize(self, data=None, label=None):
        if label is None:
            label = self.label
        if data is None:
            data = self.data
        
        plt.figure('Visualize')
        plt.grid()
        for idx, item in enumerate(data):
            plt.scatter(item[0], item[1], marker='.', color=plt.cm.Set1(label[idx]))
        plt.show()
    
    def sse(self, data=None, label=None):
        if label is None:
            label = self.label
        if data is None:
            data = self.data
        
        centroids = np.stack([np.mean(self.data[self.label==x, :], axis=0) for x in np.sort(np.unique(self.label))])
        sse = 0
        for index in np.unique(label):
            subdata = data[label == index]
            sse += np.sum((subdata - np.mean(subdata, axis=0, keepdims=True))**2)
        return sse
        

if __name__ == '__main__':
    ### data load
    path = os.path.join('../data', 'data.mat')
    data = sio.loadmat(path)['data']
    model = MyKmeans()
    model.clustering(data, num=3)
    model.sse()
    # model.visualize()

