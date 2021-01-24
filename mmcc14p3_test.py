
from random import *
M = 5000

with open("data.txt", "w") as f:
	m = randint(1, M)
	n = randint(m, M)
	s = randint(1, m)
	f.write(f"{n} {s}\n")
	
	# https://math.stackexchange.com/questions/683/how-can-i-randomly-generate-trees
	dst = list(range(1, n + 1))
	shuffle(dst)
	src = [dst.pop()]
	while dst:
		a = src[randint(0, len(src) - 1)]
		b = dst.pop()
		f.write(f"{a} {b}\n")
		src.append(b)

