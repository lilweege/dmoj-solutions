#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string n;
	string lastdir;
	while (true) {
		cin >> n;
		if (n == "99999")
			break;
		
		int dir = n[0]-'0' + n[1]-'0';

		int steps = (n[2]-'0') * 100 +
					(n[3]-'0') * 10 +
					(n[4]-'0');
		
		if (dir & 1) {
			lastdir = "left";
		}
		else if (dir) {
			lastdir = "right";
		}

		cout << lastdir << " " << steps << "\n";
	}
}