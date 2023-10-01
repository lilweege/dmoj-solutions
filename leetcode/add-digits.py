class Solution:
    def addDigits(self, num: int) -> int:
        while len(str(num)) > 1:
            num = sum(ord(x)-ord('0') for x in str(num))
        return num