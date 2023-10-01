class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip(' ')
        if len(s) == 0: return 0
        neg = False
        if s[0] == '-':
            s = s[1:]
            neg = True
        elif s[0] == '+':
            s = s[1:]
        s = s.lstrip('0')
        if len(s) == 0: return 0
        x = 0
        for ch in s:
            if not ord('0') <= ord(ch) <= ord('9'):
                break
            x = 10 * x + (ord(ch) - ord('0'))
        if neg: x = -x
        if x > (1<<31)-1: return (1<<31)-1
        if x < -(1<<31): return -(1<<31)
        return x