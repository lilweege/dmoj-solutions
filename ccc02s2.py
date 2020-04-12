import math
a = int(input())
b = int(input())
if a % b == 0:
	print(a//b)
else:
	g = math.gcd(a, b)
	a //= g
	b //= g
	if a > b:
		print(f"{a // b} {a % b}/{b}")
	else:
		print(f"{a}/{b}")
