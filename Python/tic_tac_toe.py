"""
Code for tic tac toe game
"""

import sys
from random import choice

# test = [
#     [" ","P1","P2"],
#     ["P2"," ", " "],
#     ["P1","P2"," "]
# ]


class TicTacToe:
    """Class for the Tic Tac Toe game"""

    def __init__(self, is_computer: str or bool) -> None:
        """To store few important stuffs"""
        self.player_dict = {
            "P1": "X",
            "P2": "O"
        }
        self.matrix = [
            [" ", " ", " "],
            [" ", " ", " "],
            [" ", " ", " "]
        ]
        self.computer = is_computer
        self.turn = "P1"

    def print_board(self, particular_row: int = 0):
        """
        Function to print current board

        matrix: Matrix of the current stats
        particular_row: If you want to get particular row
        """
        matrix = self.matrix
        if particular_row:
            elements = [self.player_dict.get(i, ' ')
                        for i in matrix[particular_row-1]]
            board = "|".join(elements)
        else:
            board = ""
            num = 1
            for i in matrix:
                lines = ""
                for j in i:
                    if not lines:
                        lines += f" {self.player_dict.get(j,' ')} "
                    else:
                        lines += f"| {self.player_dict.get(j,' ')} "
                if num == 3:
                    board += lines
                else:
                    board += f"{lines}\n-----------\n"
                num += 1

        return board

    def computer_choice(self):
        """Function which will randomly choose row and column from the available places on the board"""
        _, places = self.is_available_space()
        if places:
            choosen = choice(places)
            row, column = choosen
            print(f"Computer choosen\nRow {row+1}, column {column+1}")
            self.update_board(row+1, column+1, self.computer)

    def update_board(self, row: int, column: int, to_update: str):
        """
        Function to update the current board

        :type row: int: Row where you want to put the mark
        :type column: int : Column where you want to put the mark
        :type to_update: str: Mark you want to put in the particular position 
        """
        new_matrix = self.matrix
        at_point = new_matrix[row-1][column-1]
        in_row = new_matrix[row-1]

        if at_point in ["P1", "P2"]:
            return []
        else:
            in_row.remove(at_point)
            in_row.insert(column-1, to_update)

        self.matrix = new_matrix
        if not self.computer:
            print(f"Next turn will be of player {self.turn[1:]}\n")
        else:
            print("Next turn will be of computer\n")

    def is_available_space(self):
        """Function to check the available spaces"""
        matrix = self.matrix
        available = 0
        places = []
        row = 0
        for i in matrix:
            column = 0
            for j in i:
                if j == " ":
                    places.append((row, column))
                    available += 1
                column += 1
            row += 1

        return available, places

    def get_results(self):
        """Function to decide the results"""
        matrix = self.matrix
        win = False
        for i, sub_list in enumerate(matrix):
            is_solo = set(sub_list)
            if len(is_solo) == 1 and is_solo != {" "}:
                win = list(is_solo)[0]
            if not i:
                for j, element in enumerate(sub_list):
                    if not j:
                        is_solo = {element, matrix[i+1][j+1], matrix[i+2][j+2]}
                        is_solo2 = {element, matrix[i+1][j], matrix[i+2][j]}
                        if (len(is_solo) == 1 or len(is_solo2) == 1) and is_solo != {" "}:
                            win = list(is_solo)[0]
                            if win == " ":
                                win = list(is_solo2)[0]
                    elif j == 2:
                        is_solo = {element, matrix[i+1][j-1], matrix[i+2][j-2]}
                        is_solo2 = {element, matrix[i+1][j], matrix[i+2][j]}
                        if len(is_solo) == 1 and is_solo != {" "}:
                            win = list(is_solo)[0]
                            if win == " ":
                                win = list(is_solo2)[0]
                    else:
                        is_solo = {element, matrix[i+1][j], matrix[i+2][j]}
                        if len(is_solo) == 1 and is_solo != {" "}:
                            win = list(is_solo)[0]
        return win

    def get_winner(self):
        """Function to get winner of the game"""
        blank_space, _ = game_class.is_available_space()

        winner = self.get_results()

        if not blank_space or winner:
            board = self.print_board()
            if not winner:
                print("Looks like it's an tie...\n\n")
                print(f"Current board:\n{board}")
                return True
            elif comp and winner == "P2":
                print("You lost the game.\n\n")
                print(f"Current board:\n{board}")
                return True
            elif comp and winner == "P1":
                print("Congratulations! You (somehow) manged to win the game.\n")
                print(f"Current board:\n{board}")
                return True
            else:
                print(f"Player {winner[1:]} won this game.\n\n")
                print(f"Current board:\n{board}")
                return True
        return False

    def get_available_command(self, cmd=None):
        """
        Function to get the commands
        cmd: Command you want to fetch or else none
        """
        txt = """
■ How: Will explain how to play the game.
■ Board: WIll print the current board.
■ Reset/Stop: Will stop the game.

All commands are case insensetive, it will not matter if you type them in small or capital
        """
        if not cmd:
            print(txt)
        elif cmd.lower() == "how":
            txt = """
As you have played tic tac toe this is same as that you have to just choose where you want to mark.
You can either play against player or you can also play against the computer.

Enjoy playing! XD
            """
            print(txt)
        elif cmd.lower() == "board":
            print(self.print_board())

        else:
            print("Stopping the game...")
            sys.exit(1)


