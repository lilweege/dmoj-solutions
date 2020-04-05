#include <bits/stdc++.h>
using namespace std;

struct connection {
	int conns, points;
	bool operator < (const connection& o) const {
		if (conns == o.conns)
			return points < o.points;
		return conns > o.conns;
	}
};

int main() {
	int n;
	cin >> n;


	int friends = 0;
	vector<connection> connections;
	for (int a, b; n; n--) {
		cin >> a >> b;
		if (a <= friends || b == 0)
			friends++;
		else
			connections.push_back({ a, b });
	}
	sort(connections.begin(), connections.end());
	reverse(connections.begin(), connections.end());

	int points = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = connections.size() - 1; i >= 0; i--) {
		q.push(connections[i].points);
		if (connections[i].conns > friends + i) {
			points += q.top(); q.pop();
			friends++;
		}
	}
	cout << points;
}
