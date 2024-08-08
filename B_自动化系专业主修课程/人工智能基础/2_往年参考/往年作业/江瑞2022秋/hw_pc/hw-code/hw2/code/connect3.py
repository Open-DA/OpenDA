# 游戏配置（本题无需修改）
MINIMAX_DEPTH = 3
GAME_WIDTH = 4
GAME_HEIGHT = 4


class Board:
    """
        屏风棋类
        属性:
            self.rows (int): 棋盘行数
            self.cols (int): 棋盘列数
            self.player_turn (bool): 该轮次是否为玩家下棋
            self.table (list): 电脑使用的字符（X 或者 O）
            self.border (int): 棋盘的边界长度，默认为2
            self.indexes_string (str): 棋盘底部的序号字符串
        参数:
            rows (int): 棋盘行数
            cols (int): 棋盘列数
            player_turn (bool): 是否轮到玩家下棋
        """
    def __init__(self, rows: int, cols: int, player_turn: bool):
        self.rows = rows
        self.cols = cols
        self.player_turn = player_turn
        self.table = []
        self.border = 2
        self.indexes_string = ''

        self.create_indexes_string()
        self.create_table()
        self.print_table()

    def get_char(self, digit):
        """
        根据输入数字输出对应的标记符，0为空，1为玩家棋子，2为电脑棋子
        """
        if digit == 0:
            return '_ '
        elif digit == 1:
            return 'O '
        else:
            return 'X '

    def create_indexes_string(self):
        """
        创建棋盘的行序号：0,1,2,3
        """
        ix = ''
        for x in range(self.cols):
            ix += '{nr} '.format(nr=x)
        ix += '\n'
        self.indexes_string = ix

    def create_table(self):
        """
        创建棋盘，初始默认空棋盘上全为0，即全为'_'
        """
        for row in range(self.rows + self.border):
            line = []
            for col in range(self.cols + self.border):
                line.append(-1)
            self.table.append(line)

        for row in range(1, self.rows + 1):
            for col in range(1, self.cols + 1):
                self.table[row][col] = 0

    def print_table(self):
        """
        将游戏棋盘打印输出
        """
        i_like_coffee = '==================\n'
        for row in range(1, self.rows + 1):
            for col in range(1, self.cols + 1):
                i_like_coffee += self.get_char(self.table[row][col])
            i_like_coffee += '\n'
        i_like_coffee += self.indexes_string
        print(i_like_coffee + '==================')

    def is_move_legal(self, choice: int):
        """
        检查当前下的棋子是否合法，如果合法就返回棋子停下的位置坐标，否则返回None
        choice:选择落入入口对应的列，输入为0,1,2,3
        """
        choice += 1
        for row in reversed(range(1, self.rows + 1)):
            if self.table[row][choice] == 0:
                return row, choice

        return None

    def make_move(self, choice: int):
        """
        电脑或玩家对指定列进行一步下棋操作，即改变table表中对应坐标的数值
        参数：choice代表玩家选择放入的列序号，0,1,2,3
        返回值：True表示下棋成功，否则失败
        """
        choice += 1
        legal_moves = self.get_legal_moves()
        marker = False
        for move in legal_moves:
            if choice == move[1]:
                marker = True
        if not marker:
            return False

        for row in reversed(range(1, self.rows + 1)):
            if self.table[row][choice] == 0:
                if self.player_turn:
                    self.table[row][choice] = 1
                else:
                    self.table[row][choice] = 2
                break

        self.player_turn = not self.player_turn
        return True

    def get_legal_moves(self):
        """
        获取当前游戏状态下所有可能下棋的位置坐标，具体做法是检查每一列是否可以合法放入棋子
        返回值：为所有可能棋子停下的坐标
        """
        moves = []
        for col in range(0, self.cols):
            cords = self.is_move_legal(col)
            if cords is not None:
                moves.append(cords)

        return moves

    def check_for_win(self):
        """
        检查当前游戏的获胜状态
        返回值：-1代表玩家获胜，1代表电脑获胜，0代表平局，None代表游戏尚未结束
        """
        player = -1
        enemy = 1
        tie = 0
        # 检查玩家水平连线获胜
        for row in range(1, self.rows + 1):
            hor_score = 0
            for col in range(1, self.cols + 1):
                if self.table[row][col] == 1:
                    hor_score += 1
                    if hor_score >= 3:
                        return player
                else:
                    hor_score = 0

        # 检查玩家垂直连线获胜
        for col in range(1, self.cols + 1):
            ver_score = 0
            for row in range(1, self.rows + 1):
                if self.table[row][col] == 1:
                    ver_score += 1
                    if ver_score >= 3:
                        return player
                else:
                    ver_score = 0

        # 检查玩家对焦连线获胜
        if (self.table[1][1] == 1 and self.table[2][2] == 1 and self.table[3][3] == 1) or (
                self.table[2][2] == 1 and self.table[3][3] == 1 and self.table[4][4] == 1) or (
                self.table[2][1] == 1 and self.table[3][2] == 1 and self.table[4][3] == 1) or (
                self.table[1][2] == 1 and self.table[2][3] == 1 and self.table[3][4] == 1):
            return player

        if (self.table[1][4] == 1 and self.table[2][3] == 1 and self.table[3][2] == 1) or (
                self.table[2][3] == 1 and self.table[3][2] == 1 and self.table[4][1] == 1) or (
                self.table[1][3] == 1 and self.table[2][2] == 1 and self.table[3][1] == 1) or (
                self.table[2][4] == 1 and self.table[3][3] == 1 and self.table[4][2] == 1):
            return player

        # 检查敌人水平连线获胜
        for row in range(1, self.rows + 1):
            hor_score = 0
            for col in range(1, self.cols + 1):
                if self.table[row][col] == 2:
                    hor_score += 1
                    if hor_score >= 3:
                        return enemy
                else:
                    hor_score = 0

        # 检查敌人垂直连线获胜
        for col in range(1, self.cols + 1):
            ver_score = 0
            for row in range(1, self.rows + 1):
                if self.table[row][col] == 2:
                    ver_score += 1
                    if ver_score >= 3:
                        return enemy
                else:
                    ver_score = 0

        # 检查敌人对角连线获胜
        if (self.table[1][1] == 2 and self.table[2][2] == 2 and self.table[3][3] == 2) or (
                self.table[2][2] == 2 and self.table[3][3] == 2 and self.table[4][4] == 2) or (
                self.table[2][1] == 2 and self.table[3][2] == 2 and self.table[4][3] == 2) or (
                self.table[1][2] == 2 and self.table[2][3] == 2 and self.table[3][4] == 2):
            return enemy

        if (self.table[1][4] == 2 and self.table[2][3] == 2 and self.table[3][2] == 2) or (
                self.table[2][3] == 2 and self.table[3][2] == 2 and self.table[4][1] == 2) or (
                self.table[1][3] == 2 and self.table[2][2] == 2 and self.table[3][1] == 2) or (
                self.table[2][4] == 2 and self.table[3][3] == 2 and self.table[4][2] == 2):
            return enemy

        # 如果棋盘上还有空位置，这说明游戏还没有结束，返回None
        for row in range(1, self.rows + 1):
            for col in range(1, self.cols + 1):
                if self.table[row][col] == 0:
                    return None

        # 排除以上可能后，只剩下平局可能
        return tie


