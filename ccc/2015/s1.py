lines = int(input())
sequence = []
for line in range(lines):
	sequence.append(input())

stack = []
for char in sequence:
	if char == "0":
		stack.pop()
	else:
		stack.append(int(char))

print(sum(stack))