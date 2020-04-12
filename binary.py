def decToBin(n):
	if n == 0:
		return "0000"

	b = ""
	while n:
		b = str(int(n % 2)) + b
		n //= 2

	b = ((3 - (len(b) - 1) % 4) * "0") + b
	return ' '.join([b[i:i+4] for i in range(0, len(b), 4)])

for _ in range(int(input())):
	print(decToBin(int(input())))
