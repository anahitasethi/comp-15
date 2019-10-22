def find_empty(board,loc): 
    for row in range(9): 
        for col in range(9): 
            if(board[row][col]==0): 
                loc[0]=row 
                loc[1]=col 
                return True
    return False

def used_in_row(board,row,num): 
    for i in range(9): 
        if(board[row][i] == num): 
            return True
    return False
  
def used_in_col(board,col,num): 
    for i in range(9): 
        if(board[i][col] == num): 
            return True
    return False

def used_in_box(board,row,col,num): 
    for i in range(3): 
        for j in range(3): 
            if(board[i+row][j+col] == num): 
                return True
    return False

def check_solved(board,row,col,num): 
    return not used_in_row(board,row,num) and not used_in_col(board,col,num) and not used_in_box(board,row - row%3,col - col%3,num) 

def solve_sudoku(board): 
        
    loc=[0,0] 
 
    if(not find_empty(board,loc)): 
        return True

    row=loc[0] 
    col=loc[1] 
      
    for num in range(1,10): 
          
        if(check_solved(board,row,col,num)): 
            board[row][col]=num 
            if(solve_sudoku(board)): 
                return True
            board[row][col] = 0
       
    return False 


#Print end: https://stackoverflow.com/questions/2456148/python-print-end 
def print_sudoku_board(board):
    print('--------+-------+--------', end='')
    for i in range(0, 9):
        print('\n|', end=' ')
        for j in range(0, 9):
            if (board[i][j] == 0):
                print('-', end=' ')
            else:
                print(board[i][j], end=' ')
            if (j% 3 == 2):
                print('|', end=' ')
        if (i % 3 == 2):
            print('\n--------+-------+--------', end='')
    print('')

if __name__=="__main__": 
      
    grid=[[0 for i in range(9)]for j in range(9)] 

    user_input = input('Type easy if you want to solve the easy puzzle and evil if you want to solve a more challenging one\n')
    if user_input == 'easy':
        grid = [[6,0,8,7,0,2,1,0,0], 
                [4,0,0,0,1,0,0,0,2], 
                [0,2,5,4,0,0,0,0,0], 
                [7,0,1,0,8,0,4,0,5], 
                [0,8,0,0,0,0,0,7,0], 
                [5,0,9,0,6,0,3,0,1], 
                [0,0,0,0,0,6,7,5,0], 
                [2,0,0,0,9,0,0,0,8], 
                [0,0,6,8,0,5,2,0,3]] 

    elif user_input == 'evil':
        grid=[[0,7,0,0,4,2,0,0,0], 
              [0,0,0,0,0,8,6,1,0], 
              [3,9,0,0,0,0,0,0,7], 
              [0,0,0,0,0,4,0,0,9], 
              [0,0,3,0,0,0,7,0,0], 
              [5,0,0,1,0,0,0,0,0], 
              [8,0,0,0,0,0,0,7,6], 
              [0,5,4,8,0,0,0,0,0], 
              [0,0,0,6,1,0,0,5,0]] 

    if(solve_sudoku(grid)): 
        print_sudoku_board(grid) 
    else: 
        print('No solution exists')
  