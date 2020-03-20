import sys
input = sys.stdin.readline

def xor(n):
	m = n % 4
	if m == 0:
		return n+1
	if m == 1:
		return 0
	if m == 2:
		return n
	if m == 3:
		return 1

for _ in range(int(input())):
	s, f = map(int, input().split())
	print(xor(s-1) ^ xor(f))
