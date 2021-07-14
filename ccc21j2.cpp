#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string winner;
	int highestBid = -1;
	for (int i = 0; i < n; ++i) {
		string name;
		int bid;
		cin >> name >> bid;
		
		if (highestBid < bid) {
			highestBid = bid;
			winner = name;
		}
	}
	
	cout << winner << "\n";
}