import sys
import math
rx, ry, jx, jy = map(int, sys.stdin.readline().split())
string = ((rx, ry), (jx, jy))
b = int(sys.stdin.readline())

buildings = []
for _ in range(b):
	line = sys.stdin.readline().split()
	points = int(line[0])
	building = []
	for i in range(1, points+1):
		building.append((int(line[2*i-1]), int(line[2*i])))
	buildings.append(building)

segments = []
for building in buildings:
	shape = []
	for i in range(len(building)):
		if i == len(building)-1:
			segment = (building[i], building[0])
		else:
			segment = (building[i], building[i+1])
		shape.append(segment)
	segments.append(shape)

def isInBetween(n, a, b):
	return (n >= a and n <= b) or (n <= a and n >= b)

def segmentIntersect(seg1, seg2):
	x1 = seg1[0][0]
	y1 = seg1[0][1]
	x2 = seg1[1][0]
	y2 = seg1[1][1]
	x3 = seg2[0][0]
	y3 = seg2[0][1]
	x4 = seg2[1][0]
	y4 = seg2[1][1]
	
	if x1 == x2:
		m1 = float("inf")
		b1 = 0
	else:
		m1 = (y1-y2)/(x1-x2)
		b1 = y2 - m1*x2

	if x3 == x4:
		m2 = float("inf")
		b2 = 0
	else:
		m2 = (y3-y4)/(x3-x4)
		b2 = y4 - m2*x4
		
	if m1 == m2:
		if math.isinf(m1):
			if x1 == x3:
				return isInBetween(y3, y1, y2) or isInBetween(y4, y1, y2)
		else:
			if b1 == b2:
				return isInBetween(x3, x1, x2) or isInBetween(x4, x1, x2)
		return False
	if math.isinf(m1) or math.isinf(m2):
		if math.isinf(m1):
			xi = x1
			yi = m2*xi + b2
		else:
			xi = x3
			yi = m1*xi + b1
	else:
		xi = (b2-b1)/(m1-m2)
		yi = m1*xi + b1

	return isInBetween(xi, x1, x2) and isInBetween(yi, y1, y2) and isInBetween(xi, x3, x4) and isInBetween(yi, y3, y4)

blocking = 0
for shape in segments:
	for segment in shape:
		if segmentIntersect(segment, string):
			blocking += 1
			break

print(blocking)