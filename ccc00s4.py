d = int(input())
n = int(input())

dist = [5280 for _ in range(d+1)]
club = [int(input()) for _ in range(n)]

for i in range(len(dist)):
	for j in range(len(club)):
		if club[j] < i:
			dist[i] = min(dist[i], dist[i - club[j]] + 1)
		elif club[j] == i:
			dist[i] = 1

print(f"Roberta wins in {dist[d]} strokes." if dist[d] < 5280 else "Roberta acknowledges defeat.")