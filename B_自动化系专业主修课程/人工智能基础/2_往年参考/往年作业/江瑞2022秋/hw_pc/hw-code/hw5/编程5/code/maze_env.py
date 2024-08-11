import numpy as np
import time
import sys
if sys.version_info.major == 2:
    import Tkinter as tk
    from Tkinter import PhotoImage
else:
    import tkinter as tk
    from tkinter import PhotoImage


UNIT = 100   # 迷宫中每个格子的像素大小
MAZE_H = 5  # 迷宫的高度（格子数）
MAZE_W = 5  # 迷宫的宽度（格子数）


class Maze(tk.Tk, object):
    def __init__(self):
        super(Maze, self).__init__()
        self.action_space = ['u', 'd', 'l', 'r'] # 决策空间
        self.n_actions = len(self.action_space)
        self.title('Q-learning')
        self.geometry('{0}x{1}'.format(MAZE_H * UNIT, MAZE_H * UNIT))
        self._build_maze()

    def _build_maze(self):
        """
        迷宫初始化
        """
        self.canvas = tk.Canvas(self, bg='white',
                           height=MAZE_H * UNIT,
                           width=MAZE_W * UNIT)

        for c in range(0, MAZE_W * UNIT, UNIT):
            x0, y0, x1, y1 = c, 0, c, MAZE_H * UNIT
            self.canvas.create_line(x0, y0, x1, y1)
        for r in range(0, MAZE_H * UNIT, UNIT):
            x0, y0, x1, y1 = 0, r, MAZE_W * UNIT, r
            self.canvas.create_line(x0, y0, x1, y1)

        origin = np.array([UNIT/2, UNIT/2])
        
        self.bm_trap = PhotoImage(file="trap.png")
        self.trap1 = self.canvas.create_image(origin[0]+UNIT * 2, origin[1]+UNIT,image=self.bm_trap)
        self.trap2 = self.canvas.create_image(origin[0]+UNIT, origin[1]+UNIT * 2,image=self.bm_trap)

        self.bm_mouse = PhotoImage(file="mouse.png")
        self.mouse = self.canvas.create_image(origin[0], origin[1],image=self.bm_mouse)

        self.bm_cheese = PhotoImage(file="cheese.png")
        self.cheese = self.canvas.create_image(origin[0]+2*UNIT, origin[1]+2*UNIT,image=self.bm_cheese)

        self.canvas.pack()

    def reset(self):
        self.update()
        time.sleep(0.5)
        self.canvas.delete(self.mouse)
        origin = np.array([UNIT/2, UNIT/2])
        
        self.mouse = self.canvas.create_image(origin[0], origin[1],image=self.bm_mouse)
        # 返回当前老鼠所在的位置
        return self.canvas.coords(self.mouse)

    def step(self, action):
        s = self.canvas.coords(self.mouse)
        base_action = np.array([0, 0])
        wall = 0
        if action == 0:   # 向上移动
            if s[1] > UNIT:
                base_action[1] -= UNIT
            else:
                wall = 1
        elif action == 1:   # 向下移动
            if s[1] < (MAZE_H - 1) * UNIT:
                base_action[1] += UNIT
            else:
                wall = 1
        elif action == 2:   # 向右移动
            if s[0] < (MAZE_W - 1) * UNIT:
                base_action[0] += UNIT
            else:
                wall = 1
        elif action == 3:   # 向左移动
            if s[0] > UNIT:
                base_action[0] -= UNIT
            else:
                wall = 1

        self.canvas.move(self.mouse, base_action[0], base_action[1])  # 在图形化界面上移动老鼠
        s_ = self.canvas.coords(self.mouse)

        # 回报函数
        if s_ == self.canvas.coords(self.cheese):
            reward = 10
            done = True
            s_ = 'terminal'
        elif s_ in [self.canvas.coords(self.trap1), self.canvas.coords(self.trap2)]:
            reward = -5
            done = True
            s_ = 'terminal'
        else:
            reward = -1
            done = False

        if wall==1:
            reward = -2

        return s_, reward, done

    def render(self,t=0.1):
        time.sleep(t)
        self.update()


def update():
    # 更新图形化界面
    for t in range(10):
        s = env.reset()
        while True:
            env.render()
            a = 1
            s, r, done = env.step(a)
            if done:
                break

if __name__ == '__main__':
    env = Maze()
    env.after(100, update) # 弄个一直往下走的例子
    env.mainloop()