"""
https://neetcode.io/problems/valid-sudoku

You are given a a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:

Each row must contain the digits 1-9 without duplicates.
Each column must contain the digits 1-9 without duplicates.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
Return true if the Sudoku board is valid, otherwise return false

Note: A board does not need to be full or be solvable to be valid.


Input: board =
[["1","2",".",".","3",".",".",".","."],
 ["4",".",".","5",".",".",".",".","."],
 [".","9","8",".",".",".",".",".","3"],
 ["5",".",".",".","6",".",".",".","4"],
 [".",".",".","8",".","3",".",".","5"],
 ["7",".",".",".","2",".",".",".","6"],
 [".",".",".",".",".",".","2",".","."],
 [".",".",".","4","1","9",".",".","8"],
 [".",".",".",".","8",".",".","7","9"]]

Output: true
"""

import collections


def valid_sudoku(board: list[list[str]]) -> bool:
    """
    This function checks if a Sudoku board is valid.

    Intuition:
    The logic behind this function is to check each row, column, and 3x3 sub-box for duplicates.
    We use sets to track the digits we've seen in each row, column, and sub-box.
    If we find a duplicate, we return False.
    If we don't find any duplicates, we return True.
    """
    rows = collections.defaultdict(set)
    cols = collections.defaultdict(set)
    squares = collections.defaultdict(set)

    # for row in board
    for r in range(len(board)):
        # for column in board
        for c in range(len(board[0])):
            # if the cell is empty, continue
            if board[r][c] == ".":
                continue
            # if the cell is not empty and the value of the cell is present in any of the sets, return False
            if (
                board[r][c] in rows[r]
                or board[r][c] in cols[c]
                or board[r][c] in squares[(r // 3, c // 3)]
            ):
                return False
            # add the value of the cell to the sets
            rows[r].add(board[r][c])
            cols[c].add(board[r][c])
            # add the value of the cell to the sets
            """
            Why (r // 3, c // 3)?
            The board is 9x9, so we can divide the board into 3x3 sub-boxes.
            The sub-boxes are indexed from 0 to 2 for both the row and the column.
            So, for example, the first sub-box is (0, 0), the second is (0, 1), the third is (0, 2), and so on.
            """
            squares[(r // 3, c // 3)].add(board[r][c])
    # if we don't find any duplicates, return True
    return True


"""
ASCII Diagram for the logic:

Initial Board:
[
 ["5",".",".",".","6",".",".",".","4"],
 [".",".",".","8",".","3",".",".","5"],
 ["7",".",".",".","2",".",".",".","6"],
 [".",".",".",".",".",".","2",".","."],
 [".",".",".","4","1","9",".",".","8"],
 [".",".",".",".","8",".",".","7","9"]
]

+---+---+---+   +---+---+---+   +---+---+---+
| 5 | . | . |   | . | 6 | . |   | . | . | 4 |
+---+---+---+   +---+---+---+   +---+---+---+
| . | . | . |   | 8 | . | 3 |   | . | . | 5 |
+---+---+---+   +---+---+---+   +---+---+---+
| 7 | . | . |   | . | 2 | . |   | . | . | 6 |
+---+---+---+   +---+---+---+   +---+---+---+

+---+---+---+   +---+---+---+   +---+---+---+
| . | . | . |   | . | . | . |   | 2 | . | . |
+---+---+---+   +---+---+---+   +---+---+---+
| . | . | . |   | 4 | 1 | 9 |   | . | . | 8 |
+---+---+---+   +---+---+---+   +---+---+---+
| . | . | . |   | . | 8 | . |   | . | 7 | 9 |
+---+---+---+   +---+---+---+   +---+---+---+

Explanation:
- Each 3x3 sub-box is visually separated to show how the board is divided.
- The logic checks each row, column, and sub-box for duplicates.
- If a duplicate is found in any row, column, or sub-box, the board is invalid.
- If no duplicates are found, the board is valid.
"""

if __name__ == "__main__":
    print(
        valid_sudoku(
            [
                ["5", ".", ".", ".", "6", ".", ".", ".", "4"],
                [".", ".", ".", "8", ".", "3", ".", ".", "5"],
                ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
                [".", ".", ".", ".", ".", ".", "2", ".", "."],
                [".", ".", ".", "4", "1", "9", ".", ".", "8"],
                [".", ".", ".", ".", "8", ".", ".", "7", "9"],
            ]
        )
    )
    print(
        valid_sudoku(
            [
                ["1", "2", ".", ".", "3", ".", ".", ".", "."],
                ["4", ".", ".", "5", ".", ".", ".", ".", "."],
                [".", "9", "1", ".", ".", ".", ".", ".", "3"],
                ["5", ".", ".", ".", "6", ".", ".", ".", "4"],
                [".", ".", ".", "8", ".", "3", ".", ".", "5"],
                ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
                [".", ".", ".", ".", ".", ".", "2", ".", "."],
                [".", ".", ".", "4", "1", "9", ".", ".", "8"],
                [".", ".", ".", ".", "8", ".", ".", "7", "9"],
            ]
        )
    )
