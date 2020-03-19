n = int(input())
a = 100
d = 100


rounds = []
for round in range(n):
	temp = input().split()
	r = []
	for c in temp:
		r.append(int(c))
	
	if r[0] == r[1]:
		pass
	elif r[0] > r[1]:
		d -= r[0]
	elif r[0] < r[1]:
		a -= r[1]

print(a)
print(d)

	
