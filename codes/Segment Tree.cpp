// Luogu P3372
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Tree{int l, r, sum, mx, lazy;};
class SegmentTree{
private:
	vector<Tree>tree;
	vector<int>a;
	void pushup(int node){
		int left = node << 1, right = node << 1 | 1;
		tree[node].sum = tree[left].sum + tree[right].sum;
		tree[node].mx = max(tree[left].mx, tree[right].mx);
	}
	void pushdown(int node){
		if(!tree[node].lazy)return;
		int left = node << 1;
		int right = node << 1 | 1;
		int lz = tree[node].lazy;
		int ll = tree[left].r - tree[left].l + 1;
		int rl = tree[right].r - tree[right].l + 1;
		tree[left].sum += lz * ll;
		tree[left].mx += lz;
		tree[left].lazy += lz;
		tree[right].sum += lz * rl;
		tree[right].mx += lz;
		tree[right].lazy += lz;
		tree[node].lazy = 0;
	}
	void build(int node, int l, int r){
		tree[node].l = l;
		tree[node].r = r;
		tree[node].lazy = 0;
		if(l == r){
			tree[node].sum = a[l];
			tree[node].mx = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		int left = node << 1;
		int right = node << 1 | 1;
		build(left, l, mid);
		build(right, mid + 1, r);
		pushup(node);
	}
public:
	SegmentTree(const vector<int> & arr):a(arr){
		tree.resize(arr.size() * 4);
		build(1, 0, arr.size() - 1);
	}
	void update(int l, int r, int val, int node = 1){
		int tl = tree[node].l, tr = tree[node].r;
		if(l <= tl && tr <= r){
			tree[node].sum += val * (tr - tl + 1);
			tree[node].mx += val;
			tree[node].lazy += val;
			return;
		}
		pushdown(node);
		int mid = (tl + tr) >> 1;
		int left = node << 1;
		int right = node << 1 | 1;
		if(l <= mid)update(l, r, val, left);
		if(r > mid)update(l, r, val, right);
		pushup(node);
	}
	int query(int l, int r, int node = 1){
		int tl = tree[node].l, tr = tree[node].r;
		if(l <= tl && tr <= r)return tree[node].sum;
		pushdown(node);
		int mid = (tl + tr) >> 1;
		int left = node << 1;
		int right = node << 1 | 1;
		int res = 0;
		if(l <= mid)res += query(l, r, left);
		if(r > mid)res += query(l, r, right);
		return res;
	}
};
signed main(){
	int n, m;
	cin >> n >> m;
	vector<int>a(n + 1);
	for(int i = 1;i <= n;i++)cin >> a[i];
	SegmentTree seg(a);
	while(m--){
		int op;
		cin >> op;
		if(op == 1){
			int x, y, k;
			cin >> x >> y >> k;
			seg.update(x, y, k);
		}
		else{
			int x, y;
			cin >> x >> y;
			cout << seg.query(x, y) << endl;
		}
	}
	return 0;
	// Write By Kryagon
}
