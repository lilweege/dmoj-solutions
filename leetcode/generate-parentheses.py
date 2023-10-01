class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def dfs(s, x, y):
            if x == 0 and y == 0:
                yield s
            else:
                if x >= 1:
                    yield from dfs(s+"(", x-1, y)
                if y >= 1 and y > x:
                    yield from dfs(s+")", x, y-1)

        return list(dfs("", n, n))