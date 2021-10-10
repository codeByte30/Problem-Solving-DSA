#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int>adj[100005];
int vis[100005];
void bfs(int src) {
	queue<int>q;

	q.push(src);
	vis[src] = 1;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " ";
		for (auto it : adj[node]) {
			if (!vis[it]) {
				q.push(it);
				vis[it] = 1;
			}
		}
	}
}
void dfs(int node) {
	vis[node] = 1;
	cout << node << " ";
	for (auto it : adj[node]) {
		if (!vis[it]) {
			dfs(it);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, e;
	cin >> n >> e;
	while (e--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int components  = 0;
	// for (int i = 1; i <= n; i++) {
	// 	if (vis[i] == 0) {
	// 		// components++;
	// 		// bfs(i);
	// 	}
	// }

	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			components++;
			dfs(i);
		}
	}
	cout << endl;

	cout << components << endl;






	return 0;
}


// input

// 9 8
// 1 2
// 2 3
// 3 4
// 2 5
// 5 6
// 3 6
// 5 7
// 8 9