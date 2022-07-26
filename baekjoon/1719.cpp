#include <algorithm>
#include <iostream>
#include <string.h>
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

int dist[201][201];
int ans[201][201];

void solve() {
	int n, m;
	cin >> n >> m;

	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			if(i==j) 
				dist[i][j]=0;
			else 
				dist[i][j]=iInf;
		}
	}

	for(int i=0; i<m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;

		dist[u][v]=w;
		ans[u][v]=v;
		dist[v][u]=w;
		ans[v][u]=u;
	}

	for(int k=1; k<=n; ++k) {
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=n; ++j) {
				if(dist[i][j]>dist[i][k]+dist[k][j]) {
					dist[i][j]=dist[i][k]+dist[k][j];
					ans[i][j]=ans[i][k];
				}
			}
		}
	}

	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j)
			cout << dist[i][j] << ' ';
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

