#include <stdio.h>
#include <string.h>

int main() {
	int m = 1000000;
	int n = m / 2;
	char S[m+1], T[n+1];
	memset(S, 'a', m);
	S[n-1] = 'b';
	S[m-1] = '\n';
	S[m] = 0;
	memset(T, 'a', n);
	T[n] = 0;
	
	printf("%s\n%s", S, T);
}
