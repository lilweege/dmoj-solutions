#include <bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> con(50);
void insert(int x, int y) {
	con[x].insert(y);
	con[y].insert(x);
}
void erase(int x, int y) {
	con[x].erase(y);
	con[y].erase(x);
}

void init() {
	insert(2, 6);
	insert(1, 6);
	insert(6, 7);
	insert(7, 8);
	insert(3, 4);
	insert(4, 5);
	insert(3, 6);
	insert(4, 6);
	insert(5, 6);
	insert(3, 5);
	insert(3, 15);
	insert(8, 9);
	insert(9, 10);
	insert(9, 12);
	insert(10, 11);
	insert(11, 12);
	insert(12, 13);
	insert(13, 15);
	insert(13, 14);
	insert(16, 17);
	insert(16, 18);
	insert(17, 18);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	init();
	
	
	char c;
	int x, y;
	while (true) {
		cin >> c;
		
		if (c == 'i') {
			cin >> x >> y;
			insert(x, y);
		}
		else if (c == 'd') {
			cin >> x >> y;
			erase(x, y);
		}
		else if (c == 'n') {
			cin >> x;
			cout << con[x].size() << endl;
		}
		else if (c == 'f') {
			cin >> x;
			unordered_set<int> t;
			for (int y : con[x])
				for (int e : con[y])
					if (e != x && 
						con[x].find(e) == con[x].end() &&
						t.find(e) == t.end())
						t.insert(e);
			cout << t.size() << endl;
		}
		else if (c == 's') {
			cin >> x >> y;
			
			// lol I suck
			vector<int> b;
			int d = 0;
			bool f = false;
			unordered_set<int> vis;
			vis.insert(x);
			queue<int> q;
			q.push(x);
			while (q.size()) {
				// each breadth
				while (q.size()) {
					b.push_back(q.front());
					q.pop();
				}
				while (b.size()) {
					int u = b.back();
					b.pop_back();
					if (u == y) {
						f = true;
						break;
					}
					for (int v : con[u]) {
						if (vis.find(v) == vis.end()) {
							q.push(v);
							vis.insert(v);
						}
					}
				}
				if (!f)
					++d;
			}
			if (f)
				cout << d << endl;
			else
				cout << "Not connected" << endl;
		}
		else break;
	}
}