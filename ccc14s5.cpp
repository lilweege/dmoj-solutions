#include <bits/stdc++.h>
#define Point pair<int, int>
#define Edge pair<int, Point>
using namespace std;

int getDist(Point p, Point q) {
  return pow(q.first - p.first, 2) + pow(q.second - p.second, 2);
}

int main() {
  int n;
  cin >> n;
  vector<int> best(n+1), prev(n+1), dist(n+1);
  vector<Point> points(n+1);
  vector<Edge> edges;
  for (int i = 1, x, y; i <= n; i++) {
	cin >> x >> y;
	points[i] = {x, y};
  }


  for (int x = 0; x <= n; x++)
	for (int y = x+1; y <= n; y++)
	  edges.push_back({getDist(points[x], points[y]), {x, y}});
  sort(edges.begin(), edges.end());


  for (auto &edge : edges) {
	int c = edge.first;
	int a = edge.second.first;
	int b = edge.second.second;
	if (c != dist[a]) {
	  dist[a] = c;
	  prev[a] = best[a];
	}
	if (c != dist[b]) {
	  dist[b] = c;
	  prev[b] = best[b];
	}

	if (a == 0) {
	  if (prev[b] > best[a])
		best[a] = prev[b];
	}
	else {
	  if (prev[b] + 1 > best[a])
		best[a] = prev[b] + 1;
	  if (prev[a] + 1 > best[b])
		best[b] = prev[a] + 1;
	}
  }

  cout << best[0] + 1;
}
