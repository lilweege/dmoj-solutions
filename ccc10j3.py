a = 0
b = 0

while True:
	line = input().split()
	if int(line[0]) == 7:
		break
	if int(line[0]) == 1:
		if line[1] == "A":
			a = int(line[2])
		if line[1] == "B":
			b = int(line[2])
	if int(line[0]) == 2:
		if line[1] == "A":
			print(a)
		if line[1] == "B":
			print(b)
	if int(line[0]) == 3:
		if line[1] == "A":
			if line[2] == "A":
				a += a
			if line[2] == "B":
				a += b
		if line[1] == "B":
			if line[2] == "A":
				b += a
			if line[2] == "B":
				b += b
	if int(line[0]) == 4:
		if line[1] == "A":
			if line[2] == "A":
				a *= a
			if line[2] == "B":
				a *= b
		if line[1] == "B":
			if line[2] == "A":
				b *= a
			if line[2] == "B":
				b *= b
	if int(line[0]) == 5:
		if line[1] == "A":
			if line[2] == "A":
				a -= a
			if line[2] == "B":
				a -= b
		if line[1] == "B":
			if line[2] == "A":
				b -= a
			if line[2] == "B":
				b -= b
	if int(line[0]) == 6:
		if line[1] == "A":
			if line[2] == "A":
				a = a//a
			if line[2] == "B":
				a = a//b
		if line[1] == "B":
			if line[2] == "A":
				b = b//a
			if line[2] == "B":
				b = b//b
