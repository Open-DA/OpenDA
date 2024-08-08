import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt 
import scipy.stats as stats
import logging
# import statsmodels.api as sm

# linear regression
class linear_regression1:
    def __init__(self, Y, X, alpha=0.05, intercept=False):
        '''
        Args:
            Y:          label. (nsamples)
            X:          features. (nsamples × dimension)
            alpha:      float. fignificance level.
            intercept:  default=False.
        '''        
        # initiate data
        self.y = Y.reshape(-1, 1)
        self.dim = X.shape[1]
        self.x = X.reshape(-1, self.dim)
        self.alpha = alpha
        self.length = len(self.x)
        self.intercept = intercept

        # data process
        self.y_mean = np.mean(self.y)
        self.y_std = np.std(self.y)
        self.x_mean = np.mean(self.x, axis=0, keepdims=True)
        self.x_std = np.std(self.x, axis=0, keepdims=True)

        # normalize
        self.y_nd = (self.y - self.y_mean) / self.y_std
        self.x_nd = (self.x - self.x_mean) / self.x_std
        # n × dimension

    def decompose(self, thres=0.95):
        '''
        Handle Morbid problem.
        '''
        self.corr_mat = np.matmul(self.x_nd.T, self.x_nd)

        # Eigenvalue Decomposition
        eig_val, eig_vector = np.linalg.eig(self.corr_mat)
        sorted_eig_idx = np.argsort(eig_val)[::-1]
        
        lambda_count = 0
        lambda_sum = np.sum(eig_val)
        index = 0
        for i in range(len(sorted_eig_idx)):
            index = i + 1
            lambda_count = np.sum(eig_val[sorted_eig_idx[:index]]) / lambda_sum
            if lambda_count > thres:
                break
        
        self.trans_mat = eig_vector[:, sorted_eig_idx[:index]].T
        # selected × dimension

        # decomposed x
        self.x_decom = np.matmul(self.trans_mat, self.x_nd.T).T
        # n × selected

        # print
        print('Decomposed dimension: {}'.format(index))


    def fit(self, thres=0.95):
        
        '''
        Linear regression
        '''
        # Morbid problem
        self.decompose(thres)
        self.y_fit = self.y_nd
        if self.intercept:
            self.x_fit = np.concatenate([self.x_decom, np.ones((self.length, 1))], axis=-1)
        else:
            self.x_fit = self.x_decom

        # fitting: omega = ( X.T * X )^-1 * X.T * y
        self.omega = np.linalg.inv( np.matmul(self.x_fit.T, self.x_fit) )
        self.omega = np.matmul(self.omega, self.x_fit.T)
        self.omega = np.matmul(self.omega, self.y_fit)

        # confidence: F = (N - n - 1) ESS / (n * RSS)
        n = self.x_fit.shape[1]
        self.y_pre = np.matmul(self.x_fit, self.omega)
        self.ess = np.sum( (self.y_pre.ravel() - self.y_pre.mean())**2 )
        self.rss = np.sum( (self.y_pre.ravel() - self.y_fit.ravel())**2 )
        self.F = ((self.length - n - 1) * self.ess) / (n * self.rss)

        F0 = stats.f.ppf(1 - self.alpha, n, self.length - n - 1)
        if self.F > F0:
            print('Linearity is considered under the condition of significance {}'.format(self.alpha))
        else:
            print('Linearity IS NOT considered under the condition of significance {}'.format(self.alpha))
        
        # confidence interval
        self.S_sigma = np.sqrt(self.rss / (self.length - n - 1))
        self.Z_alpha_by2 = stats.norm.ppf(1 - self.alpha / 2, 0, 1)

        # recover
        if self.intercept:
            self.inter = self.omega[-1]
            self.omega = self.omega[:-1]
            self.re_omega = np.matmul(self.omega.T, self.trans_mat)
            self.final_omega = np.ones_like(self.re_omega).ravel()
            for i in range(len(self.final_omega)):
                self.final_omega[i] = self.re_omega.ravel()[i] * self.y_std / self.x_std.ravel()[i]
            self.inter = self.inter * self.y_std + self.y_mean - np.matmul( self.re_omega, self.y_mean.ravel() / self.y_std.ravel() ) * self.y_std
        else:
            self.re_omega = np.matmul(self.omega.T, self.trans_mat)
            self.final_omega = np.ones_like(self.re_omega).ravel()
            for i in range(len(self.final_omega)):
                self.final_omega[i] = self.re_omega.ravel()[i] * self.y_std / self.x_std.ravel()[i]
            self.inter = self.y_mean - np.matmul( self.re_omega, self.x_mean.ravel() / self.x_std.ravel() ) * self.y_std
    
    def print_formula(self):
        '''
        print formulation
        '''
        print('omega', self.omega)
        print('re_omega', self.re_omega)
        print('final_omega', self.final_omega)
        print('intercept', self.inter)
        print('S_sigma', self.S_sigma)
        print('Z', self.Z_alpha_by2)
        print('error', self.Z_alpha_by2 * self.S_sigma * self.y_std)

    def predict(self, X):
        '''prediction
        '''
        return np.matmul(X, self.final_omega.reshape(-1, 1)) + self.inter
    

if __name__ == '__main__':
    # hyper-parameters
    raw_data = pd.read_csv('../data/data.csv')
    X = np.array(raw_data.iloc[:, :4])
    Y = np.array(raw_data.iloc[:, 4])

    model = linear_regression1(Y, X, alpha=0.05, intercept=False)
    model.fit()
    y_pre = model.predict(X)
    result = np.concatenate([y_pre.reshape(1, -1), Y.reshape(1, -1)], axis=0)
    result = pd.DataFrame(result)
    result.to_csv('result.csv')
    model.print_formula()

    # model = sm.OLS(data[:, 0], sm.add_constant(data[:, 1]))
    # model = model.fit()
    # print(model.summary())
