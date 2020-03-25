import sys
input = sys.stdin.readline

s = input()
a = ["B", "F", "T", "L", "C"]
f = False
for i in range(5):
	if a[i] not in s:
		print(a[i])
		f = True
if not f:
	print("NO MISSING PARTS")
