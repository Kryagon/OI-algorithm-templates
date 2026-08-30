#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
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
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)fa[i] = i;
    while(m--){
        int z, x, y;
        cin >> z >> x >> y;
        if(z == 1)unite(x, y);
        else{
            if(find(x) == find(y))cout << "Y\n";
            else cout << "N\n";
        }
    }
    return 0;
}
