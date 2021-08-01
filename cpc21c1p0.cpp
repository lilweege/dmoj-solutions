#include <bits/stdc++.h>
using namespace std;

bool l[26];
int main() {
	for (int i = 0; i < 5; ++i) {
		char c;
		cin >> c;
		l[c-'a'] = 1;
	}

	for (int i = 0; i < 26; ++i)
		if (!l[i]) {
			cout << char(i+'a') << "\n";
			return 0;
		}
}