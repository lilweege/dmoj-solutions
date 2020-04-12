smallest = 201
ans = ""
while True:
	a, b = input().split()
	b = int(b)
	if b < smallest:
		smallest = b
		ans = a

	if a == "Waterloo":
		break

print(ans)
