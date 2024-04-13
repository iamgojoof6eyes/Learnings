# My first ever created code which is more than 10 lines

import random


def gameWin(Computer , player): #defining the function
    if Computer == player: # Game string
        return None
    elif Computer == 'R':
        if player == 'P':
            return True
        elif player == 'S':
            return False
    elif Computer == 'P':
        if player == 'S':
            return True
        elif player == 'R':
            return False
    elif Computer == 'S':
        if player == 'R':
            return True
        elif player == 'P':
            return False


ran = ('S','R','P') 

while True:
    try:
        x = int(input("Tell me how many rounds you want to play "))
        if not x:
            print("Can't be 0")
        elif x < 0:
            print("Can't be less than or equals to 0")
        else:
            break
    except ValueError:
        print("Should be natural number")

def choices():
    Computer = random.choice(ran)
    while True:
        Player = input("Now it's your turn....choose one...\nHit R for Rock\nHit P for Paper\nHit S for scisor. ")
        player = Player.upper()
        if player not in ["S","P","R"]:
            print("Choices availabel\ns : Stone\np : Pape\n s : Scissor")
        else:
            break
    return player, Computer

i = x
y = []
while x:
    print("\n")
    print(f"Round {i-x+1}")
    print('Computer is choosing one value...\n')
    
    player, Computer = choices()
    print(f'\nComputer has choosen {Computer}\n')
    print(f'You have choosen {player}\n')
    
    win = gameWin(Computer, player)
    
    if win == None:
        print('It is a tie....')
        y.append("Tie")
    elif win == True:
        print('Congo! you win.')
        y.append("Won")
    elif win == False:
        print('You losser....I win try your luck another time.')
        y.append("Lost")
        
    x = x-1

print("\nSo here are the Results:")
for round, result in enumerate(y):
    z = f"Round{round+1} : {result}\n"
    print(z)
y.clear