is_computer = input(
    "Enter P if you want to play against a player, if you want to play against computer hit enter or enter anything: ")

if is_computer and is_computer.lower() == "p":
    comp = False
else:
    comp = "P2"
    mark = print("You are player 1 now...your sign is X")


cmds = ["how", "board", "reset", "stop"]

game_class = TicTacToe(comp)

print("You can send cmd anytime to get somehelp and list of available commands")

bound = [1, 2, 3]

while True:
    print("Current board:\n\n")
    print(game_class.print_board())
    print("\n")

    if comp and game_class.turn == "P2":
        print("Please wait computer is playing...\n")
        game_class.computer_choice()
        print("Now it's your turn")

    else:
        def is_valid(row):
            row = set(game_class.matrix[row-1])
            players = {"P1", "P2"}
            space = row-players
            return bool(len(space))

        print(f"Player {game_class.turn[1]} it's your turn\n")

        def select_row():
            while True:
                try:
                    in_put = input(
                        f"\nRow should be integer between 1 to 3\nYou can send cmd to get list of commands\nIn which row you want to put your mark? ")
                    row = int(in_put)
                    if is_valid(row):
                        back_ = input(
                            "\nType back to revert your change or else hit enter to continue ")
                        if back_.lower() == "back":
                            pass
                        else:
                            break
                    elif row not in bound:
                        print("\nYou can only choose between 1 to 3")
                    else:
                        print("\nThis row is already filled try another row\n")
                except ValueError:
                    if in_put.lower() == "cmd":
                        game_class.get_available_command()
                    elif in_put.lower() in cmds:
                        game_class.get_available_command(in_put.lower())
                    else:
                        print("Row should be integer between 1 to 3")
            return row

        row = select_row()

        print("\n")
        print(
            f"Here are the marked column in the row you have choosen\n{game_class.print_board(row)}\n\n")

        while True:
            try:
                column = int(input(
                    f"\nColumn should be integer between 1 to 3\nIn which column you want to put your mark? "))
                elem = game_class.matrix[row-1][column-1]
                if elem == " ":
                    break
                elif column not in bound:
                    print("\nYou can only choose between 1 to 3")
                else:
                    print(
                        "\nAre you blind or what?! This column is already filled try another column\n")
            except ValueError:
                print("\nColumn should be integer between 1 to 3")

        game_class.update_board(row, column, game_class.turn)
    game_class.turn = "P2" if game_class.turn == "P1" else "P1"
    is_finish = game_class.get_winner()
    if is_finish:
        break
