from asyncore import read
from cgitb import text
import sys
import numpy as np
from copy import deepcopy
from collections import deque
import sortedcontainers
import time
# 基本工具类
class Queue(object):
    def __init__(self):
        self._items = deque([])

    def push(self, item):
        self._items.append(item)

    def pop(self):
        return self._items.popleft() \
            if not self.empty() else None

    def empty(self):
        return len(self._items) == 0

    def find(self, item):
        return self._items.index(item) if item in self._items else None


class Stack(object):
    def __init__(self):
        self._items = list()

    def push(self, item):
        self._items.append(item)

    def pop(self):
        return self._items.pop() if not self.empty() else None

    def empty(self):
        return len(self) == 0

    def __len__(self):
        return len(self._items)


class PriorityQueue(object):

    def __init__(self, node, problem):
        self._queue = sortedcontainers.SortedList([node],key=lambda item:item.prior(problem))

    def push(self, node):
        self._queue.add(node)

    def pop(self):
        return self._queue.pop(index=0)

    def empty(self):
        return len(self._queue) == 0

    def compare_and_replace(self, i, node):
        if node < self._queue[i]:
            self._queue.pop(index=i)
            self._queue.add(node)

    def find(self, node):
        try:
            loc = self._queue.index(node)
            return loc
        except ValueError:
            return None


class Set(object):
    def __init__(self):
        self._items = set()

    def add(self, item):
        self._items.add(item)

    def remove(self, item):
        self._items.remove(item)

    def find(self,item):

        return len(set([item]) & self._items)
        # return item in self._items


class Dict(object):
    def __init__(self):
        self._items = dict()

    def add(self, key, value):
        self._items.update({key: value})

    def remove(self, key):
        self._items.pop(key, None)

    def find(self, key):
        return self._items[key] if key in self._items else None


# 游戏基本配置类
class Node(object):  # Represents a node in a search tree
    def __init__(self, state, parent=None, action=None, path_cost=0):
        self.state = state
        self.parent = parent
        self.action = action
        self.path_cost = path_cost
        self.depth = 0
        if parent:
            self.depth = parent.depth + 1

    def child_node(self, problem, action):
        next_state = problem.move(self.state,action)
        next_node = Node(next_state, self, action,self.path_cost+1)
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

    def __repr__(self):
        return "<Node {}(g={})>".format(self.state, self.path_cost)

    def __lt__(self, other):
        return self.path_cost < other.path_cost

    def __eq__(self, other):
        return self.state == other.state


class Sudoku(object):
    def __init__(self,state=None, n=4, textfile=''):
        self.n = n
        if state is not None:
            self.matrix = state
        else:
            self.matrix = self.read_file(textfile)
        # self.np_matrix = np.array(self.matrix)

    def read_file(self, textfile):
        """
        read initial puzzle from textfile
	    Args:textfile (str): name of textfile
	    Returns:List[List]: initial puzzle
	    """
        f = open(textfile, 'r')
        i, j = 0, 0
        matrix = [[0 for x in range(self.n)] for y in range(self.n)]
        while True:
            j = 0
            char = f.readline()
            for c in char:
                matrix[i][j] = int(c)
                j += 1
                if j == 4:
                    i += 1
                    break
            if i == 4:
                break
        return np.array(matrix)

    def print_puzzle(self, matrix):
        for i in range(self.n):
            print('+' + '+'.join(['---'] * 4) + '+')
            print('|' + '|'.join([' %d ' % item for item in matrix[i]]) + '|')
        print('+' + '+'.join(['---'] * 4) + '+')

    def is_valid(self, loc):
        if -1 < loc[0] < self.n and -1 < loc[1] < self.n:
            return True
        else:
            return False

    def actions(self, state):
        # return [(x,y),num]
        empty_index_list = np.argwhere(np.array(state) == 0)
        valid_candidates = []
        for empty_row, empty_col in empty_index_list:
            flag = 1
            for i in range(1,5):
                # no i in col, row and 2*2 corner then i can be candidate
                row = np.sum(state[empty_row,:] == i)
                col = np.sum(state[:,empty_col] == i)
                x = empty_row-empty_row%2
                y = empty_col-empty_col%2
                corner = np.sum(state[x:x+2,y:y+2]==i)

                if not row+col+corner:
                    flag = 0
                    valid_candidates.append([(empty_row,empty_col),i])
            # 如果1234都不行，说明死路，返回空列表
            if flag:
                return []

        return valid_candidates

    def solve(self, state):
        # return a pos with min solutions
        empty_index_list = np.argwhere(np.array(state) == 0)
        count = np.zeros(empty_index_list.shape[0])
        num_list = {}
        # print(count)
        # print(empty_index_list)
        for index, empty_pos in enumerate(empty_index_list):
            num = []
            for i in range(1, 5):
                # no i in col and row then i can be candidate
                row = np.sum(state[empty_pos[0], :] == i)
                col = np.sum(state[:, empty_pos[1]] == i)
                x = empty_pos[0] - empty_pos[0] % 2
                y = empty_pos[1] - empty_pos[1] % 2
                corner = np.sum(state[x:x + 2, y:y + 2] == i)

                if not row + col + corner:
                    num.append(i)
                    count[index] += 1
            num_list[f'{index}'] = num
        min = np.argmin(count)
        if count[min]==0:
            return (empty_index_list[min][0],empty_index_list[min][1]), []
        else:
            return (empty_index_list[min][0],empty_index_list[min][1]), num_list[f'{min}']

    def move(self, state, action):
        # return np format
        new_state = deepcopy(state)
        empty_row, empty_col = action[0]
        num = action[1]
        new_state[empty_row][empty_col] = num
        return new_state

    def is_goal(self, state):
        return not np.sum(state == 0)


