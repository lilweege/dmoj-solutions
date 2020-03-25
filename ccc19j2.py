l = int(input())

lines = []
for i in range(l):
	t = input().split()
	lines.append([int(t[0]), t[1]])
	
for line in lines:
	print(line[1] * line[0])