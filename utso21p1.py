from math import *
import sys
input = sys.stdin.readline

# https://oeis.org/A000982
def s(n):
	n -= 1
	m = n % 2
	if m == 1:
		return floor(sqrt(2 * n))
	else:
		return floor(sqrt(2 * n - m))

n = int(input())
print(s(n))