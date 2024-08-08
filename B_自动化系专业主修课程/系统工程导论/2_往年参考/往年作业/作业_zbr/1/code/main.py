import scipy.io as sio
import numpy as np 
import matplotlib.pyplot as plt 

from myarima import myarima

### hyper-parameters
method = 'arima' # ma / es / arima
N = 5
a = 0.05
p = 100
q = 100
d = 1

def load_data(path):
    '''
    data loading and preprocess.
    Args:
        path.       str. the path where data is located.
    Returns:    
        data.       dict.
    '''
    data = sio.loadmat(path)
    # print(data.keys())
    data = data['data']
    return data

def plot_data(y, x=None, mark=None, title='Traffic Flow Statistic', legend='Traffic Flow', xlabel='T/(30s)', ylabel='N/h'):
    '''
    plot.
    Args:
        y.          numpy.ndarray.
        x.          numpy.ndarray. default: None
    Returns:  
        None
    '''
    # data checking 
    if not isinstance(y, np.ndarray):
        y = np.array(y)
    if x is None:
        x = np.array(list(range(len(y))))
    if not isinstance(x, np.ndarray):
        x = np.array(x)
    
    # plot
    plt.figure(title)
    if mark is None:
        plt.plot(x, y, label=legend)
    else:
        plt.plot(x, y, mark, label=legend)
    plt.legend()
    plt.title(title)
    plt.grid()
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.show()

def MA(data, N=3):
    '''
    Implementation of MA 
    '''
    data_pre = []
    total = len(data)
    for i in range(N - 1, total):
        data_pre.append(sum(data[(i-N+1):(i+1)]) / N)
    data_pre = np.stack(data_pre).reshape(-1)
    plot_data(data_pre, title='MA (N={})'.format(N))

def ES(data, a=0.2):
    '''
    Implementation of ES
    '''
    data_pre = []
    total = len(data)
    S_pre = data[0]
    S_cur = 0
    data_pre.append(S_pre)
    for i in range(total):
        S_cur = S_pre
        S_pre = a * data[i] + (1 - a) * S_cur
        data_pre.append(S_pre)
    data_pre = np.stack(data_pre)
    plot_data(data_pre, title='ES (a={})'.format(a))

def main():
    # load the data
    data_path = '../data.mat'
    data = load_data(data_path).astype('int64')
    # print(data.shape)

    # plot the origin data
    # plot_data(data)

    # prediction
    if method == 'ma':
        data_pre = MA(data, N)
    
    elif method == 'es':
        data_pre = ES(data, a)
    
    elif method == 'arima':
        order = (p, d, q)
        arimaDemo = myarima(data, order)
        arimaDemo.fit()
        data_pre = arimaDemo.predict()
        plot_data(data_pre, title='ARIMA (p={}, d={}, q={})'.format(p, d, q))
    
    else:
        raise KeyError('Unknown method: ', method)
    

if __name__ == '__main__':
    main()