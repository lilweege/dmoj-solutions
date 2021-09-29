#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, T;
	cin >> N >> T;

	vector<vector<pair<int, int>>> adj(N+1);

	// [a] -> (b, c)
	int total = 0;
	for (int i = 1; i < N; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
		total += c;
	}

	vector<bool> vis(N+1);
	auto clear = [&]() { fill(begin(vis), end(vis), false); };

	int md;
	function<void(int, int&, int)> dfs1 = [&]
	(int cur, int& idx, int d) { // bro how do default arg d=0 -_-
		vis[cur] = true;
		if (md < d) {
			md = d;
			idx = cur;
		}
		for (auto [nxt, dst] : adj[cur])
			if (!vis[nxt])
				dfs1(nxt, idx, d+dst);
	};

	int node1 = 0, node2 = 0;
	clear(); md = 0; dfs1(1, node1, 0);
	clear(); md = 0; dfs1(node1, node2, 0);
	
	
	function<void(int, vector<int>&)> dfs2 = [&]
	(int cur, vector<int>& dist) {
		vis[cur] = true;
		for (auto [nxt, dst] : adj[cur])
			if (!vis[nxt]) {
				dist[nxt] = dist[cur] + dst;
				dfs2(nxt, dist);
			}
	};

	vector<int> dist1(N+1);
	vector<int> dist2(N+1);
	clear(); dfs2(node1, dist1);
	clear(); dfs2(node2, dist2);
	
	for (int i = 1; i <= N; ++i)
		if (int(size(adj[i])) == T)
			cout << i << " " << (2*total - max(dist1[i], dist2[i])) << "\n";
}