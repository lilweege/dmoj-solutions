'''
import sys
from itertools import combinations
from copy import deepcopy

r = int(sys.stdin.readline())
l = int(sys.stdin.readline())

grid = []
for _ in range(r):
    t = sys.stdin.readline().split()
    row = []
    for light in range(l):
        row.append(int(t[light]))
    grid.append(row)


def switchLight(light, above):
    return int(light != above)

possiblePatterns = []
switches = list(range(1, r))
for i in range(r-1):
    for sequence in combinations(switches, i + 1):
        new = deepcopy(grid)
        for row in sequence:
            for light in range(l):
                new[row][light] = switchLight(new[row][light], new[row-1][light])

        if new[-1] not in possiblePatterns:
            possiblePatterns.append(new[-1])

print(len(possiblePatterns))
'''

def switchRow(a, b):
    new = ""
    for i in range(len(a)):
        new += ("0" if a[i] == b[i] else "1")
    return new

r = int(input())
l = int(input())

rows = []
for i in range(r):
    rows.append(input().replace(" ", ""))

aboveRows = ["" for _ in range(30)]
belowRows = ["" for _ in range(30)]
aboveRows[0] = rows[0]

aboveSize = 1
for i in range(r):
    belowRows[0] = rows[i]
    belowSize = 1

    for j in range(aboveSize):
        newRow = switchRow(aboveRows[j], belowRows[0])

        k = 0
        while k < belowSize and belowRows[k] != newRow:
            k += 1
        
        if k >= belowSize:
            belowRows[belowSize] = newRow
            belowSize += 1
    
    for j in range(belowSize):
        aboveRows[j] = belowRows[j]
        aboveSize = belowSize

print(belowSize)
