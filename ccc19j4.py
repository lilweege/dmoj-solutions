sequence = input()

h = False
v = False
for char in sequence:
	if char == "H": h = not h
	if char == "V": v = not v

if not h and not v:
	final = [1, 2, 3, 4]
if h and not v:
	final = [3, 4, 1, 2]
if not h and v:
	final = [2, 1, 4, 3]
if h and v:
	final = [4, 3, 2, 1]


print(str(final[0]) + " " + str(final[1]))
print(str(final[2]) + " " + str(final[3]))