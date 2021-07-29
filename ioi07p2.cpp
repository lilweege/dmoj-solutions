#include <bits/stdc++.h>
using namespace std;

using point = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	vector<point> unsorted(n);
	vector<array<int, 4>> adj(n, {-1, -1, -1, -1});
	vector<array<int, 4>> wall(n, {-1, -1, -1, -1});
	for (auto& [x, y] : unsorted)
		cin >> x >> y;

	vector<int> indices(n);
	iota(indices.begin(), indices.end(), 0);
	sort(indices.begin(), indices.end(),
		[&unsorted] (const auto& l, const auto& r) {
			return unsorted[l] < unsorted[r];
		});

	int w;
	cin >> w;
	vector<int> time(w, -1);

	for (int i = 0; i < w; ++i) {
		int A, B;
		cin >> A >> B;
		--A, --B;
		auto [ax, ay] = unsorted[A];
		auto [bx, by] = unsorted[B];
		int dx = bx - ax;
		int dy = by - ay;
		// clockwise
		// 0, 1, 2, 3 -> u, r, d, l
		int a2b = dx ?
			((dx > 0) ? 1 : 3) :
			((dy > 0) ? 0 : 2);
		int b2a = (a2b + 2) % 4;
		adj[A][a2b] = B;
		adj[B][b2a] = A;
		wall[A][a2b] = i;
		wall[B][b2a] = i;
	}

	int rel_time = -1;
	auto keep_going = [&](int cur, int dir) {
		return wall[cur][dir] != -1 && (
			time[wall[cur][dir]] == -1 ||
			time[wall[cur][dir]] == rel_time);
	};

	vector<int> standing;
	for (int start : indices)
		for (int start_dir = 0; start_dir < 4; ++start_dir) {
			++rel_time;
			if (!keep_going(start, start_dir))
				continue;
			int cur = start;
			int dir = start_dir;
			do {
				int cur_wall = wall[cur][dir];
				if (time[cur_wall] == rel_time) {
					// water on both sides
					standing.push_back(cur_wall+1);
				}
				time[cur_wall] = rel_time;
				cur = adj[cur][dir];

				for (int rot = -1, old = dir; rot <= 2; ++rot) {
					dir = (old + rot) % 4;
					if (dir < 0) dir += 4;
					if (keep_going(cur, dir))
						break;
				}
			} while (cur != start);
		}


	cout << standing.size() << "\n";
	for (int x : standing)
		cout << x << "\n";
}
