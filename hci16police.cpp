#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100001
#define INF LONG_MAX

int main() {
  ll cheapest[MAXN], criminals[MAXN];
  int n, h;
  cin >> n >> h;
  for (int i = 1; i <= n; i++)
	cin >> criminals[i];

  for (int a = 1, pb = 0; a <= n; a++) {
	cheapest[a] = INF;
	for (int b = pb; b < a; b++) {
	  ll spent = h + cheapest[b] + pow((criminals[a] - criminals[b+1]), 2);
	  if (spent < cheapest[a]) {
		cheapest[a] = spent;
		pb = b;
	  }
	}
  }
  cout << cheapest[n];
}
