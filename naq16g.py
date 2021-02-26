from math import *
from itertools import count
import sys
input = sys.stdin.readline

def bad_fact(n):
	fact = 1
	for i in count(1):
		fact *= i
		if fact >= n:
			break
	return i

def gud_fact(l):
	'''
	for i in count(1):
		# stirling equation bruh
		if ceil(log10(tau * i) / 2 + i * log10(i / e)) == l:
			return i
	'''
	digs = 0
	for i in count(1):
		digs += log10(i)
		if digs >= l:
			break
	return i - 1


s = input()[:-1]
l = len(s)
if l <= 7:
	print(bad_fact(int(s)))
else:
	print(gud_fact(l))