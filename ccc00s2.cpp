#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	vector<float> flow(n);
	for (int i = 0; i < n; ++i)
		cin >> flow[i];
	
	while (true) {
		int q;
		cin >> q;
		
		// split
		if (q == 99) {
			int whichSplit;
			float percentageFlow;
			cin >> whichSplit >> percentageFlow;
			--whichSplit;
			percentageFlow /= 100.0f;
			
			float l = flow[whichSplit] * percentageFlow;
			float r = flow[whichSplit] - l;
			flow[whichSplit] = l;
			flow.insert(flow.begin() + whichSplit + 1, r);
		}
		// join
		else if (q == 88) {
			int whichJoin;
			cin >> whichJoin;
			--whichJoin;
			flow[whichJoin] += flow[whichJoin + 1];
			flow.erase(flow.begin() + whichJoin + 1);
		}
		else break;
	}
	
	for (float x : flow)
		cout << round(x) << " ";
}