#include <bits/stdc++.h>
using namespace std;

int main() {
	int p, n, r, d = 0;
	cin >> p >> n >> r;
	for (int t = n; t <= p; ++d)
		t += (n *= r);
	cout << d;
}