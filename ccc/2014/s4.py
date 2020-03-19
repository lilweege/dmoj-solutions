class Window:
	def __init__(self, x, y, w, h, t):
		self.x = x
		self.y = y
		self.w = w
		self.h = h
		self.t = t

	def pointCollide(self, px, py):
		return px >= self.x and px < self.x + self.w and py >= self.y and py < self.y + self.h


n = int(input())
tintFactor = int(input())
MAX = 1000000
l = t = MAX
r = b = 0

rects = []
for _ in range(n):
	x1, y1, x2, y2, tf = map(int, input().split(" "))
	l = min(l, x1)
	t = min(t, y1)
	r = max(r, x2)
	b = max(b, y2)
	rects.append(Window(x1, y1, x2-x1, y2-y1, tf))

tint = [[0 for _ in range(l, r+1)] for _ in range(t, b+1)]
tinted = 0

# brute force times out on most problems
# this is a very bad solution lol
for rect in rects:
	for x in range(l, r+1):
		for y in range(t, b+1):
			if rect.pointCollide(x, y):
				tint[y-b-1][x-l-1] += rect.t

for x in range(l, r+1):
	for y in range(t, b+1):
		if tint[y-b-1][x-l-1] >= tintFactor:
			tinted += 1

print(tinted)
