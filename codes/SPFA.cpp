// Luogu B3601
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
struct Edge{int to, w;};
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<Edge>>g(n + 1);
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}
	vector<int>dst(n + 1, INF);
	vector<bool>inque(n + 1, false);
	queue<int>q;
	dst[1] = 0;
	inque[1] = true;
	q.push(1);
	while(!q.empty()){
		int p = q.front();
		q.pop();
		inque[p] = false;
		for(auto e:g[p]){
			int to = e.to, w = e.w;
			if(dst[p] != INF && dst[p] + w < dst[to]){
				dst[to] = dst[p] + w;
				inque[to] = true;
				q.push(to);
			}
		}
	}
	for(int i = 1;i <= n;i++)cout << (dst[i] == INF ? -1 : dst[i]) << ' ';
	return 0;
  // Write By Kryagon
}
