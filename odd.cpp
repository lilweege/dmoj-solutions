#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int a = 0, v;
	while (n--) {
		cin >> v;
		a ^= v;
	}
	cout << a << "\n";
}
