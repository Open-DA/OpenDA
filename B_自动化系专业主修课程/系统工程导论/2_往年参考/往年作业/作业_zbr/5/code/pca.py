import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt 
import scipy.stats as stats
import logging
import dataloader
# import statsmodels.api as sm

logging.basicConfig(level=logging.INFO,
                    format='%(asctime)s - %(filename)s[line:%(lineno)d] - %(levelname)s: %(message)s')

# linear regression
class pca:
    def __init__(self):        
        pass

    def pca_compress(self, X, Y, rerr):
        '''
        Args:
            X           (np.ndarray):       data (features). num × feature dim
            Y           (np.ndarray):       ground truth
            rerr        (np.ndarray):       upper bound of error rate
        
        Returns:
            pcs         (np.ndarray):       principal component. feature dim × num
            cprs_data   (np.ndarray):       compressed data
            cprs_c      (np.ndarray):       for recover original data
        '''
        self.X = X
        self.Y = Y
        self.N = len(self.X)
        self.rerr = rerr

        cprs_c = dict() # for recover
        X_mean = np.mean(X, axis=0)
        X_std = np.std(X, axis=0)
        Y_mean = np.mean(Y)
        Y_std = np.std(Y, axis=0)
        cprs_c['X'] = {'mean': X_mean, 'std': X_std}
        cprs_c['Y'] = {'mean': Y_mean, 'std': Y_std}
        self.cprs_c = cprs_c

        X_tilde = (X - X_mean) / X_std
        Y_tilde = (Y - Y_mean) / Y_std
        self.X_tilde = X_tilde
        self.Y_tilde = Y_tilde

        # matrix decomposition
        cov_mat = np.matmul(X_tilde.T, X_tilde) #/ (self.N - 1)
        eig_val, eig_vec = np.linalg.eig(cov_mat)

        # sort the eig-values
        eig_index_sort = np.argsort(eig_val)[::-1]
        eig_val_sort = eig_val[eig_index_sort]
        eig_cumsum = 0
        eig_sum = sum(eig_val)
        index = 1
        for item in eig_val_sort:
            eig_cumsum += item
            if eig_cumsum / eig_sum > (1 - rerr):
                break
            index += 1
        print('Dimension reduction: ', index)
        eig_val_sort = eig_val[eig_index_sort[:index]]
        pcs = eig_vec[:, eig_index_sort[:index]]
        cprs_data = np.matmul(X_tilde, pcs)
        self.pcs = pcs 
        self.cprs_data = cprs_data
        return pcs, cprs_data, cprs_c
    
    def ols(self, X=None, Y=None, alpha=0.05):
        if X is None:
            X = self.cprs_data
        if Y is None:
            Y = self.Y_tilde
        
        # compute the parameters through OLS
        omega = np.matmul(X.T, X)
        omega = np.linalg.inv(omega)
        omega = np.matmul(omega, X.T)
        omega = np.matmul(omega, Y)
        self.omega = omega

        # compute confidence: F = ( N - n - 1) ESS / (n * RSS)
        n = self.X.shape[1]
        N = self.N
        Y_pre = np.matmul(X, omega).reshape(-1)
        self.ess = np.sum( (Y_pre - Y_pre.mean())**2 )
        self.rss = np.sum( (Y_pre - Y)**2 )
        self.F = (N-n-1)*self.ess / (n*self.rss)
        F0 = stats.f.ppf(1-alpha, n, N-n-1)
        self.F0 = F0

        if self.F > F0:
            print('Linearity is considered under the condition of significance {}'.format(alpha))
        else:
            print('Linearity IS NOT considered under the condition of significance {}'.format(alpha))

        # confidence interval
        self.S_sigma = np.sqrt(self.rss / (N-n-1))
        self.Z_alpha_by2 = stats.norm.ppf( 1  - alpha/2, 0, 1)
        self.interval = self.Z_alpha_by2 * self.S_sigma * self.cprs_c['Y']['std']

        return omega
    
    def recon_data(self, pcs=None, cprs_data=None, cprs_c=None):
        '''
        Args:
            pcs         (np.ndarray):       principal component
            cprs_data   (np.ndarray):       compressed data
            cprs_c      (np.ndarray):       for recover original data

        Returns:
            recon_data  (np.ndarray):       recovered data
        '''
        if pcs is None:
            pcs = self.pcs
        if cprs_data is None:
            cprs_data = self.cprs_data 
        if cprs_c is None:
            cprs_c = self.cprs_c
        
        X_mean = cprs_c['X']['mean']
        X_std = cprs_c['X']['std']
        Y_mean = cprs_c['Y']['mean']
        Y_std = cprs_c['Y']['std']

        self.re_omega = np.matmul(pcs, self.omega)
        self.final_omega = np.ones_like(self.re_omega).ravel()
        for i in range(len(self.final_omega)):
            self.final_omega[i] = self.re_omega.ravel()[i] * Y_std / X_std.ravel()[i]
        self.inter = Y_mean - np.matmul( self.re_omega, X_mean.ravel() / X_std.ravel() ) * Y_std
    
    def print_formula(self):
        '''
        print parameters
        '''
        print('======== OLS result ===============')
        print('omega:           ', self.omega.reshape(-1))
        print('F:               ', self.F)
        print('F0:              ', self.F0)
        print('interval:        ', self.interval)
        print('\n')
        print('======== recover result ===========')
        print('re_omega:        ', self.final_omega.reshape(-1))
        print('intercept:       ', self.inter)

        final_omega = self.final_omega.reshape(-1)
        df = pd.DataFrame(final_omega)
        df.to_csv('result.csv')
        
    

if __name__ == '__main__':
    # hyper-parameters
    X, Y = dataloader.load_data()

    model = pca()
    model.pca_compress(X, Y, rerr=0.05)
    model.ols()
    model.recon_data()
    model.print_formula()



