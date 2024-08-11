import numpy as np

class Node():
    def __int__(self):
        pass

    def childnode(self):
        pass

class Node(object):  # Represents a node in a search tree
    def __init__(self, state, parent=None, action=None, path_cost=0):
        self.state = state
        self.parent = parent
        self.action = action
        self.path_cost = path_cost
        self.depth = 0
        if parent:
            self.depth = parent.depth + 1

    def child_node(self, problem, action, empty_pos):
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

    def __repr__(self):
        return "<Node {}(g={})>".format(self.state, self.path_cost)

    def __lt__(self, other):
        return self.path_cost < other.path_cost

    def __eq__(self, other):
        return self.state == other.state

# BFS

# DFS

# Tracking Back

# MinConflict
