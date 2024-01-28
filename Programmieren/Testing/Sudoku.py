import random

def generate_sudoku():
    sudoku = [[0] * 9 for _ in range(9)]
    fill_sudoku(sudoku)
    return sudoku

def fill_sudoku(sudoku):
    for row in range(9):
        for col in range(9):
            if sudoku[row][col] == 0:
                numbers = list(range(1, 10))
                random.shuffle(numbers)
                for num in numbers:
                    if is_valid(sudoku, row, col, num):
                        sudoku[row][col] = num
                        if fill_sudoku(sudoku):
                            return True
                        sudoku[row][col] = 0
                return False
    return True

def is_valid(sudoku, row, col, num):
    for i in range(9):
        if sudoku[row][i] == num or sudoku[i][col] == num:
            return False
    start_row = (row // 3) * 3
    start_col = (col // 3) * 3
    for i in range(3):
        for j in range(3):
            if sudoku[start_row + i][start_col + j] == num:
                return False
    return True

sudoku = generate_sudoku()
for i, row in enumerate(sudoku):
    if i % 3 == 0 and i != 0:
        print("- - - - - - - - - - - -")
    for j, num in enumerate(row):
        if j % 3 == 0 and j != 0:
            print("| ", end="")
        print(num, end=" ")
    print()

