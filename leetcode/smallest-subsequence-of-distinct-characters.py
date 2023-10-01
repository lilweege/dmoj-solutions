class Solution:
    def smallestSubsequence(self, s: str) -> str:
        last_idx = {}
        for i, c in enumerate(s):
            last_idx[c] = i

        ss = []
        for i, c in enumerate(s):
            if c not in ss:
                while ss and ss[-1] > c:
                    # Greedy fails when can't pop current
                    if last_idx[ss[-1]] <= i:
                        break
                    ss.pop()

                ss.append(c)

        return ''.join(ss)