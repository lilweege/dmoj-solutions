class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        last = 0
        for x in s.split():
            try:
                x = int(x)
            except:
                continue
            if x <= last:
                return False
            last = x
        return True