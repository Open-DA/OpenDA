# -*- coding: utf-8 -*-
"""
Created on Mon Nov 28 20:03:54 2022

@author: hsc
"""
import numpy as np

def update_dis(d):
    new_d = np.array(d)
    for i in range(5):
        for j in range(5):
            if i == j :
                pass
            else:
                tmp = [d[i][k] + d[k][j] for k in range(5)]
                
                new_d[i][j] = min([np.min(tmp ),d[i][j]])
                #print(i,j,'tmp =',tmp,'min_d=',new_d[i][j])
                
    return  new_d
                

inf=np.inf
dis=np.array([[0,3,2,inf,2],
              [3,0,inf,2,inf],
              [2,inf,0,inf,5],
              [inf,2,inf,0,1],
              [2,inf,5,1,0]
              
              ])

for i in range(5):
    dis_new = update_dis(dis)
    print(dis_new)
    if np.sum(dis_new-dis)==0.0:
        break
    dis = dis_new
     
    
     