a = int(input())
b = int(input())
c = int(input())
if (b <= a and a <= c) or (b >= a and a >= c):
    print(a)
elif (a <= b and b <= c) or (a >= b and b >= c):
	print(b)
else:
	print(c)