# 游戏基本搜索算法
def DFS(problem):
    print("DFS Search")
    # 思路，深度优先搜索，适合用于搜一种解，不适合搜索全部解
    qu = Stack()
    open = Set()
    # 维护一些初始化的信息
    sudoku = problem
    node_start = Node(sudoku.matrix)
    qu.push(node_start)
    open.add(np.array(node_start.state).tobytes())
    # 开始深度优先搜索
    while not qu.empty():
        node = qu.pop()
        state = node.state
        actions = sudoku.actions(state)
        for action in actions:
            new_node = node.child_node(sudoku, action)
            bytestate = np.array(new_node.state).tobytes()

            if sudoku.is_goal(new_node.state):
                return new_node
            elif not open.find(bytestate):
                # print(new_node.state)
                qu.push(new_node)
                open.add(bytestate)
    print("no way")
    return 0


def BackTracking(problem):
    # 每一步查找都加入约束，找可能值最少的点进行推断
    # 每个空位可能的action数量记录一下，然后递归推断
    # 可以用于搜索所有解
    sudoku = problem
    pos,num_list = sudoku.solve(sudoku.matrix)
    solution = []
    if len(num_list)==0:
        return []
    for num in num_list:
        new_state = deepcopy(sudoku.matrix)
        new_state[pos[0],pos[1]] = num

        if sudoku.is_goal(new_state):
            solution.append(new_state)
        else:
            new_problem = Sudoku(new_state)
            solution += BackTracking(new_problem)
    return solution


def useDFS(problem):
    # 调用dfs算法并进行格式化输出
    print("Use DFS Search")
    start_time = time.time()  # 开始时间
    node = DFS(problem)
    end_time = time.time()  # 结束时间
    time_cost = end_time - start_time
    print(f'time cost:{time_cost}')
    print("Original state:")
    problem.print_puzzle(problem.matrix)
    print("Solution:")
    problem.print_puzzle(node.state.tolist())


def useBackTracking(problem):
    # 调用backtracking算法并进行格式化输出
    print("Use BackTracking Search")
    print("Original state:")
    problem.print_puzzle(problem.matrix)
    start_time = time.time()  # 开始时间
    solve = BackTracking(problem)
    end_time = time.time()  # 结束时间
    time_cost = end_time - start_time
    print(f'time cost:{time_cost}')
    if len(solve)==0:
        print("no solution")
    else:
        print(f"solution number:{len(solve)}\n")
        for i, s in enumerate(solve):
            print(f"solution {i + 1}:")
            problem.print_puzzle(s)

for i in range(1,7):
    game = Sudoku(n=4, textfile=f'test_case_{i}.txt')  # change the test case id here
    print(f'test case {i}')
    #useBackTracking(game)
    useDFS(game)





