values = {
"I": 1,
"V": 5,
"X": 10,
"L": 50,
"C": 100,
"D": 500,
"M": 1000}

S = input()

sum = 0
for i in range(0, len(S), 2):
	a = int(S[i])
	r = values[S[i+1]]
	if i+3 < len(S):
		nr = values[S[i+3]]
	else:
		nr = 0
	
	if nr > r:
		val = a * -r
	else:
		val = a * r
	
	sum += val
print(sum)