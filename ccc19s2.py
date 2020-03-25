def isPrime(n):
	if (n <= 1): return False
	if (n <= 3): return True
	if (n % 2 == 0 or n % 3 == 0): return False
	i = 5
	while(i * i <= n):
		if (n % i == 0 or n % (i + 2) == 0): return False
		i = i + 6
	return True

cases = int(input())
numbers = []
for case in range(cases):
	numbers.append(int(input()))

for number in numbers:
	if isPrime(number):
		print(number, number)
		continue

	diff = 0
	while not (isPrime(number + diff) and isPrime(number - diff)):
		diff += 1

	print(number + diff, number - diff)
