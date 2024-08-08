import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt 
import scipy.stats as stats
# import statsmodels.api as sm

# linear regression
class linear_regression1:
    def __init__(self, data, alpha=0.05):
        '''
        Args:
            data:       numpy.array. First column - Y; Second column - X.
            alpha:      float. fignificance level.
        '''
        if not isinstance(data, np.ndarray):
            data = np.array(data)
        
        self.y = data[:, 0]
        self.x = data[:, 1]
        self.alpha = alpha
        self.length = len(self.x)

        self.hat_a = 0
        self.hat_b = 0

    def fit(self):
        '''
        Linear regression
        $ \hat{y}_i = \hat{b} + \hat{a} \cdot x_i $
        '''
        # fitting
        y_mean = self.y.mean()
        x_mean = self.x.mean()
        sigma_xy = np.matmul(self.x, self.y)
        nomerator = sigma_xy - self.length * x_mean * y_mean
        denominator = (self.x**2).sum() - self.length * x_mean * x_mean

        self.hat_a = nomerator / denominator
        self.hat_b = y_mean - self.hat_a * x_mean

        # confidence 
        self.y_pre = self.hat_a * self.x + self.hat_b
        self.ESS = ((self.y_pre - y_mean) ** 2).sum()
        self.RSS = ((self.y_pre - self.y) ** 2).sum()
        self.F = self.ESS * (self.length - 2) / self.RSS
        self.P = stats.f.cdf(self.F, 1, self.length - 2)

        if self.P > ( 1-self.alpha):
            print('Linear relationship holds')
        else:
            print('Linear relationship doesn\'t hold')
        
        # confidence interval
        self.S_sigma = np.sqrt(self.RSS / (self.length - 2))
        self.Z_alpha_by2 = stats.norm.ppf(1 - self.alpha / 2, 0, 1)
    
    def print_formula(self):
        '''
        print formulation
        '''
        formula_str = 'y = {:.2f} * x + {:.2f}'.format(self.hat_a, self.hat_b)
        print('ESS:                     ', self.ESS)
        print('RSS:                     ', self.RSS)
        print('F:                       ', self.F)
        print('P:                       ', self.P)
        print('S_sigma:                 ', self.S_sigma)
        print('Z_alpha/2:               ', self.Z_alpha_by2)
        print('x mean:                  ', self.x.mean())
        print('y mean:                  ', self.y.mean())
        print('hat_a:                   ', self.hat_a)
        print('hat_b:                   ', self.hat_b)
        print('fitting formula:         ', formula_str)
        print('confidence interval:     (y - {}, y + {})'.format(self.S_sigma * self.Z_alpha_by2, self.S_sigma * self.Z_alpha_by2) )
    
    def plot(self, title='fitting curve'):
        '''
        plot origin data and fitting  and confidence interval.
        '''
        # plot origin data
        plt.figure(title)
        plt.scatter(self.x, self.y, label='origin')
        plt.xlabel('x')
        plt.ylabel('y')

        # plot fitting curve
        x_min = self.x.min()
        x_max = self.x.max()
        x = np.linspace(x_min, x_max, num=100)
        y = self.hat_a * x + self.hat_b
        plt.plot(x, y, label='fitting curve')

        # plot confidence interval
        y_upperbound = y + self.Z_alpha_by2 * self.S_sigma
        y_lowerbound = y - self.Z_alpha_by2 * self.S_sigma
        plt.plot(x, y_upperbound, label='upper bound')
        plt.plot(x, y_lowerbound, label='lower bound')

        plt.title(title)
        plt.grid()
        plt.legend()
        plt.show()

    

if __name__ == '__main__':
    # hyper-parameters
    raw_data = pd.read_csv('../data/data')
    data = np.array(raw_data)[:,[1, 0]]
    # print(data)

    model = linear_regression1(data, alpha=0.05)
    model.fit()
    model.print_formula()
    model.plot()

    # model = sm.OLS(data[:, 0], sm.add_constant(data[:, 1]))
    # model = model.fit()
    # print(model.summary())
