class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        currBoard = [[0]*n for _ in range(n)]
        nextBoard = [[0]*n for _ in range(n)]
        nextBoard[row][column] = 1

        def add_moves(r, c, x):
            if r >= 0 and r < n and c >= 0 and c < n:
                nextBoard[r][c] += x

        for _ in range(k):
            for r in range(n):
                for c in range(n):
                    currBoard[r][c] = nextBoard[r][c]
                    nextBoard[r][c] = 0
            for r in range(n):
                for c in range(n):
                    x = currBoard[r][c]
                    add_moves(r+1, c+2, x)
                    add_moves(r+1, c-2, x)
                    add_moves(r+2, c+1, x)
                    add_moves(r+2, c-1, x)
                    add_moves(r-1, c+2, x)
                    add_moves(r-1, c-2, x)
                    add_moves(r-2, c+1, x)
                    add_moves(r-2, c-1, x)

        tot = 0
        for r in range(n):
            for c in range(n):
                tot += nextBoard[r][c]
        return tot / (1 << (3*k))