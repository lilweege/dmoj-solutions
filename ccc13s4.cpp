#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000000

ll n, m;
vector<vector<int> > indexTallerThanValue(maxn);

bool isTaller(int p, int q) {
	vector<bool> vis(n+1);
	queue<int> qu;
	for (int x : indexTallerThanValue[p]) {
		qu.push(x);
	}

	while (!qu.empty()) {
		int cur = qu.front(); qu.pop();

		if (cur == q)
			return true;

		if (vis[cur])
			continue;

		vis[cur] = true;
		for (int x : indexTallerThanValue[cur]) {
			qu.push(x);
		}
	}
	return false;
}

int main() {
	cin >> n >> m;

	for (int i = 0, taller, shorter; i < m; i++) {
		cin >> taller >> shorter;
		taller -= 1; shorter -= 1;
		indexTallerThanValue[taller].push_back(shorter);
	}


	int p1, p2;
	cin >> p1 >> p2;
	p1 -= 1; p2 -= 1;

	if (isTaller(p1, p2))
		cout << "yes";
	else if (isTaller(p2, p1))
		cout << "no";
	else
		cout << "unknown";

	return 0;
}
