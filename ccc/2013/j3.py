d = int(input())

valid = False
y = 0
while not valid:
	y += 1
	new = str(d+y)
	valid = True
	for n in new:
		if new.count(n) > 1:
			valid = False
			break

print(int(new))