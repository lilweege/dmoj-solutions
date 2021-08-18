#include <bits/stdc++.h>
using namespace std;

int main() {
	int s, m, l;
	cin >> s >> m >> l;
	int h = s + 2*m + 3*l;
	cout << (h >= 10 ? "happy" : "sad");
}