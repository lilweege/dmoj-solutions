class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        q = deque()
        cnt = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    q.append((i, j))
                elif grid[i][j] == 1:
                    cnt += 1

        depth = 0
        while q:
            sz = len(q)
            for _ in range(sz):
                i, j = q.popleft()
                for i, j in (i+1, j), (i-1, j), (i, j+1), (i, j-1):
                    if 0 <= i < m and 0 <= j < n and grid[i][j] == 1:
                        grid[i][j] = 2
                        cnt -= 1
                        q.append((i, j))
            depth += 1

        if cnt > 0:
            return -1
        return max(depth-1, 0)
