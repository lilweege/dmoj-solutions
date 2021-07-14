#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> h(n+1);
	for (int& x : h)
		cin >> x;
	vector<int> w(n);
	for (int& x : w)
		cin >> x;

	double area = 0;
	for (int i = 0; i < n; ++i) {
		int l = h[i];
		int r = h[i+1];
		int base = w[i];
		int hTri = abs(l - r);
		int hRect = min(l, r);
		area += hTri * base / 2.0f;
		area += hRect * base;
	}
	cout << fixed << setprecision(6) << area << "\n";
}