class AI:
    """
    电脑玩家类，参数depth表示minimax算法的深度，默认为3
    """
    def __init__(self, depth: int = 0):
        self.depth = depth

    def best_move(self, board: Board):
        """
        根据当前棋盘状态，为AI寻找最佳的下一步
        参数：board:当前游戏棋盘的对象
        """
        best_score = -9999
        move = None
        move_scores = []

        # 得到全部的可行下一步，返回值是可能的落子坐标(row, col)
        legal_moves = board.get_legal_moves()

        # 应用minimax算法
        for pos in legal_moves:
            # 电脑尝试在pos这里下棋
            board.table[pos[0]][pos[1]] = 2
            # 求出对应的得分
            score = self.minimax(board, 0, False)
            move_scores.append(score)
            # 再复原棋盘为下次尝试做准备
            board.table[pos[0]][pos[1]] = 0
            # 利用最高分数寻找对应的路径
            if score > best_score:
                best_score = score
                move = pos[1] - 1

        return move

    # TODO: 请在此处补全minimax算法的代码
    def minimax(self, board: Board, depth, is_maximizing: bool):
        """
        board (Board): 当前棋局
        depth (int): 深度
        is_maximizing (bool): 是否为极大
        """
        return 0


def report_win():
    """
    播报游戏是否结束，结束包含玩家获胜、电脑获胜、平局三种可能
    返回值：True表示游戏结束，False表示游戏继续
    """
    winner = game.check_for_win()
    if winner is not None:
        if winner == 1:
            print('电脑获胜！')
        elif winner == -1:
            print('恭喜你获胜！')
        else:
            print('平局！')
        return True
    return False


if __name__ == '__main__':
    # 初始化棋盘
    game = Board(rows=GAME_HEIGHT, cols=GAME_WIDTH, player_turn=True)

    # 初始化电脑玩家
    AI = AI(depth=MINIMAX_DEPTH)

    # 进入游戏循环
    while not report_win():
        # 玩家下棋，输入数字i为0,1,2,3，分别对应从第i列的入口投入棋子
        while not game.make_move(int(input('玩家走棋，请输入落子位置: '))):
            print('该位置不合法，请重新输入。')
        game.print_table()

        # AI选择最有利于自己的一步
        print("电脑走棋：")
        game.make_move(AI.best_move(game))
        # 打印本轮次下棋后的结果
        game.print_table()
        
        print('\n')
