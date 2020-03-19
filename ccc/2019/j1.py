'''
d = int(input())*3 + int(input())*2 + int(input()) - int(input())*3 - int(input())*2 - int(input())
if  d == 0: print("T")
elif d > 0: print("A")
elif d < 0: print("B")
'''

#'''
aOne = int(input()) * 3
aTwo = int(input()) * 2
aThree = int(input())

bOne = int(input()) * 3
bTwo = int(input()) * 2
bThree = int(input())

aSum = aOne + aTwo + aThree
bSum = bOne + bTwo + bThree

if aSum == bSum:
	print("T")
if aSum > bSum:
	print("A")
if aSum < bSum:
	print("B")
#'''