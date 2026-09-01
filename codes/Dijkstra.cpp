// Luogu P4779
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, s;
	cin >> n >> m >> s;
	vector<vector<pair<int, int>>>g(n + 1);
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}
	vector<int>dst(n + 1, INF);
	vector<bool>vis(n + 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	q.push(make_pair(0, s));
	dst[s] = 0;
	while(!q.empty()){
		auto p = q.top();
		int d = p.first, u = p.second;
		q.pop();
		if(vis[u] || dst[u] != d)continue;
		vis[u] = true;
		for(auto e:g[u]){
			int to = e.first, w = e.second;
			if(dst[u] + w < dst[to]){
				dst[to] = dst[u] + w;
				q.push(make_pair(dst[to], to));
			}
		}
	}
	for(int i = 1;i <= n;i++)cout << dst[i] << ' ';
	return 0;
  // Write By Kryagon
}
