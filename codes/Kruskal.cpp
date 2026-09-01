// Luogu P3366
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5005;
int fa[MAXN], rk[MAXN];
int find(int x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
void unite(int x, int y){
	int fx = find(x), fy = find(y);
	if(rk[fx] < rk[fy])fa[fx] = fy;
	else if(rk[fx] > rk[fy])fa[fy] = fx;
	else{
		fa[fx] = fy;
		rk[fy]++;
	}
}
struct Edge{int u, v, w;};
bool compare(Edge x, Edge y){return x.w < y.w;}
void Kruskal(const vector<Edge> & edge, int n){
	int cnt = 0, sum = 0;
	for(auto i:edge){
		int u = find(i.u), v = find(i.v);
		if(u != v){
			unite(u, v);
			cnt++;
			sum += i.w;
			if(cnt == n - 1)break;
		}
	}
	if(cnt == n - 1)cout << sum << endl;
	else cout << "orz" << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<Edge>edge(m);
	for(auto & i:edge)cin >> i.u >> i.v >> i.w;
	for(int i = 1;i <= n;i++)fa[i] = i;
	sort(edge.begin(), edge.end(), compare);
	Kruskal(edge, n);
	return 0;
	// Write by Kryagon
}
