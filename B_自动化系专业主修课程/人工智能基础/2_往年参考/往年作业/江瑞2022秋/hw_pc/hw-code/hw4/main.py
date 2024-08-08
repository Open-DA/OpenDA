
import numpy as np
x = 3


for i in range(30):
    print(i)
    print(x)
    print('error:',1/2*(1/x**2+2/x-np.log(x)))
    x = x+1/2*(1/x**2+2/x-np.log(x))

# x = 4
# x = 2/3 - 86/(3*x**3)
# print(x)