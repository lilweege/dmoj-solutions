class Solution:
    def secondHighest(self, s: str) -> int:
        ss = set(ord(c)-ord('0') for c in s if '0' <= c <= '9')
        if len(ss) <= 1:
            return -1
        return sorted(ss)[-2]