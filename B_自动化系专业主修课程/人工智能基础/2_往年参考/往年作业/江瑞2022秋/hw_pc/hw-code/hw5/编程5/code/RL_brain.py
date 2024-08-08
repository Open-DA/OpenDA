import numpy as np
import pandas as pd


class QLearningTable:
    def __init__(self, actions, reward_decay= 0.5, learning_rate=0.1, e_greedy=0.01):
        self.actions = actions  # 当前状态下，所有可能采取的行动
        self.lr = learning_rate
        self.gamma = reward_decay # 折现因子
        self.epsilon = e_greedy # 贪心策略中，以epsilon的概率随机选择行动。
        self.q_table = pd.DataFrame(columns=self.actions, dtype=np.float64)

    def choose_action(self, observation):
        # import pdb;pdb.set_trace()
        self.check_state_exist(observation)
        # 行动选择
        if np.random.uniform() > self.epsilon:
            # 选择最优行动（或最优行动之一）
            state_action = self.q_table.loc[observation, :]
            action = np.random.choice(state_action[state_action == np.max(state_action)].index)
        else:
            # 随机选择行动
            action = np.random.choice(self.actions)
        return action

    def choose_greedy_action(self, observation):
        # import pdb;pdb.set_trace()
        self.check_state_exist(observation)
        # 行动选择
        state_action = self.q_table.loc[observation, :]
        action = np.random.choice(state_action[state_action == np.max(state_action)].index)
        return action

    def learn(self, s, a, r, s_):
        self.check_state_exist(s_)
        q_predict = self.q_table.loc[s, a]
        if s_ != 'terminal':
            q_target = r + self.gamma * self.q_table.loc[s_, :].max()
        else:
            q_target = r
        self.q_table.loc[s, a] += self.lr * (q_target - q_predict)  # 更新表格

    def check_state_exist(self, state):
        if state not in self.q_table.index:
            # 若某状态不存在于表格中，则添加
            self.q_table = self.q_table.append(
                pd.Series(
                    [0]*len(self.actions),
                    index=self.q_table.columns,
                    name=state,
                )
            )

class Sarsa:
    def __init__(self, actions, reward_decay= 0.5, learning_rate=0.1, e_greedy=0.01):
        self.actions = actions  # 当前状态下，所有可能采取的行动
        self.lr = learning_rate
        self.gamma = reward_decay # 折现因子
        self.epsilon = e_greedy # 贪心策略中，以epsilon的概率随机选择行动。
        self.q_table = pd.DataFrame(columns=self.actions, dtype=np.float64)

    def choose_action(self, observation):
        # import pdb;pdb.set_trace()
        self.check_state_exist(observation)
        # 行动选择
        if np.random.uniform() > self.epsilon:
            # 选择最优行动（或最优行动之一）
            state_action = self.q_table.loc[observation, :]
            action = np.random.choice(state_action[state_action == np.max(state_action)].index)
        else:
            # 随机选择行动
            action = np.random.choice(self.actions)
        return action

    def choose_greedy_action(self, observation):
        # import pdb;pdb.set_trace()
        self.check_state_exist(observation)
        # 行动选择
        state_action = self.q_table.loc[observation, :]
        action = np.random.choice(state_action[state_action == np.max(state_action)].index)
        return action

    def learn(self, s, a, r, s_):
        self.check_state_exist(s_)
        q_predict = self.q_table.loc[s, a]
        if s_ != 'terminal':
            ap = self.choose_action(s_)
            q_target = r + self.gamma * self.q_table.loc[s_, ap]
        else:
            q_target = r
        self.q_table.loc[s, a] += self.lr * (q_target - q_predict)  # 更新表格

    def check_state_exist(self, state):
        if state not in self.q_table.index:
            # 若某状态不存在于表格中，则添加
            self.q_table = self.q_table.append(
                pd.Series(
                    [0]*len(self.actions),
                    index=self.q_table.columns,
                    name=state,
                )
            )



if __name__ == "__main__":
    RL = QLearningTable(actions=list(range(4)))
    print(RL.q_table)