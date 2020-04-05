import sys
input = sys.stdin.readline

adj = [[] for _ in range(26)]
edges = []

while True:
	a, b = map(lambda c: ord(c) - ord('A'), input()[:-1])
	if a == -23:
		break
	edges.append((a, b))
	adj[a].append(b)
	adj[b].append(a)


cnt = 0
for a, b in edges:
	# 0 is a
	vis = set([0])
	q = [0]
	while q:
		u = q.pop(0)
		for v in adj[u]:
			if v not in vis and (u != a or v != b) and (u != b or v != a):
				vis.add(v)
				q.append(v)

	# 1 is b
	if 1 not in vis:
		cnt += 1
		print(f"{chr(a+ord('A'))}{chr(b+ord('A'))}")

print(f"There are {cnt} disconnecting roads.")
