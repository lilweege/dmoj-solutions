a = int(input())
b = int(input())
c = int(input())
d = int(input())
s = int(input())

nikky = 0
byron = 0

ncnt = 0
nfwd = True
bcnt = 0
bfwd = True
for step in range(s):
		
	if nfwd:
		nikky += 1
	else:
		nikky -= 1
	if bfwd:
		byron += 1
	else:
		byron -= 1
	
	ncnt += 1
	bcnt += 1
	
	if ncnt == a and nfwd:
		nfwd = False
		ncnt = 0
	if ncnt == b and not nfwd:
		nfwd = True
		ncnt = 0
	if bcnt == c and bfwd:
		bfwd = False
		bcnt = 0
	if bcnt == d and not bfwd:
		bfwd = True
		bcnt = 0

if nikky == byron:
	print("Tied")
elif nikky > byron:
	print("Nikky")
elif nikky < byron:
	print("Byron")