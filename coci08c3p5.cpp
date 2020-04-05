#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	map<int, int> t;
	long long C = 0;
	for (int i = 0, n; i < N; i++) {
		cin >> n;
		map<int, int>::iterator it = t.lower_bound(n);

		int d = 0;
		if (it != t.end()) {
			d = max(0, it -> second + 1);
		}
		if (it != t.begin()) {
			d = max(d, (--it) -> second + 1);
		}
		t[n] = d;

		cout << (C += t[n]) << endl;
	}
}
