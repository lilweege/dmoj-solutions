n = int(input())
r = [int(input()) for x in range(n)]
freq = [0 for i in range(2001)]

for reading in r:
    freq[reading] += 1

highFreq = sorted(freq, reverse=True)
if highFreq[0] != highFreq[1]:
    firstIndex = freq.index(highFreq[0])
    diff = 0
    for i in range(2000,0,-1):
        if freq[i] == highFreq[1]:
            lastIndex = i
            newDiff = abs(firstIndex - lastIndex)
            if newDiff > diff:
                diff = newDiff

else:
    firstIndex = -1
    lastIndex = -1
    for i in range(2000,0,-1):
        if freq[i] == highFreq[0]:
            firstIndex = i
            break
    for i in range(0,2000):
        if freq[i] == highFreq[0]:
            lastIndex = i
            break
    diff = abs(firstIndex - lastIndex)


print(diff)