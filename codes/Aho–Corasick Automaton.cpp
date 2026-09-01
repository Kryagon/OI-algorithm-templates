// Luogu P3808
#include <bits/stdc++.h>
using namespace std;
struct Trie{
	Trie * child[26];
	Trie * fail;
	int cnt;
	bool vis, del;
	Trie():fail(nullptr), cnt(0), vis(false), del(false){memset(child, 0, sizeof(child));}
};
class ACautomaton{
private:
	Trie * root;
	void clear(Trie * node){
		if(!node || node -> del)return;
		node -> del = true;
		for(int i = 0;i < 26;i++)clear(node -> child[i]);
		delete node;
	}
public:
	ACautomaton():root(new Trie()){}
	~ACautomaton(){clear(root);}
	void insert(const string & s){
		Trie * p = root;
		for(char c:s){
			int idx = c - 'a';
			if(!p -> child[idx])p -> child[idx] = new Trie();
			p = p -> child[idx];
		}
		p -> cnt++;
	}
	void buildfail(){
		root -> fail = root;
		queue<Trie*>q;
		for(int i = 0;i < 26;i++){
			if(root -> child[i]){
				root -> child[i] -> fail = root;
				q.push(root -> child[i]);
			}
			else root -> child[i] = root;
		}
		while(!q.empty()){
			auto p = q.front();
			q.pop();
			for(int i = 0;i < 26;i++){
				if(p -> child[i]){
					p -> child[i] -> fail = p -> fail -> child[i];
					q.push(p -> child[i]);
				}
				else p -> child[i] = p -> fail -> child[i];
			}
		}
	}
	int query(const string & s){
		int ans = 0;
		Trie * p = root;
		for(char c:s){
			p = p -> child[c - 'a'];
			Trie * tmp = p;
			while(tmp != root && !tmp -> vis){
				ans += tmp -> cnt;
				tmp -> vis = true;
				tmp = tmp -> fail;
			}
		}
		return ans;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	ACautomaton ac;
	while(n--){
		string s;
		cin >> s;
		ac.insert(s);
	}
	ac.buildfail();
	string s;
	cin >> s;
	cout << ac.query(s) << endl;
	return 0;
    // Write by Kryagon
}
