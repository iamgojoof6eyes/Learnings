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
Computer = random.choice(ran)

while True:
    try:
        x = int(input("Tell me how many rounds you want to play"))
        if not x:
            print("Can't be 0")
        else:
            break
    except ValueError:
        print("Should be natural number")

while True:
    Player = input("Now it's your turn....choose one...Hit R for Rock, Hit P for Paper, hit S for scisor. ")
    player = Player.upper()
    if player not in ["S","P","R"]:
        print("Choices availabel\ns : Stone\np : Pape\n s : Scissor")
    else:
        break

i = x
y = []
while x:
    print("\n")
    print(f"Round {i-x+1}")
    print('Computer is choosing one value.....')
    
    
    print(f'Computer has choosen {Computer}')
    print(f'You have choosen {Player}')
    
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
l = len(y)
for a in y:
    z = f"So here are the Results:\nRound{len(y)-l + 1} : {a}"

    print(z)
y.clear
