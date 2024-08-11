## refer to https://www.writebug.com/code/0c752aa0-c792-11ed-b7ef-6479f0e5e323/src/branch/master/main_TSP.py/
## adjust the code to fit the requirement of the project

import dis
import numpy as np
import matplotlib.pyplot as plt
import random
import math

class TSP_MAP:
    def __init__(self, num_of_points=0):
        self.num_of_points = num_of_points
        self.points = None
        self.distance_matrix = None

    def calculate_distance_matrix(self):
        """ Calculate the distance matrix for the points. """
        G = np.dot(self.points, self.points.T)
        H = np.tile(np.diag(G), (self.num_of_points, 1))
        self.distance_matrix = np.sqrt(H + H.T - 2 * G)

    def random_generate(self):
        """ Generate random points and calculate the distance matrix. """
        self.points = np.random.rand(self.num_of_points, 2) * 100
        self.calculate_distance_matrix()

    def read_from_file(self, file_route):
        """ Read points from a file and calculate the distance matrix. """
        with open(file_route, 'r') as file:
            lines = file.readlines()
            self.num_of_points = int(lines[0].strip())
            self.points = np.array([list(map(float, line.strip().split())) for line in lines[1:]])

        self.calculate_distance_matrix()

    def route_distance(self, route):
        """ Calculate the total distance of a given route. """
        return sum(self.distance_matrix[route[i], route[(i + 1) % self.num_of_points]] for i in range(self.num_of_points))

    def draw_route(self, route):
        """ Draw the route using matplotlib with additional aesthetic enhancements. """
        # Scatter plot for points
        plt.scatter(*self.points.T, s=30, c='blue', edgecolor='black', alpha=0.75, zorder=2)

        # Plot lines for the route
        for i in range(self.num_of_points):
            start, end = route[i], route[(i + 1) % self.num_of_points]
            plt.plot(*self.points[[start, end]].T, color='green', linewidth=2, alpha=0.6, zorder=1)

        # Adding labels to the points
        for idx, point in enumerate(self.points):
            plt.text(point[0], point[1], str(idx), fontsize=9, ha='right', va='bottom')

        # Enhancing the aesthetics
        plt.title("TSP Route Visualization")
        plt.xlabel("X Coordinate")
        plt.ylabel("Y Coordinate")
        plt.grid(True, which='both', linestyle='--', linewidth=0.5)
        plt.xticks(fontsize=8)
        plt.yticks(fontsize=8)

        plt.tight_layout()
        plt.show()

# Note: This is a modification of the given function. 
# The function now includes enhancements like larger, colored points with borders,
# labeled points, thicker route lines, and gridlines for better visualization.
# Additionally, it includes titles and axis labels for clarity.



class SA_TSP():
    def __init__(self, TSP_MAP, T0_mode='random', route_mode='SWAP', T_annealing_mode='log'):
        self.TSP_MAP = TSP_MAP
        self.N = TSP_MAP.num_of_points
        self.T0_mode = T0_mode
        self.route_mode = route_mode
        self.T_annealing_mode = T_annealing_mode

    def init_outer_para(self, T_Lambda=0.05, T_end=0.5):
        self.T_Lambda = T_Lambda
        self.T_end = T_end

    def init_inner_para(self, T_in_step=100):
        self.T_in_step = T_in_step

    def init_T0(self):
        if self.T0_mode == 'experience':
            return 20000000
        elif self.T0_mode == 'random': # choose T0 according to the sample result
            dest_value = [self.TSP_MAP.route_distance(random.sample(range(self.N), self.N)) for _ in range(50)]
            return (max(dest_value) - min(dest_value)) / abs(math.log(0.9))

    def new_state(self, route):
        if self.route_mode == 'SWAP': # randomly swap two cities
            index1, index2 = np.random.choice(range(self.N), 2, replace=False)
            route[index1], route[index2] = route[index2], route[index1]
        elif self.route_mode == 'REVERSE': # randomly reverse a segment of the route
            index1, index2 = sorted(np.random.choice(range(self.N), 2, replace=False))
            route[index1:index2] = route[index1:index2][::-1]
        elif self.route_mode == 'INSERT': # randomly insert a segment of the route
            index1, index2, index3 = sorted(np.random.choice(range(self.N), 3, replace=False))
            temp_str = route[index1:index2]
            route[index1:index3 - index2 + index1] = route[index2:index3]
            route[index3 - index2 + index1:index3] = temp_str
        elif self.route_mode == 'RANDOM':
            route = np.random.permutation(self.N)

        return route

    def annealing(self, T, k_step):
        if self.T_annealing_mode == 'ordinary':
            return self.T_Lambda * T
        elif self.T_annealing_mode == 'log':
            return T / math.log(1 + k_step)

    def should_accept(self, E_0, E_1, t):
        return random.random() < min(1, np.exp(-(E_1 - E_0) / t))

    def optimize(self):
        T = self.init_T0()
        route_curr = np.random.permutation(self.N)
        best_route = route_curr.copy()
        D_min = self.TSP_MAP.route_distance(route_curr)
        k_step = 0
        Distances = [D_min]
        Temps = [T]

        while True:
            k_step += 1
            for _ in range(self.T_in_step):
                route_new = self.new_state(route_curr.copy())
                D_new = self.TSP_MAP.route_distance(route_new)
                if D_new < D_min:
                    best_route = route_new.copy()
                    D_min = D_new
                if self.should_accept(self.TSP_MAP.route_distance(route_curr), D_new, T):
                    route_curr = route_new

            Distances.append(D_min)
            T = self.annealing(T, k_step)
            Temps.append(T)
            if T < self.T_end:
                    break

        return best_route, Distances, Temps


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

if __name__ == '__main__':
    # build map
    TSP_MAP = TSP_MAP(30)
    TSP_MAP.random_generate()
    # random give a route
    route = np.random.permutation(TSP_MAP.num_of_points)
    # draw
    TSP_MAP.draw_route(route)

    # use SA to solve TSP
    SA_TSP = SA_TSP(TSP_MAP, T0_mode='random', route_mode='SWAP', T_annealing_mode='ordinary')
    SA_TSP.init_outer_para(T_Lambda=0.9, T_end=0.01)
    SA_TSP.init_inner_para(T_in_step=200)
    
    # now solve 20 times and get the average result
    min_value_list = []
    min_x_list = []
    dist_list = []
    temps_list = []
    for i in range(20):
        best_route, Distances, temps = SA_TSP.optimize()
        min_value_list.append(min(Distances))
        min_x_list.append(best_route)
        dist_list.append(Distances)
        temps_list.append(temps)

        print('min value:%.5f' % min(Distances))
    
    # 计算平均性能、最佳性能、最差性能、方差
    min_value_list = np.array(min_value_list)
    min_x_list = np.array(min_x_list)
    print('min value average:%.2f' % np.mean(min_value_list))
    print('min value best:%.2f' % np.min(min_value_list))
    print('min value worst:%.2f' % np.max(min_value_list))
    print('min value variance:%.2f' % np.var(min_value_list))

    # get the best route
    min_index = np.argmin(min_value_list)
    best_route = min_x_list[min_index]
    Distances = dist_list[min_index]
    temps = temps_list[min_index]

    # plot the result
    plot_results(Distances, temps)
    TSP_MAP.draw_route(best_route)

