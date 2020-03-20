import sys
import math

for _ in range(int(sys.stdin.readline())):
    num = int(sys.stdin.readline())
    print(0 if num > 33 else math.factorial(num)%(2**32))
