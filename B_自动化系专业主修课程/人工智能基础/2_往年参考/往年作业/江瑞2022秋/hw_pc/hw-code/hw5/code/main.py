# -*- coding: UTF-8 -*-
"""
@File ：main.py.py
@Author ：PengCheng
@Date ：2022/12/20 18:36
@Intro: the main function
"""
from maze_env import Maze
from RL import *


def step(method,episode):
    for episode in range(episode):
        position = env.reset()
        print(episode)
        while True:
            env.render(t=0.001)
            action = method.action(str(position))
            position_,reward,end =env.step(action)
            method.update(str(position), action, reward, str(position_))
            position = position_
            if end:
                break
    print('finish')
    env.destroy()


def result_test(method,):
    position = env.reset()
    while True:
        env.render(t=1)
        action = method.greedy(str(position))
        position_,reward,end=env.step(action)
        method.update(str(position), action, reward, str(position_))
        position = position_
        if end:
            break
    print('finish')
    env.destroy()


if __name__ == "__main__":
    env = Maze()

    # 选择方法
    #method_name = 'QLearning'
    method_name = 'Sarsa'

    episode = 100
    RL = RL_method(method_name,actions=list(range(env.n_actions)))
    env.after(100, step(RL,episode))
    env.mainloop()
    print(RL.record)

    print("Greedy-Show")
    env = Maze()  # 创建迷宫
    env.after(100, result_test(RL))
    env.mainloop()