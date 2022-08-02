#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

#define ll long long

const int iInf=(int)1e9;
const int MOD=(int)1e9;
const int d4x[4]={1,-1,0,0};
const int d4y[4]={0,0,1,-1};
const int d8x[8]={-1,-1,0,1,1,1,0,-1};
const int d8y[8]={0,1,1,1,0,-1,-1,-1};

int parent[1000001];

int Find(int x) {
	if(x==parent[x]) 
		return x;
	else
		return parent[x]=Find(parent[x]);
}

void Union(int x, int y) {
	x=Find(x);
	y=Find(y);

	if(x==y) return;
	parent[y]=x;
}

void solve() {
	int T, idx=1;
	cin >> T;

	while(T--) {
		cout << "Scenario " << idx << ":\n";
		int n, k;
		cin >> n >> k;

		for(int i=0; i<=n; ++i) 
			parent[i]=i;

		for(int i=0; i<k; ++i) {
			int a, b;
			cin >> a >> b;
			Union(a, b);
		}

		int m;
		cin >> m;
		for(int i=0; i<m; ++i) {
			int u, v;
			cin >> u >> v;
			if(Find(u)!=Find(v))
				cout << "0\n";
			else
				cout << "1\n";

		}
		++idx;
		cout << '\n';
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	solve();

	return 0;
}

