#include <bits/stdc++.h>
using namespace std;

struct rect {
	int x1, x2, y1, y2;
};

ostream& operator << (ostream& os, const rect& r) {
	os << r.x1 << " " << r.x2 << " " << r.y1 << " " << r.y2;
	return os;
}

bool operator == (const rect& r1, const rect& r2) {
	return r1.x1 == r2.x1 && r1.x2 == r2.x2 && r1.y1 == r2.y1 && r1.y2 == r2.y2;
}

struct rect_hash {
	size_t operator()(const rect& r) const {
		return hash<int>()(r.x1) ^ hash<int>()(r.x2) ^ hash<int>()(r.y1) ^ hash<int>()(r.y2);
	}
};

unordered_map<rect, int, rect_hash> cache;
auto query(int a, int b, int c, int d) {
	rect r = { a, b, c, d };
	if (cache.find(r) != cache.end())
		return cache[r];
	cout << "? " << r << endl;
	int q;
	cin >> q;
	if (q == -1)
		exit(0);
	return cache[r] = q;
}

int main() {
#ifndef LOCAL
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#endif

	int n;
	cin >> n;
	
	vector<rect> found;
	found.reserve(n);
	auto done = [&found]() {
		cout << "!" << endl;
		for (rect r : found)
			cout << r << endl;
		exit(0);
	};

	int right = 1;
	int m = 1;
	while (found.size() < n) {
		int lo = m, hi = 1e9;
		int rq = 0;
		// leftmost search
		while (lo <= hi) {
			m = lo + (hi - lo) / 2;
			int q = query(1, m, 1, 1e9);
			if (q >= right) {
				hi = m - 1;
				rq = q - right + 1;
			}
			else {
				lo = m + 1;
			}
		}
		for (int x = 0; x < rq; ++x)
			found.emplace_back(0, hi + 1, 1, 1);
		right += rq;
	}
	
	for (rect& r : found) {
		int right = r.x2;
		int lo = 1, hi = right;
		while (lo <= hi) {
			int m = lo + (hi - lo) / 2;
			int q = query(m, right, 1, 1e9);
			int inside = 0;
			for (rect o : found) {
				if (o == r)
					continue;
				if (o.x1 >= m && o.x2 <= right)
					++inside;
			}
			if (q >= inside + 1) {
				lo = m + 1;
			}
			else {
				hi = m - 1;
			}
		}
		r.x1 = lo - 1;
	}

	bool is_subtask_3 = query(1, 1e9, 1, 1) == n;
	if (is_subtask_3)
		done();

	sort(found.begin(), found.end(),
		[] (const auto& a, const auto& b) {
			return (a.x2 - a.x1) < (b.x2 - b.x1);
		});

	for (int i = 0; i < n; ) {
		rect& r = found[i];
		int lo = 1, hi = 1e9;
		int tq = 0;
		while (lo <= hi) {
			int m = lo + (hi - lo) / 2;
			int q = query(r.x1, r.x2, 1, m);
			int inside = 0;
			for (rect o : found) {
				// if (o == r)
				// 	continue;
				if ((o.x2 - o.x1) > (r.x2 - r.x1))
					break;
				if (o.x1 >= r.x1 && o.x2 <= r.x2 && o.y2 <= m)
					++inside;
			}
			if (q >= inside) {
				hi = m - 1;
				tq = q - inside + 1;
			}
			else {
				lo = m + 1;
			}
		}
		for (int x = 0; x < tq; ++x)
			found[i++].y2 = hi + 1;
	}

	sort(found.begin(), found.end(),
		[] (const auto& a, const auto& b) {
			if ((a.x2 - a.x1) != (b.x2 - b.x1))
				return (a.x2 - a.x1) < (b.x2 - b.x1);
			return (a.y2 - a.y1) < (b.y2 - b.y1);
		});

	for (int i = 0; i < n; ++i) {
		rect& r = found[i];
		int top = r.y2;
		int lo = 1, hi = top;

		while (lo <= hi) {
			int m = lo + (hi - lo) / 2;
			int q = query(r.x1, r.x2, m, top);
			int inside = 0;
			for (rect o : found) {
				if (o == r)
					continue;
				if ((o.x2 - o.x1) > (r.x2 - r.x1))
					break;
				if (o.x1 >= r.x1 && o.x2 <= r.x2 && o.y1 >= m && o.y2 <= r.y2)
					++inside;
			}
			if (q >= inside + 1) {
				lo = m + 1;
			}
			else {
				hi = m - 1;
			}
		}
		r.y1 = lo - 1;
	}

	done();
}
