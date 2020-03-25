'''
import sys
import math

for _ in range(int(sys.stdin.readline())):
	num = int(sys.stdin.readline())
	print(0 if num > 33 else math.factorial(num)%(2**32))
'''
import sys
input = sys.stdin.readline
hardcode_lol = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 1932053504, 1278945280, 2004310016, 2004189184, 4006445056, 3396534272, 109641728, 2192834560, 3099852800, 3772252160, 862453760, 3519021056, 2076180480, 2441084928, 1484783616, 2919235584, 3053453312, 1409286144, 738197504, 2147483648, 2147483648]
N = int(input())
for i in range(N):
	n = int(input())
	print(0 if n > 33 else hardcode_lol[n])
