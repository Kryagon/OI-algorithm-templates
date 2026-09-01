// Luogu B3601
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
struct Edge{int u, v, w;};
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
    cin >> n >> m;
    vector<Edge>edge;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    vector<int>dst(n + 1, INF);
    dst[1] = 0;
    for(int i = 0;i < n - 1;i++){
        bool upd = false;
        for(auto e:edge){
            int u = e.u, v = e.v, w = e.w;
            if(dst[u] != INF && dst[u] + w < dst[v]){
                dst[v] = dst[u] + w;
                upd = true;
            }
        }
        if(!upd)break;
    }
    for(int i = 1;i <= n;i++)cout << (dst[i] == INF ? -1 : dst[i]) << ' ';
	return 0;
    // Write By Kryagon
}
