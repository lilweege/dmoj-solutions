import sys
input = sys.stdin.readline
n = int(input())
t = int(input())

lines = []
ys = []

class Line:
	def __init__(self, xr, y1, y2, tf):
		self.xr = xr
		self.y1 = y1
		self.y2 = y2
		self.tf = tf

	def __lt__(self, other):
		return self.xr < other.xr

	def __iter__(self):
		yield from (self.xr, self.y1, self.y2, self.tf,)

for i in range(n):
	xl, yt, xr, yb, tf = map(int,input().split())
	lines += [Line(xl, yt, yb, tf), Line(xr, yt, yb,-tf)]
	ys += [yt, yb]

lines.sort()
ys = list(set(ys))
ys.sort()

tint = [0]*(len(ys))
ans = 0
xl = 0
for xr, y1, y2, tf in lines:

	for j in range(len(ys)-1):
		if tint[j] >= t:
			ans += (ys[j+1] - ys[j]) * (xr - xl)

	for j in range(len(ys)-1):
		if y1 <= ys[j] and y2 >= ys[j+1]:
			tint[j] += tf
	xl = xr

print(ans)
