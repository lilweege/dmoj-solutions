#include <bits/stdc++.h>
using namespace std;

int main() {
	string t, s;
	cin >> t >> s;
	// unoptimal, but sufficient
	for (int i = 0; i < int(size(s)); ++i) {
		if (t.find(s) != string::npos) {
			cout << "yes";
			return 0;
		}
		s = s.back() + s;
		s.pop_back();
	}
	cout << "no";
}