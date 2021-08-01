#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		// reverse 😳️
		adj[b].push_back(a);
	}

	unordered_set<int> vis(n);
	pair<int, int> best = { -1, -1 };

	for (int end = n-1; end >= 0; --end) {
		vis.insert(end);
		queue<int> q;
		q.push(end);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			if (cur < end)
				best = max(best, { cur, end });
			for (int nxt : adj[cur]) {
				if (vis.contains(nxt))
					continue;
				vis.insert(nxt);
				q.push(nxt);
			}
		}
	}

	if (best.first == -1)
		cout << "-1\n";
	else
		cout << (best.first+1) << " " << (best.second+1) << "\n";
}
