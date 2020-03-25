import sys
input = sys.stdin.readline

class Coord:
	def __init__(self, x, y, z):
		self.x = x
		self.y = y
		self.z = z

class Beam:
	def __init__(self, p, q):
		dx = q.x - p.x
		dy = q.y - p.y
		dz = q.z - p.z
		d = (dx**2 + dy**2 + dz**2)**0.5
		self.m = (round(dx/d, 5), round(dy/d, 5), round(dz/d, 5))

	def __repr__(self):
		return str(self.m)

	def __eq__(self, other):
		return self.m == other.m

	def __hash__(self):
		return hash(self.__repr__())

	def __iter__(self):
		yield from self.m


beams = set()
origin = Coord(*map(int, input().split()))
n = int(input())
for i in range(n):
	enemy = Coord(*map(int, input().split()))
	beams.add(Beam(origin, enemy))

print(len(beams))
