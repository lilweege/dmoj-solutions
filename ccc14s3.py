'''
Luigi Quattrociocchi
Waterloo CCC 2014 S3: The Geneva Confection
Queues
'''

import sys
t = int(sys.stdin.readline())

tests = []
for i in range(t):
	tests.append([int(sys.stdin.readline()) for x in range(int(sys.stdin.readline()))])


for onMountain in tests:
	length = len(onMountain)
	onBranch = []
	car = 1
	while True:
		if onMountain and onMountain[-1] == car:
			onMountain.pop()
			car += 1
		elif onBranch and onBranch[-1] == car:
			onBranch.pop()
			car += 1
		elif onMountain:
			onBranch.append(onMountain.pop())
		else:
			break
	
	print("Y" if car-1 == length else "N")