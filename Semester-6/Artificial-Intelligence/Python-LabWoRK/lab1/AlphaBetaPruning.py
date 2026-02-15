import time

class TicTacToe:
    def __init__(self):
        self.current_state = [['.' for _ in range(3)] for _ in range(3)]
        self.player_turn = 'X'
        self.result = None

    # -----------------------------
    # CHECK END STATE
    # -----------------------------
    def is_end(self):
        # Row
        for i in range(3):
            if self.current_state[i][0] == self.current_state[i][1] == self.current_state[i][2] != '.':
                return self.current_state[i][0]

        # Column
        for j in range(3):
            if self.current_state[0][j] == self.current_state[1][j] == self.current_state[2][j] != '.':
                return self.current_state[0][j]

        # Diagonal
        if self.current_state[0][0] == self.current_state[1][1] == self.current_state[2][2] != '.':
            return self.current_state[0][0]

        if self.current_state[0][2] == self.current_state[1][1] == self.current_state[2][0] != '.':
            return self.current_state[0][2]

        # Empty → Not ended
        for row in self.current_state:
            if '.' in row:
                return None

        return '.'  # Draw

    # -----------------------------
    # VALID MOVE
    # -----------------------------
    def is_valid(self, x, y):
        return 0 <= x < 3 and 0 <= y < 3 and self.current_state[x][y] == '.'

    # -----------------------------
    # DISPLAY BOARD
    # -----------------------------
    def draw_board(self):
        for row in self.current_state:
            print(" ".join(row))
        print()

    # -----------------------------
    # RESET GAME
    # -----------------------------
    def initialize_game(self):
        self.current_state = [['.' for _ in range(3)] for _ in range(3)]
        self.player_turn = 'X'
        self.result = None

    # -----------------------------
    # MAX PLAYER (AI = O)
    # -----------------------------
    def max_alpha_beta(self, alpha, beta):
        maxv = -2
        px = None
        py = None

        result = self.is_end()
        if result == 'X': return (-1, 0, 0)
        if result == 'O': return (1, 0, 0)
        if result == '.': return (0, 0, 0)

        for i in range(3):
            for j in range(3):
                if self.current_state[i][j] == '.':
                    self.current_state[i][j] = 'O'
                    (m, _, _) = self.min_alpha_beta(alpha, beta)

                    if m > maxv:
                        maxv = m
                        px = i
                        py = j

                    self.current_state[i][j] = '.'

                    if maxv >= beta:
                        return (maxv, px, py)

                    if maxv > alpha:
                        alpha = maxv

        return (maxv, px, py)

    # -----------------------------
    # MIN PLAYER (HUMAN = X)
    # -----------------------------
    def min_alpha_beta(self, alpha, beta):
        minv = 2
        qx = None
        qy = None

        result = self.is_end()
        if result == 'X': return (-1, 0, 0)
        if result == 'O': return (1, 0, 0)
        if result == '.': return (0, 0, 0)

        for i in range(3):
            for j in range(3):
                if self.current_state[i][j] == '.':
                    self.current_state[i][j] = 'X'
                    (m, _, _) = self.max_alpha_beta(alpha, beta)

                    if m < minv:
                        minv = m
                        qx = i
                        qy = j

                    self.current_state[i][j] = '.'

                    if minv <= alpha:
                        return (minv, qx, qy)

                    if minv < beta:
                        beta = minv

        return (minv, qx, qy)

    # -----------------------------
    # MAIN GAME LOOP
    # -----------------------------
    def play_alpha_beta(self):
        while True:
            self.draw_board()
            self.result = self.is_end()

            if self.result is not None:
                if self.result == 'X':
                    print("The winner is X!")
                elif self.result == 'O':
                    print("The winner is O!")
                else:
                    print("It's a tie!")
                
                self.initialize_game()
                return

            if self.player_turn == 'X':

                while True:
                    start = time.time()
                    (m, qx, qy) = self.min_alpha_beta(-2, 2)
                    end = time.time()

                    print("Evaluation time: {}s".format(round(end - start, 7)))
                    print("Recommended move: X = {}, Y = {}".format(qx, qy))

                    px = int(input("Insert the X coordinate (0–2): "))
                    py = int(input("Insert the Y coordinate (0–2): "))

                    if self.is_valid(px, py):
                        self.current_state[px][py] = 'X'
                        self.player_turn = 'O'
                        break
                    else:
                        print("Invalid move! Try again.")

            else:
                (m, px, py) = self.max_alpha_beta(-2, 2)
                self.current_state[px][py] = 'O'
                self.player_turn = 'X'


# -----------------------------
# RUN GAME
# -----------------------------
game = TicTacToe()
game.play_alpha_beta()
