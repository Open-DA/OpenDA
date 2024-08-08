from maze_env import Maze
from RL_brain import *
import numpy as np 



def update():
    for episode in range(100):
        # 获取老鼠的初始位置
        observation = env.reset()
        print(episode)

        while True:
            # 刷新迷宫
            env.render(t=0.001)

            # 根据当前状态，基于你的策略，选择下一步的行动
            action = RL.choose_action(str(observation))

            # 移动老鼠，获取该行动的回报，及移动后的状态
            observation_, reward, done = env.step(action)

            # 更新RL算法策略
            RL.learn(str(observation), action, reward, str(observation_))

            # 更新当前状态
            observation = observation_

            # 若达到了迭代终止条件则结束算法迭代
            if done:
                break

    # 游戏结束，退出游戏
    print('game over')
    env.destroy()

def mtest():
    observation = env.reset()
    while True:
        # 刷新迷宫
        env.render(t=1)
        # 根据当前状态，基于你的策略，选择下一步的行动
        action = RL.choose_greedy_action(str(observation))
        # 移动老鼠，获取该行动的回报，及移动后的状态
        observation_, reward, done = env.step(action)
        # 更新RL算法策略
        RL.learn(str(observation), action, reward, str(observation_))
        # 更新当前状态
        observation = observation_
        # 若达到了迭代终止条件则结束算法迭代
        if done:
            break

    # 游戏结束，退出游戏
    print('game over')
    env.destroy()



if __name__ == "__main__":
    env = Maze() # 创建迷宫
    #RL = QLearningTable(actions=list(range(env.n_actions)))
    RL = Sarsa(actions=list(range(env.n_actions)))
    MAX_STEPS = 100 # 最大迭代步数
    env.after(MAX_STEPS, update)
    env.mainloop()
    print(RL.q_table)
    input()
    env = Maze()  # 创建迷宫
    env.after(MAX_STEPS, mtest)
    env.mainloop()