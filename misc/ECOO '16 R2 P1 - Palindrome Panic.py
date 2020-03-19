import sys
def isPalindrome(s):
	return s == s[::-1]

numCases = 1
for case in range(numCases):
	word = sys.stdin.readline()[:-1]
