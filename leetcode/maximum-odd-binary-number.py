class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        numOnes = s.count('1')
        n = len(s)
        numZeros = n - numOnes
        return '1' * (numOnes-1) + '0' * numZeros + '1'