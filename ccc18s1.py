n = int(input())
villages = [int(input()) for i in range(n)]
villages.sort()

smallestNeighborhood = None

for i in range(n):
	if i == 0 or i == n-1:
		continue
	leftBound = (villages[i-1] + villages[i])/2
	rightBound = (villages[i] + villages[i+1]) / 2
	neighborhood = rightBound - leftBound
	if smallestNeighborhood == None or neighborhood < smallestNeighborhood:
		smallestNeighborhood = neighborhood

print(smallestNeighborhood)