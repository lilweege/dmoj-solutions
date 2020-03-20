import sys
input = sys.stdin.readline

def isPrime(n):
	if n <= 3:
		return n >= 2

	if n % 2 == 0 or n % 3 == 0:
		return False

	for i in range(5, int(n**0.5)+1, 6):
		if n % i == 0 or n % (i+2) == 0:
			return False

	return True

n = int(input())
for i in range(n):
	a, b = map(int, input().split())
	t = 0
	while a < b:
		if isPrime(a):
			t += 1
		a += 1
	print(t)
