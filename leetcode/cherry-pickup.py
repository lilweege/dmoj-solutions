def solve(grid):
    n = len(grid)
    cell_ok = lambda i, j: 0 <= i < n and 0 <= j < n and grid[i][j] != -1

    @cache
    def dfs(i1=0, j1=0, i2=0):
        # Optimization based on the fact that one of the four parameters can
        # always be deduced by the other three and the fact that the depth of
        # both paths is always the same. This improves runtime from n^4 to n^3.
        depth = i1 + j1
        j2 = depth - i2

        if not (cell_ok(i1, j1) and cell_ok(i2, j2)):
            return -float('inf')

        if (i1, j1) == (i2, j2) == (n-1, n-1):
            return grid[n-1][n-1]

        # Only count an ore once if both paths reach it at the same time
        ores = grid[i1][j1]
        if (i1, j1) != (i2, j2):
            ores += grid[i2][j2]

        return ores + max(
            dfs(i1, j1+1, i2),
            dfs(i1, j1+1, i2+1),
            dfs(i1+1, j1, i2),
            dfs(i1+1, j1, i2+1))

    # Run DFS from the base (0, 0) to the target (n-1, n-1), two times,
    # simultaneously. The catch is that each ore can only be used by at most
    # one of the two paths. This is ensured because both paths will always have
    # taken the same number of steps (the current depth of the traversal).
    max_ores = dfs()
    if max_ores < 0:
        return 0
    return max_ores

class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        return solve(grid)