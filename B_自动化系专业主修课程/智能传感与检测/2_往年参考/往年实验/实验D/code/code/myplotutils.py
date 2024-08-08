# -*- coding: utf-8 -*-
"""
Created on Mon Dec 20 17:07:06 2021

@author: 12434
"""


import numpy as np
from scipy.interpolate import griddata
import matplotlib.pyplot as plt
from math import floor

def mycontourf(x,y,z,step=0.05):
    
    xi = np.linspace(min(x), max(x), 50)
    yi = np.linspace(min(y), max(y), 50)
    X, Y = np.meshgrid(xi, yi)
    Z = griddata((x, y), z, (X, Y), method='linear')
    #plt.figure()
    plt.contourf(X,Y,Z)
    plt.colorbar()
    plt.axis("equal")
    
    
    
    
    