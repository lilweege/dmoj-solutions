#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, w, d;
	cin >> n >> w >> d;
	
	vector<vector<int>> adj(n);
	for (int i = 0; i < w; ++i) {
		int a, b;
		cin >> a >> b;
		// one-way, backwards
		adj[b-1].push_back(a-1);
	}

	vector<int> walk(n, 2e5+1);
	walk[n-1] = 0;
	queue<int> q;
	q.push(n-1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int nxt : adj[cur])
			if (walk[nxt] > walk[cur] + 1) {
				walk[nxt] = walk[cur] + 1;
				q.push(nxt);
			}
	}

	multiset<int> times;
	vector<int> stations(n);
	auto time = [&](int t) {
		return walk[stations[t]] + t;
	};
	
	for (int i = 0; i < n; ++i) {
		cin >> stations[i];
		--stations[i];
		times.insert(time(i));
	}

	while (d--) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		
		times.erase(times.find(time(x)));
		times.erase(times.find(time(y)));
		swap(stations[x], stations[y]);
		times.insert(time(x));
		times.insert(time(y));
		
		int best = *times.begin();
		cout << best << "\n";
	}
}