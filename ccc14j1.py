a = [int(input()),int(input()),int(input())]

if a[0] + a[1] + a[2] != 180:
	print("Error")

elif a[0] == 60 and a[1] == 60 and a[2] == 60:
	print("Equilateral")

elif a[0] != a[1] and a[1] != a[2] and a[0] != a[2]:
	print("Scalene")

else:
	print("Isosceles")