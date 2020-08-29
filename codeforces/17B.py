import sys
input = sys.stdin.readline

def main():
	n = int(input())
	q = list(map(int, input().split()))
	m = int(input())
	
	cost = {}
	
	for _ in range(m):
		a, b, c = map(int, input().split())
		a, b = a - 1, b - 1
		
		if q[a] > q[b]:
			if b in cost:
				if cost[b] > c:
					cost[b] = c
			else:
				cost[b] = c
	
	print(-1 if len(cost) < n - 1 else sum(cost.values()))
	

if __name__ == '__main__':
	main()