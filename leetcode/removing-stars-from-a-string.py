class Solution:
    def removeStars(self, s: str) -> str:
        lastCh = []
        for ch in s:
            if ch == '*':
                lastCh.pop()
            else:
                lastCh.append(ch)
        return ''.join(lastCh)