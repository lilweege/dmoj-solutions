j = int(input())
a = int(input())

sizes = [input() for i in range(j)]

count = 0
for l in range(a):
	t = input().split()
	i = int(t[1])-1
	size = t[0]
	
	if sizes[i] != "T":
		if size == "S" or size == sizes[i] or (size == "M" and sizes[i] == "L"):
			count += 1
			sizes[i] = "T"
print(count)