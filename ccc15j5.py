n = int(input())
k = int(input())

def pi(n, k, min):
	if visited[n][k][min] == 0:
		if k == n or k == 1:
			visited[n][k][min] = 1
		
		else:
			t = 0
			for i in range(min, n//k+1):
				t += pi(n-i, k-1, i)
				
			visited[n][k][min] = t

	return visited[n][k][min]


visited = [[[0 for x in range(n+1)] for y in range(k+1)] for z in range(n+1)]
print(pi(n, k, 1))