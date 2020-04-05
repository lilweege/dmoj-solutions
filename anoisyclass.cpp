#include <bits/stdc++.h>
using namespace std;

int n, m;
bool possible;
vector<vector<int>> adj;
set<int> vis;

void dfs(int s, int e) {
	if (!vis.count(s)) {
		if (s == e)
			possible = false;
		else {
			vis.insert(s);
			for (int x : adj[s])
				dfs(x, e);
		}
	}
}


int main() {
	cin >> n >> m;
	adj.resize(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		adj[u - 1].push_back(v - 1);
	}

	for (int i = 0; i < n; i++) {
		vis.clear();
		possible = true;
		for (int x : adj[i])
			dfs(x, i);
		if (!possible)
			break;
	}

	cout << (possible ? "Y" : "N");
}
