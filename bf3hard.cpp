#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull mulM(ull a, ull b, ull m) {
  ull x = 0;
  ull y = a % m;
  while (b) {
	if (b % 2 == 1) {
	  x = (x + y) % m;
	}
	y = 2 * y % m;
	b /= 2;
  }
  return x % m;
}

ull powM(ull b, ull p, ull m) {
  ull x = 1;
  ull y = b;
  while (p) {
	if (p % 2 == 1) {
	  x = mulM(x, y, m);
	}
	y = mulM(y, y, m);
	p /= 2;
  }
  return x % m;
}

bool isPrime(ull n, int k) {
  if (n == 2) {
	return true;
  }
  if (n <= 1 || n % 2 == 0) {
	return false;
  }
  ull s = n - 1;
  while (s % 2 == 0) {
	s /= 2;
  }

  for (int i = 0; i < k; i++) {
	ull t = s;
	ull r = powM(rand() % (n-1) + 1, t, n);
	while (t != n-1 && r != 1 && r != n - 1) {
	  r = mulM(r, r, n);
	  t *= 2;
	}
	if (r != n-1 && t % 2 == 0) {
	  return false;
	}
  }

  return true;
}

int main() {
  ull n;
  cin >> n;
  while (!isPrime(n, 3)) n++;
  cout << n;
}
