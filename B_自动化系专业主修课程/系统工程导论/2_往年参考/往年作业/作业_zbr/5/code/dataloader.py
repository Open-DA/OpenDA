import pandas as pd 
import numpy as np 

datapath = '../data/counties.xlsx'

def load_data(path=datapath):
    df = pd.read_excel(path)
    X = np.array(df.iloc[:, 2:(2+14)])
    Y = np.array(df.iloc[:, -1])
    return X, Y

if __name__ == '__main__':
    data = load_data()