def isTaller(p, q):
	visited = [False for _ in range(n)]	
	qu = [x for x in indexTallerThanValue[p]]
	
	
	while qu:
		cur = qu.pop(0)
		if cur == q:
			return True
		if visited[cur]:
			continue
		visited[cur] = True	
		qu.extend(indexTallerThanValue[cur])
		
	return False
    

import sys
n, m = map(int, sys.stdin.readline().split())

# I'm very good at naming variables btw
indexTallerThanValue = [[] for _ in range(n)] 

for _ in range(m):
	taller, shorter = map(int, sys.stdin.readline().split())
	indexTallerThanValue[taller-1].append(shorter-1)


p1, p2 = map(int, sys.stdin.readline().split())
print ("yes" if isTaller(p1-1, p2-1) else\
		"no" if isTaller(p2-1, p1-1) else\
		"unknown")
