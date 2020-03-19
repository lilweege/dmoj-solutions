import sys
INF = 10**8

ship = []
shop = []
visited = []
n = int(sys.stdin.readline())
for i in range(n+1):
	ship.append([INF for _ in range(i+1)])
	shop.append(INF)
	visited.append(False)

t = int(sys.stdin.readline())
for _ in range(t):
	x, y, cost = map(int, sys.stdin.readline().split(" "))
	if x <= n or y <= n:
		ship[max(x, y)][min(x, y)] = cost

k = int(sys.stdin.readline())
for _ in range(k):
	city, cost = map(int, sys.stdin.readline().split(" "))
	if city <= n:
		shop[city] = cost

def getCheapest(city):
	if visited[city]:
		return shop[city]
	visited[city] = True

	cheapest = shop[city]
	for c in range(1, n+1):
		transport = ship[max(c, city)][min(c, city)]
		price = getCheapest(c)
		cheapest = min(cheapest, transport + price)
	shop[city] = cheapest

	return cheapest

dest = int(sys.stdin.readline())
cost = 0
while True:
	visited = [False for i in range(n+1)]
	prev = cost
	cost = getCheapest(dest)
	if cost == prev:
		break

print(cost)
