class Solution:
    def bulbSwitch(self, n: int) -> int:
        # Number of perfect squares less than n
        return floor(sqrt(n))