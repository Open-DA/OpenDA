import numpy as np
from copy import deepcopy
from utils import *
import time


class Node(object):  # Represents a node in a search tree
    def __init__(self, state, parent=None, action=None, path_cost=0):
        self.state = state
        self.parent = parent
        self.action = action
        self.path_cost = path_cost
        self.depth = 0
        if parent:
            self.depth = parent.depth + 1

    def child_node(self, problem, empty_pos, action):
        next_state = problem.move(self.state, empty_pos, action)
        next_node = Node(next_state, self, action,
                         problem.g(self.path_cost, self.state,
                                   action, next_state))
        return next_node

    def path(self):
        """
        Returns list of nodes from this node to the root node
        """
        node, path_back = self, []
        while node:
            path_back.append(node)
            node = node.parent
        return list(reversed(path_back))

    def prior(self, problem):
        """
        Return the priority of one node
        """
        return self.path_cost + problem.h(self.state)

    def __repr__(self):
        return "<Node {}(g={})>".format(self.state, self.path_cost)

    def __lt__(self, other):
        return self.path_cost < other.path_cost

    def __eq__(self, other):
        return self.state == other.state


class Problem(object):
    def __init__(self, init_state=None, goal_state=None):
        self.init_state = Node(init_state)
        self.goal_state = Node(goal_state)

    def actions(self, state):
        """
        Given the current state, return valid actions.
        :param state:
        :return: valid actions
        """
        pass

    def move(self, state, action):
        pass

    def is_goal(self, state):
        pass

    def g(self, cost, from_state, action, to_state):
        return cost + 1

    def solution(self, goal):
        """
        Returns actions from this node to the root node
        """
        if goal.state is None:
            return None
        return [node.action for node in goal.path()[1:]]

    def expand(self, node):  # Returns a list of child nodes
        return [node.child_node(self, action, pos) for action, pos in self.actions(node.state)]


class GridsProblem(Problem):
    def __init__(self,
                 n,
                 init_state=[[1, 1, 1, 0],
                             [2, 1, 1, 2],
                             [2, 0, 1, 2],
                             [1, 2, 2, 2]],
                 goal_state=[[1, 1, 1, 1],
                             [1, 1, 1, 0],
                             [2, 2, 2, 0],
                             [2, 2, 2, 2]]):
        super().__init__(init_state, goal_state)
        self.n = n

    def is_valid(self, loc):
        """
        giving whether a pos is valid
        """
        if -1 < loc[0] < self.n and -1 < loc[1] < self.n:
            return True
        else:
            return False

    def actions(self, state):
        """
        giving list of empty pos and movable car
        """
        empty_index_list = np.argwhere(np.array(state) == 0)
        valid_candidates = []
        for empty_row, empty_col in empty_index_list:
            candidates = [[empty_row - 1, empty_col], [empty_row + 1, empty_col],
                          [empty_row, empty_col - 1], [empty_row, empty_col + 1]]
            valid_candidates += [[item, [empty_row, empty_col]] for item in candidates if self.is_valid(item)]
        return valid_candidates

    def move(self, state, empty_pos, action):
        """
        given the pos of car to exchange
        """
        new_state = deepcopy(state)
        new_state[empty_pos[0]][empty_pos[1]] = state[action[0]][action[1]]
        new_state[action[0]][action[1]] = 0
        return new_state

    def is_goal(self, state):
        """
        giving whether the state is goal
        """
        return state == self.goal_state.state

    def g(self, cost, from_state, action, to_state):
        return cost + 1

    def h(self, state):
        """
            cost predict function
            input: two matrix
            output: a predicted distance
        """
        goal = self.goal_state.state
        bike = np.argwhere(np.array(state) == 1)
        bike_g = np.argwhere(np.array(goal) == 1)
        h_bike = np.absolute(np.sum(bike, axis=0) - np.sum(bike_g, axis=0))
        h_bike = np.sum(h_bike)

        ebike = np.argwhere(np.array(state) == 2)
        ebike_g = np.argwhere(np.array(goal) == 2)
        h_ebike = np.absolute(np.sum(ebike, axis=0) - np.sum(ebike_g, axis=0))
        h_ebike = np.sum(h_ebike)

        return h_bike + h_ebike


