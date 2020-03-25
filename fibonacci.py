m = 1000000007
fibs = {0: 0, 1: 1}

def fibM(n):
	if n in fibs:
		return fibs[n]

	if n%2==0:
		k = n//2
		a = fibM(k)
		b = fibM(k-1)
		t = (a**2 + 2*a*b)%m
	else:
		k = (n+1)//2
		a = fibM(k)
		b = fibM(k-1)
		t = (a**2 + b**2)%m

	fibs[n] = t
	return t


print(fibM(int(__import__('sys').stdin.readline())))
