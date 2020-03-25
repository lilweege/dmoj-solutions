n = int(input())
t = input().split()
measurements = [int(t[i]) for i in range(n)]
measurements.sort()

low = []
high = []
for m in range(n):
	if m<n/2:
		low.insert(0, measurements[m])
	else:
		high.append(measurements[m])

res = []
for m in range(n):
	if m%2==0:
		res.append(low[m//2])
	else:
		res.append(high[m//2])

for tide in res:
	print(tide, end=' ')