def search_with_info(problem):
    """
    YOUR CODE HERE
    """
    print("有信息搜索。")
    # 思路 A*搜索，用优先队列和一个列表
    # 优先级： F = G（移动代价） + H（预估代价）

    # 维护一些初始化的信息
    parking = problem
    node_start = parking.init_state
    node_end = parking.goal_state
    pqu = PriorityQueue(node_start, parking)
    close = []

    # 开始A*搜索
    while not pqu.empty():
        node = pqu.pop()
        state = node.state
        close.append(state)
        actions = parking.actions(state)
        for action in actions:
            target, empty_pos = action[0], action[1]
            new_node = node.child_node(parking, empty_pos, target)
            if new_node == node_end:
                return new_node
            if new_node.state not in close and pqu.find(new_node) is None:
                # print(f'depth:{new_node.depth}')
                pqu.push(new_node)

    return 0


def search_without_info(problem):
    """
    YOUR CODE HERE
    """
    print("无信息搜索")
    # 思路，广度优先搜索，维护一个队列和一个列表
    qu = Queue()
    close = []

    # 维护一些初始化的信息
    parking = problem
    node_start = parking.init_state
    node_end = parking.goal_state
    qu.push(node_start)

    # 开始广度优先搜索
    while not qu.empty():
        node = qu.pop()
        state = node.state
        close.append(state)
        actions = parking.actions(state)
        for action in actions:
            target, empty_pos = action[0], action[1]
            new_node = node.child_node(parking, empty_pos, target)
            if new_node == node_end:
                return new_node
            if new_node.state not in close and qu.find(new_node) is None:
                # print(f'depth:{new_node.depth}')
                qu.push(new_node)

    return 0

def search_with_info_pro(problem):
    """
    相比于非pro版本，此版本的查找都是hash的
    """
    print("有信息搜索-hash")
    # 思路 A*搜索，用优先队列和一个列表
    # 优先级： F = G（移动代价） + H（预估代价）
    # 维护一些初始化的信息
    parking = problem
    node_start = parking.init_state
    node_end = parking.goal_state
    pqu = PriorityQueue(node_start, parking)
    close = Set()
    open = Set()
    open.add(np.array(node_start.state).tobytes())
    # 开始A*搜索
    while not pqu.empty():
        node = pqu.pop()
        state = node.state
        str_state = np.array(state).tobytes()  # tobytes enables hash
        open.remove(str_state)
        close.add(str_state)
        actions = parking.actions(state)
        for action in actions:
            target, empty_pos = action[0], action[1]
            new_node = node.child_node(parking, empty_pos, target)
            if new_node == node_end:
                return new_node
            if not close.find(np.array(new_node.state).tobytes()) and not open.find(np.array(new_node.state).tobytes()):
                pqu.push(new_node)
                open.add(np.array(new_node.state).tobytes())

    return 0



def search_without_info_pro(problem):
    """
    相比于非pro版本，此版本的查找都是hash的
    """
    print("无信息搜索-hash")
    # 思路，广度优先搜索
    qu = Queue()
    close = Set()
    open = Set()
    # 维护一些初始化的信息
    parking = problem
    node_start = parking.init_state
    node_end = parking.goal_state
    qu.push(node_start)
    open.add(np.array(node_start.state).tobytes())
    # 开始广度优先搜索
    while not qu.empty():
        node = qu.pop()
        state = node.state
        str_state = np.array(node.state).tobytes()  # tobytes enables hash
        open.remove(str_state)
        close.add(str_state)
        actions = parking.actions(state)
        for action in actions:
            target, empty_pos = action[0], action[1]
            new_node = node.child_node(parking, empty_pos, target)
            if new_node == node_end:
                return new_node
            if not close.find(np.array(new_node.state).tobytes()) and not open.find(np.array(new_node.state).tobytes()):
                qu.push(new_node)
                open.add(np.array(new_node.state).tobytes())
    return 0


if __name__ == "__main__":
    problem = GridsProblem(4)
    node = Node(state=[[1, 1, 1, 0],
                       [2, 1, 1, 2],
                       [2, 0, 1, 2],
                       [1, 2, 2, 2]])
    # test
    result = problem.expand(node)
    print("请分别使用有信息和无信息搜索方法求解单车整理问题。")
    start_time = time.time()  # 开始时间
    res = search_without_info_pro(problem)
    # res = search_with_info_pro(problem)
    # res = search_without_info(problem)
    # res = search_with_info(problem)
    end_time = time.time()  # 结束时间

    time_cost = end_time - start_time
    print(f'time cost:{time_cost}')

    path = res.path()
    print(f'nodes change is as shown:')
    for node in path:
        print(node.state)
    print(f'depth:{res.path_cost}')
