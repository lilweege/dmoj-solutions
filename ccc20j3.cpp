#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int x1 = 100, x2 = 0;
	int y1 = 100, y2 = 0;
	for (int i = 0; i < n; ++i) {
		int x, y;
		char _;
		cin >> x >> _ >> y;
		x1 = min(x1, x);
		x2 = max(x2, x);
		y1 = min(y1, y);
		y2 = max(y2, y);
	}
	--x1, --y1, ++x2, ++y2;
	cout << x1 << "," << y1 << "\n";
	cout << x2 << "," << y2 << "\n";
}