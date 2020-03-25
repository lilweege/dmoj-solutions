import math # for sqrt calculation
import sys # for python fast input

# work backwards from target number
def solitaire(n):
	cost = 0
	while n > 1:
		# fast factor
		# stop at first valid factor (best scoring)
		r = int(math.sqrt(n)) # end at sqrt of n (r*r=n)
		f = 2 # start at 2 (all n will have 1 as factor)
		while f <= r+1 and n%f != 0: 
			f += 1
		
		# if no factor is found (n is prime)
		if n%f != 0:
			a = 1
		# otherwise, f is a valid factor
		else:
			a = n/f
	
		# go to new n
		n -= a
		# add cost to go to new n
		cost += n/a
	
	# loop ended when arrived at start point (1)
	# final cost after working backwards is same
	return int(cost)

print(solitaire(int(sys.stdin.readline())))