#include <bits/stdc++.h>
using namespace std;

int N, S;
vector<vector<int>> adj;
vector<int> prv;
deque<int> ord;
vector<bool> vis, yes;
// https://www.youtube.com/watch?v=zb9ZQl3iOfU

void bfs(int st = 1) {
	vector<bool> vis(N + 1);
	vis[st] = true;
	queue<int> q;
	q.push(st);
	ord.push_front(st);
	while (q.size()) {
		int u = q.front(); q.pop();
		// cout << u << "\n";
		for (int v : adj[u]) {
			// cout << v << "\n";
			if (vis[v])
				continue;
			
			vis[v] = true;
			prv[v] = u;
			q.push(v);
			ord.push_front(v);
		}
	}
}

void dfs(int u, int d) {
	// cout << u << "\n";
	for (int v : adj[u]) {
		if (yes[v])
			continue;
		yes[v] = true;
		vis[v] = true;
		if (d > 1)
			dfs(v, d - 1);
	}
}

bool isMin(int d) {
	int s = 0;

	fill(vis.begin(), vis.end(), false);
	for (int n : ord) {
		if (vis[n])
			continue;
		if (++s > S)
			return false;
		
		for (int i = 0; prv[n] && i < d; ++i)
			n = prv[n];
		
		fill(yes.begin(), yes.end(), false);
		yes[n] = true;
		vis[n] = true;
		dfs(n, d);
	}
	return true;
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	cin >> N >> S;
	if (N == S)
		cout << 0 << "\n";
	else if (N == S - 1)
		cout << 1 << "\n";
	else {
		adj.resize(N + 1);
		prv.resize(N + 1);
		vis.resize(N + 1);
		yes.resize(N + 1);
		
		for (int u, v, i = 1; i < N; ++i) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		// for (int i = 0; i < n; ++i) {
			// cout << i << ": ";
			// for (int x : adj[i])
				// cout << x << " ";
			// cout << "\n";
		// }
		
		bfs();
		// for (int n : ord)
			// cout << n << " ";
		// cout << "\n";
		
		int l = 0, r = N / 2;
		while (l < r - 1) {
			int m = l + (r - l) / 2;
			// cout << m << "\n";
			(isMin(m) ? r : l) = m;
		}
		cout << r << "\n";
	}
}