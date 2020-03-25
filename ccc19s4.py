def permutation(lst):
	if len(lst) == 0:
		return []
	if len(lst) == 1:
		return [lst]
	l = []
	for i in range(len(lst)):
		m = lst[i]
		remLst = lst[:i] + lst[i+1:]
		for p in permutation(remLst):
			l.append([m] + p)
	return l

combinations = []
def findCombinationsUtil(arr, index, num, reducedNum): 
	current = []
	if (reducedNum < 0): return
	if (reducedNum == 0):
		for i in range(index):
			current.append(arr[i])
		combinations.append(current)
		return
	prev = 1 if(index == 0) else arr[index - 1]; 
	for k in range(prev, num + 1): 
		arr[index] = k; 
		findCombinationsUtil(arr, index + 1, num, reducedNum - k); 

def findCombinations(n): 
    arr = [0] * n; 
    findCombinationsUtil(arr, 0, n, n); 
def getValidCombination():
	for combination in combinations:
		valid = True
		if len(combination) > minDays:
			valid = False
		
		for invalid in range(k+1, n+1):
			if combination.count(invalid) > 0:
				valid = False
		
		if valid:
			return combination



import math
firstLine = input().split()
n = int(firstLine[0]) # number of attractions
k = int(firstLine[1]) # attractions per day

attractions = input().split()
for i in range(len(attractions)):
	attractions[i] = int(attractions[i])
minDays = int(math.ceil(float(n)/float(k)))


findCombinations(n)
combination = getValidCombination()

possibleSchedules = []
for p in permutation(combination):
	if p not in possibleSchedules:
		possibleSchedules.append(p)
#print(possibleSchedules)

highestScore = 0
for schedule in possibleSchedules:
	visited = 0
	score = 0
	for day in range(minDays):
		count = 0
		points = 0
		while count < schedule[day]:
			if attractions[visited] > points:
				points = attractions[visited]
			count += 1
			visited += 1
		score += points
		
	if score > highestScore:
		highestScore = score

print(highestScore)