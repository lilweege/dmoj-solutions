
def slidingWindow(needle, haystack):
	seen = set()
	cnt = 0
	N = len(needle)
	H = len(haystack)

	if N > H:
		return 0

	needle_freq = [0]*26
	window = [0]*26

	for i in range(N):
		needle_freq[ord(needle[i])-97] += 1
		window[ord(haystack[i])-97] += 1

	for i in range(N, H):
		sect = haystack[i-N:i]
		if needle_freq == window and sect not in seen:
			seen.add(sect)
			cnt += 1

		window[ord(haystack[i-N])-97] -= 1
		window[ord(haystack[i])-97] += 1

	sect = haystack[H-N:]
	if needle_freq == window and sect not in seen:
		seen.add(sect)
		cnt += 1


	return cnt

import sys
input = sys.stdin.readline
print(slidingWindow(input()[:-1], input()[:-1]))

'''
import sys
input = sys.stdin.readline
# needle = input()[:-1]
# haystack = input()[:-1]
haystack = "banana"
def suffixArray(s):
	# return [s[1] for s in sorted([(s[i:], i) for i in range(len(s))])]
	return sorted(range(len(s)), key = lambda i: s[i:])

def kasai(s, sarr):
	n = len(sarr)
	lcp = [0]*n
	inv = [0]*n

	for i in range(n):
		inv[sarr[i]] = i

	k = 0
	for i in range(n):
		if inv[i] == n-1:
			k = 0
			continue
		j = sarr[inv[i]+1]

		while i + k < n and j + k < n and s[i+k] == s[j+k]:
			k += 1

		lcp[inv[i]] = k

		if k > 0:
			k -= 1

	return lcp

sarr = suffixArray(haystack)
lcp = kasai(haystack, sarr)
print(sarr)
print(lcp)
'''
