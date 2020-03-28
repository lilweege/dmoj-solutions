#include "inaho.h"
#include <bits/stdc++.h>
#define MAXN 500001
#define pi pair<int, int>
using namespace std;


int par[MAXN], sz[MAXN];
stack<pi> st;


int Find(int i) {
  	if (par[i] == i)
    	return i;
	return Find(par[i]);
}

void Init(int n) {
    for (int i = 0; i <= n; i++) {
		par[i] = i;
        sz[i] = 1;
	}
}

void AddEdge(int u, int v) {
    u = Find(u);
    v = Find(v);
    st.push({u, v});
	if (u != v) {
        if (sz[u] < sz[v]) {
            sz[v] += sz[u];
            par[u] = par[v];
        }
        else {
            sz[u] += sz[v];
            par[v] = par[u];
        }
    }
}

void RemoveLastEdge() {
    pi p = st.top(); st.pop();
	int u = p.first;
	int v = p.second;
	if (u != v) {
		if (par[u] == u) {
			sz[u] -= sz[v];
			par[v] = v;
		}
		else {
			sz[v] -= sz[u];
			par[u] = u;
		}
    }
}

int GetSize(int u) {
    return sz[Find(u)];
}
