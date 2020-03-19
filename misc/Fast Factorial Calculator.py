input = __import__('sys').stdin.readline
def fastFactMod(n):
	sorte = sorted(nums)
	fact = 1
	j = 0
	next = sorte[j]
	for i in range(1, n+1):
		fact = (fact*i) & 0xffffffff
		if i == next:
			res[nums.index(i)] = fact
			j += 1
			if j < len(sorte):
				next = sorte[j]
nums = []
res = []
max = 0
for i in range(int(input())):
	num = int(input())
	nums.append(num)
	res.append(0)
	if num > max:
		max = num

fastFactMod(max)

print(res)
# for r in res:
# 	print(r)
