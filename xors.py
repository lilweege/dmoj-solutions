import sys
input = sys.stdin.readline
input()

maximum = minimum = 0
for num in map(int, input().split()):
	minimum ^= num
	maximum += num

print(maximum - minimum)
