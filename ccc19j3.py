n = int(input())

lines = []
for i in range(n):
	lines.append(input())
	
for line in lines:
	code = ""
	for i in range(len(line)):
		if i == 0:
			char = line[i]
			size = 1
		elif line[i] != char:
			code += str(size) + " " + char + " "
			char = line[i]
			size = 1
		elif line[i] == char:
			size += 1
		
		if i == len(line)-1:
			code += str(size) + " " + char + " "
	print(code)