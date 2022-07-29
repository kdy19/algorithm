#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define ll long long

const int iInf=(int)1e9;
const int MOD=1e9+7;
const int d4x[4]={1,-1,0,0};
const int d4y[4]={0,0,1,-1};
const int d8x[8]={-1,-1,0,1,1,1,0,-1};
const int d8y[8]={0,1,1,1,0,-1,-1,-1};

vector<int> A[20001];
int chk[20001];

void bfs(int i) {
	int c=1;
	queue<int> Q;
	Q.push(i);
	chk[i]=c;

	while(!Q.empty()) {
		int x=Q.front();
		Q.pop();

		if(chk[x]==1)
			c=2;
		if(chk[x]==2)
			c=1;

		for(int i=0; i<A[x].size(); ++i) {
			int nx=A[x][i];
			if(!chk[nx]) {
				chk[nx]=c;
				Q.push(nx);
			}
		}
	}
}

bool check(int V) {
	for(int i=1; i<=V; ++i) {
		for(int j=0; j<A[i].size(); ++j) {
			if(chk[i]==chk[A[i][j]])
				return 0;
		}
	}
	return 1;
}

void solve() {
	int K, V, E;
	cin >> K;
	while(K--) {
		cin >> V >> E;
		for(int i=0; i<E; ++i) {
			int a, b; 
			cin >> a >> b;
			A[a].push_back(b);
			A[b].push_back(a);
		}

		for(int i=1; i<=V; ++i) {
			if(!chk[i]) bfs(i);
		}

		if(check(V))
			cout << "YES\n";
		else
			cout << "NO\n";

		for(int i=1; i<=V; ++i) 
			A[i].clear();
		memset(chk, 0, sizeof(chk));

	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	solve();

	return 0;
}

