# -*- coding: UTF-8 -*-
"""
@File ：RL.py
@Author ：PengCheng
@Date ：2022/12/20 18:09
@Intro: RL Method
"""

import numpy as np
import pandas as pd

class RL_method():
    def __init__(self,method_name, actions, gamma=0.5, alpha=0.1, epsilon=0.01):
        self.actions = actions
        self.alpha = alpha
        self.gamma = gamma
        self.epsilon = epsilon
        self.record = pd.DataFrame(columns=self.actions, dtype=np.float64)
        self.method_name = method_name

    def greedy(self, s):
        # 给出贪心策略
        if s not in self.record.index:
            self.record = self.record.append(
                pd.Series([0] * len(self.actions), index=self.record.columns, name=s, ))
        # 行动选择
        state_action = self.record.loc[s, :]
        action = np.random.choice(state_action[state_action == np.max(state_action)].index)
        return action

    def action(self, s):
        # 给出ep-greedy策略
        if s not in self.record.index:
            self.record = self.record.append(pd.Series([0] * len(self.actions),index=self.record.columns,name=s,))
        if np.random.uniform() > self.epsilon:
            state_action = self.record.loc[s, :]
            action = np.random.choice(state_action[state_action == np.max(state_action)].index)
        else:
            action = np.random.choice(self.actions)
        return action

    def update(self, s, a, r, sp):
        # 更新表格
        if sp not in self.record.index:
            self.record = self.record.append(pd.Series([0] * len(self.actions),index=self.record.columns,name=sp,))
        q_predict = self.record.loc[s, a]
        if sp != 'terminal':
            if self.method_name == 'Sarsa':
                ap = self.action(sp)
                q_target = r + self.gamma * self.record.loc[sp, ap]
            elif self.method_name == 'QLearning':
                q_target = r + self.gamma * self.record.loc[sp, :].max()
            else:
                raise NameError('No such method name!')
        else:
            q_target = r
        self.record.loc[s, a] += self.alpha * (q_target - q_predict)

