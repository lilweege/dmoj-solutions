t1 = int(input())
t2 = int(input())

cnt = 0
while True:
	t = t1 - t2
	t1 = t2
	t2 = t
	if t < 0:
		break
	cnt += 1

print(cnt + 2)
