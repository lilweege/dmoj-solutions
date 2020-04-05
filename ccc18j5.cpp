#include <bits/stdc++.h>
using namespace std;
#define MAXN 10001


int main() {
	int n;
	cin >> n;

	vector<vector<int>> adj(MAXN);
	for (int u = 1, m; u <= n; u++) {
		cin >> m;
		for (int v; m > 0; m--) {
			cin >> v;
			adj[u].push_back(v);
		}
	}

	vector<int> dist(MAXN, INT_MAX);
	dist[1] = 1;

	queue<int> q; q.push(1);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (dist[u] < dist[v] - 1) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	bool possible = true;
	int shortest = INT_MAX;
	for (int x = 1; x <= n; x++) {
		if (dist[x] == INT_MAX)
			possible = false;
		if (adj[x].empty())
			shortest = min(shortest, dist[x]);
	}

	cout << (possible ? "Y" : "N") << endl << shortest;
}
