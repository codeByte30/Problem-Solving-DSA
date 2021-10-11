#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
// vector<int>adj[100005];
vector<pair<int, int>>adj[100005];
int vis[100005];

// void topoSort(int node, stack<int>&s) {
// 	vis[node] = 1;
// 	for (auto it : adj[node]) {
// 		if (!vis[it])
// 		{
// 			topoSort(it, s);
// 		}
// 	}
// 	s.push(node);
// }

void dijisktra(int n, int src) {
	vector<int>dist(n + 1, INT_MAX);
	dist[src] = 0;
	vector<int>par(n + 1, -1);
	par[src] = src;
	//{dist,node}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({0, src});
	while (!pq.empty()) {
		int node = pq.top().second;
		int dis = pq.top().first;
		pq.pop();
		for (auto it : adj[node]) {
			int wt = it.second;
			int curr_node = it.first;
			if (dis + wt < dist[curr_node]) {
				dist[curr_node] = dis + wt;
				pq.push({dist[curr_node], curr_node});
				par[curr_node] = node;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << i << "------>" << dist[i] << endl;
	}

	int x = n;
	vector<int>path;
	while (x != 1) {
		path.push_back(x);
		x = par[x];
	}
	path.push_back(1);
	reverse(path.begin(), path.end());
	for (auto x : path) {
		cout << x << " ";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n, m;
	cin >> n >> m;
	// while (m--) {
	// 	int u, v;
	// 	cin >> u >> v;
	// 	adj[u].push_back(v);
	// }

	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	dijisktra(n, 1);
	// stack<int>s;
	// for (int i = 1; i <= n; i++) {
	// 	if (!vis[i]) {
	// 		topoSort(i, s);
	// 	}
	// }

	// while (!s.empty()) {
	// 	cout << s.top() << " ";
	// 	s.pop();
	// }


	return 0;
}


// 5 6
// 1 2 2
// 2 5 5
// 2 3 4
// 1 4 1
// 4 3 3
// 3 5 1