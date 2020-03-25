import sys

MAX = 2000000000
high = MAX
low = 1

while low <= high:
	mid = low + (high - low) // 2
	print(mid)
	sys.stdout.flush()
	s = sys.stdin.readline()[:-1]
	if s == "SINKS":
		low = mid + 1
	elif s == "FLOATS":
		high = mid - 1
	elif s == "OK":
		break
