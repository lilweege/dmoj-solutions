class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        s = []
        word1 = list(word1)[::-1]
        word2 = list(word2)[::-1]
        n = len(word1) + len(word2)
        for i in range(n):
            s.append(word1.pop())
            if len(word2) > 0:
                word1, word2 = word2, word1
        return ''.join(s)