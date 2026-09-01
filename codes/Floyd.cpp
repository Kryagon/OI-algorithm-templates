// Luogu B3647
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int>>dst(n + 1, vector<int>(n + 1, INF));
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i == j)dst[i][j] = 0;
		}
	}
	for(int i = 1;i <= m;i++){
		int u, v, w;
		cin >> u >> v >> w;
		dst[u][v] = min(dst[u][v], w);
		dst[v][u] = min(dst[v][u], w);
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			if(dst[i][k] == INF)continue;
			for(int j = 1;j <= n;j++){
				if(dst[i][k] + dst[k][j] < dst[i][j])dst[i][j] = dst[i][k] + dst[k][j];
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++)cout << dst[i][j] << ' ';
		cout << '\n';
	}
	return 0;
	// Write By Kryagon
}
