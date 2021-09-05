from math import sqrt
from itertools import combinations
from dataclasses import dataclass

@dataclass
class vec:
	x: int
	y: int
	z: int = 0

	def __add__(self, other):
		return vec(self.x+other.x, self.y+other.y, self.z+other.z)

	def __neg__(self):
		return vec(-self.x, -self.y, -self.z)
	
	def __sub__(self, other):
		return self + -other

	def __mul__(self, other):
		if isinstance(other, (int, float)):
			return vec(self.x*other, self.y*other, self.z*other)
		return self.x*other.x + self.y*other.y + self.z*other.z

	def __truediv__(self, other):
		return self * (1/other)

	def __abs__(self):
		return sqrt(self.x*self.x + self.y*self.y + self.z*self.z)

	def __xor__(self, other):
		return vec(
			self.y*other.z - self.z*other.y,
			self.z*other.x - self.x*other.z,
			self.x*other.y - self.y*other.x)


def area(A, B, C):
	AB = B - A
	AC = C - A
	return abs(AB ^ AC) / 2

def norm(A, B, C):
	AB = B - A
	AC = C - A
	v = AB ^ AC
	return v / abs(v)

def sign(x):
	return x / abs(x)

def shoelace(poly):
	# NOTE: ensure polygon does not intersect self
	# NOTE: returns clockwise signed area
	area = 0
	for i in range(len(poly)):
		area += poly[i-1].x * poly[i].y
		area -= poly[i-1].y * poly[i].x
	return area / 2

def lineplane(X, Y, A, n):
	# NOTE: 3d line plane
	# assume exists
	XY = Y - X
	AX = X - A
	return X - XY*(AX*n)/(XY*n)

def lineline(A, B, C, D):
	# NOTE: 2d line line
	# (A,B) x (C,D)
	x43 = D.x - C.x
	x13 = A.x - C.x
	x21 = B.x - A.x
	y43 = D.y - C.y
	y13 = A.y - C.y
	y21 = B.y - A.y
	d = y43*x21 - x43*y21
	if abs(d) < 1e-8:
		return None
	uA = (x43*y13 - y43*x13) / d
	uB = (x21*y13 - y21*x13) / d
	if uA >= 0 and uA <= 1 and uB >= 0 and uB <= 1:
		return vec(A.x + uA*x21, A.y + uA*y21)
	return None


def sutherland_hodgman(subj, clip):
	# https://en.wikipedia.org/wiki/Sutherland%E2%80%93Hodgman_algorithm
	
	def inside(P, A, B):
		# point P clockwise edge A, B
		return ((B-A) ^ (P-A)).z > 0

	def intersect(A, B, C, D):
		# infinite edge
		AB = B - A
		CD = D - C
		d = (AB ^ CD).z
		assert abs(d) > 1e-8
		return (AB*(C^D).z - CD*(A^B).z) / d

	out = subj[:]
	for i in range(len(clip)):
		A, B = clip[i-1], clip[i]
		inp, out = out, []
		for j in range(len(inp)):
			prv, cur = inp[j-1], inp[j]
			if inside(cur, A, B):
				if not inside(prv, A, B):
					out.append(intersect(prv, cur, A, B))
				out.append(cur)
			elif inside(prv, A, B):
				out.append(intersect(prv, cur, A, B))
	return out


def quad(poly):
	# from unordered 2d points
	A, B, C, D = poly
	if lineline(A, B, C, D):
		B, C = C, B
	elif lineline(B, C, D, A):
		C, D = D, C
	return [A, B, C, D]

def clockwise(poly):
	is_cw = shoelace(poly) > 0
	return poly if is_cw else poly[::-1]


def solve(tetra1, tetra2):
	ans = 0
	for A, B, C in combinations(tetra1, 3):
		ans += area(A, B, C)
		n = norm(A, B, C)
		points = [lineplane(X, Y, A, n) for X, Y in combinations(tetra2, 2)
			if sign((X-A) * n) != sign((Y-A) * n)]
		
		if len(points) < 3:
			continue
		# len is 3 or 4
		
		# some basis of plane
		AB = B - A
		i = AB / abs(AB)
		j = i ^ n
		def proj(Q):
			return vec(Q*i, Q*j)
		
		poly = [proj(Q) for Q in points]
		if len(poly) == 4:
			poly = quad(poly)
		
		poly = clockwise(poly)
		face = clockwise([proj(A), proj(B), proj(C)])

		clipped = sutherland_hodgman(face, poly)
		ans -= shoelace(clipped)
	
	return ans


get_tetra = lambda: [vec(*map(int, input().split())) for _ in range(4)]
t1, t2 = get_tetra(), get_tetra()
ans = solve(t1, t2) + solve(t2, t1)
print(f"{ans:.6f}")
