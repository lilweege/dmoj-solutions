from collections import SortedDict
import sys
input = sys.stdin.readline

ans = 0
tree = SortedDict()

for _ in range(int(input())):
	n = int(input())
	depth = 0
	tree[n] = depth
	it = tree.bisect_left(n)
	if tree.peekitem(it) != tree.peekitem():
		pass
	if tree.peekitem(it) != tree.peekitem(0):
		pass

	ans += depth
	print(ans)
