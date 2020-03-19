import math
import sys

numPoints = 10
points = [tuple(map(int, input().split(" "))) for _ in range(numPoints)]

MAX = 10**4
sys.setrecursionlimit(MAX)
memo, memo[1] = [0]*MAX, 1

def fib(n):
	if n <= 1:
		return n

	if memo[n-1] == 0:
		memo[n-1] = fib(n-1)
	if memo[n-2] == 0:
		memo[n-2] = fib(n-2)

	memo[n] = memo[n-1] + memo[n-2]
	return memo[n]

def pointRectCollide(px, py, rx, ry, rw, rh):
	return px >= rx and px <= rx + rw and py <= ry and py >= ry - rh

fib(56)
r, b, l, t = 1, 0, 0, 0
squares = []
for i in range(1, MAX):
	# if r > 10**9:
	# 	print(i)
	# 	break

	if memo[i] == 0:
		break
	d = i%4
	if d == 0:
		r += memo[i]
	elif d == 1:
		b -= memo[i]
	elif d == 2:
		l -= memo[i]
	elif d == 3:
		t += memo[i]

	if d == 0 or d == 1:
		if d == 0:
			squares.append((r-memo[i], t, memo[i], i))
		else:
			squares.append((r-memo[i], b+memo[i], memo[i], i))
	if d == 2 or d == 3:
		squares.append((l, t, memo[i], i))


for point in points:
	px, py = point
	for sq in squares:
		sx, sy, sd, n = sq
		if pointRectCollide(px, py, sx, sy, sd, sd):
			break
	print(n)
