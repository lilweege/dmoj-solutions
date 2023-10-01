class Solution:
    def isPalindrome(self, s: str) -> bool:
        ss = ""
        for c in s.lower():
            if c in ascii_lowercase or c in list(map(str, range(10))):
                ss += c
        return ss == ss[::-1]