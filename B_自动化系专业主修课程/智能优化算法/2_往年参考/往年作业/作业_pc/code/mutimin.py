# draw 3 \sin (4 x)+4 \cos (3 x)in 

# -*- coding: utf-8 -*-
# 张嘉玮
# 20190503
# 模拟退火算法求多极小函数

import matplotlib.pyplot as plt
import numpy as np

import math
import time

np.random.seed(int(time.time()))

def Func(x):
    return 3*np.sin(4*x) + 4*np.cos(3*x)


# draw func
def draw_func(func, x_range):
    # Generate values
    x = np.linspace(x_range[0], x_range[1], 400)
    y = func(x)

    # Create plot
    fig, ax = plt.subplots()
    ax.plot(x, y, label='3*sin(4x) + 4*cos(3x)')

    # Setting labels and title
    ax.set_xlabel('X axis')
    ax.set_ylabel('Y axis')
    ax.set_title('Function Plot')

    # Adding grid, legend, and making zero lines thicker
    ax.grid(True)
    ax.legend()
    ax.axhline(0, color='black',linewidth=0.8)
    ax.axvline(0, color='black',linewidth=0.8)

    # Setting x and y axis limits
    ax.set_xlim([x_range[0], x_range[1]])
    ax.set_ylim([min(y) - 1, max(y) + 1])

    plt.show()

# Drawing the function
# draw_func(Func, [-3*np.pi, 3*np.pi])

# Simulated Annealing Algorithm
def simulated_annealing(func, T_max, T_min, R, num_iterations):
    """
    Simulated Annealing Algorithm to find the minimum of a function.

    Parameters:
    func (callable): The function to minimize.
    T_max (float): The initial temperature.
    T_min (float): The final temperature.
    R (float): The cooling rate.
    num_iterations (int): The number of iterations at each temperature.

    Returns:
    tuple: The minimum value found and its corresponding x value.
    """
    # Initial random solution
    x = np.random.uniform(0, 2 * math.pi)
    best_value = func(x)
    
    # Arrays to store the best value and temperature at each step
    best_values = []
    temperatures = []

    T = T_max
    while T > T_min:
        for _ in range(num_iterations):
            # Generate a new solution and calculate its value
            x_temp = np.random.uniform(0, 2 * math.pi)
            current_value = func(x_temp)
            dE = best_value - current_value

            # Acceptance condition
            if dE >= 0 or math.exp(dE / T) > np.random.uniform(0, 1):
                best_value = current_value
                x = x_temp

        # Cooling down
        T *= R
        temperatures.append(T)
        best_values.append(best_value)

    # Plotting the results
    # plot_results(best_values, temperatures)
    return best_values, temperatures, best_value, x

# Plot function
def plot_results(best_values, temperatures):
    """
    Plots the progress of the best value and temperature in the Simulated Annealing algorithm.

    Parameters:
    best_values (list): The list of best values found during the algorithm.
    temperatures (list): The list of temperatures during the algorithm.
    """
    fig, ax1 = plt.subplots()

    color = 'tab:red'
    ax1.set_xlabel('Iteration')
    ax1.set_ylabel('Best Value', color=color)
    ax1.plot(best_values, color=color)
    ax1.tick_params(axis='y', labelcolor=color)

    ax2 = ax1.twinx()
    color = 'tab:blue'
    ax2.set_ylabel('Temperature', color=color)
    ax2.plot(temperatures, color=color)
    ax2.tick_params(axis='y', labelcolor=color)

    fig.tight_layout()
    plt.show()

# Example usage
T_max = 10000  # Initial temperature
T_min = 0.001  # Final temperature
R = 0.9        # Cooling rate
num_iterations = 100  # Iterations per temperature

# run 1 time an plot
bvs,tmps,min_value, min_x = simulated_annealing(Func, T_max, T_min, R, num_iterations)
plot_results(bvs, tmps)



# # Run the simulated annealing algorithm 20 times
min_value_list = []
min_x_list = []
for i in range(20):

    # Run the simulated annealing algorithm
    _,_,min_value, min_x = simulated_annealing(Func, T_max, T_min, R, num_iterations)
    min_value_list.append(min_value)
    min_x_list.append(min_x)
    # 打印，保留五位小数
    print('min value:%.5f' % min_value, 'min x:%.5f' % min_x)
    
# 计算平均性能、最佳性能、最差性能、方差
min_value_list = np.array(min_value_list)
min_x_list = np.array(min_x_list)
print('min value average:%.5f' % np.mean(min_value_list))
print('min value best:%.5f' % np.min(min_value_list))
print('min value worst:%.5f' % np.max(min_value_list))
print('min value variance:%.10f' % np.var(min_value_list))



