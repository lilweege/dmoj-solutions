m=10**6
n=10**5
S=''.join('b' if i%n==0 else 'a' for i in range(m))
T='a'*n

import time
now=time.time()
x=S.find(T)
diff=time.time()-now
print(f'idx {x} in {diff}')

# print(S)
# print(T)