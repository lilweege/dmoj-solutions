'''
Luigi Quattrociocchi
Waterloo CCC 2020 S1: Surmising a Sprinter's Speed
Sorting 2D array and check consecutive points
'''

import sys
n = int(sys.stdin.readline())

observations = []
for y in range(n):
	observations.append([int(x) for x in sys.stdin.readline().split()])
observations.sort(key=lambda x: x[0])

maxvel = 0
for i in range(n-1):
	t = observations[i][0]-observations[i+1][0]
	d = observations[i][1]-observations[i+1][1]
	vel = d/t
	if abs(vel) > maxvel:
		maxvel = abs(vel)

print(maxvel)
