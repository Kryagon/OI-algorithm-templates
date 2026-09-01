// Luogu P3374
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int n, m;
int tree[MAXN];
int lowbit(int x){return x & -x;}
void add(int val, int i){
	while(i <= n){
		tree[i] += val;
		i += lowbit(i);
	}
}
int sum(int x){
	int sum = 0;
	while(x){
		sum += tree[x];
		x -= lowbit(x);
	}
	return sum;
}
int query(int x, int y = -1){return sum(y) - sum(x - 1);}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		int x;
		cin >> x;
		add(x, i);
	}
	while(m--){
		int op, x, y;
		cin >> op >> x >> y;
		if(op == 1)add(y, x);
		else cout << query(x, y) << '\n';
	}
	return 0;
	// Write By Kryagon
}
