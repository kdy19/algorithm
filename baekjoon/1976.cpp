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

int parent[201];

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
	int N, M;
	cin >> N >> M;

	for(int i=0; i<=N; ++i)
		parent[i]=i;
	
	int x;
	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=N; ++j) {
			cin >> x;
			if(x) 
				Union(i, j);
		}
	}

	vector<int> vis;
	for(int i=0; i<M; ++i) {
		cin >> x;
		vis.push_back(x);
	}

	bool ok=1;
	for(int i=0; i<M-1; ++i) {
		if(Find(vis[i])!=Find(vis[i+1])) {
			ok=0;
			break;
		}
	}

	if(ok) 
		cout << "YES";
	else
		cout << "NO";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	solve();

	return 0;
}

