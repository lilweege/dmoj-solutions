class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        # return''.join((Counter(t)-Counter(s)).keys())
        return chr(sum(map(ord,t))-sum(map(ord,s)))
