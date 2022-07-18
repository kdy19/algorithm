#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;

#define ll long long

const int inf=(1<<30);
const int d4x[4]={-1, 0, 1, 0};
const int d4y[4]={0, 1, 0, -1};

struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) {}
};

vector<Edge> A[101];
int item[101];
int dist[101];
bool chk[101];

void solve() {
	int n, m, r;
	cin >> n >> m >> r;
	for(int i=1; i<=n; ++i) 
		cin >> item[i];

	for(int i=0; i<r; ++i) {
		int a, b, l;
		cin >> a >> b >> l;
		A[a].push_back(Edge(b, l));
		A[b].push_back(Edge(a, l));
	}

	int ans=-1;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) 
			dist[j]=inf; 
		memset(chk, 0, sizeof(chk));

		dist[i]=0;
		priority_queue<pair<int, int>> pq;
		pq.push(make_pair(0, i));

		while(!pq.empty()) {
			auto p=pq.top();
			pq.pop();
			int x=p.second;
			if(chk[x]) continue;
			chk[x]=1;

			for(int j=0; j<A[x].size(); ++j) {
				int y=A[x][j].to;
				if(dist[y]>dist[x]+A[x][j].cost) {
					dist[y]=dist[x]+A[x][j].cost;
					pq.push(make_pair(-dist[y], y));
				}
			}
		}

		int tmp=0;
		for(int j=1; j<=n; ++j) {
			if(dist[j]<=m)
				tmp+=item[j];
		}
		if(tmp>ans)
			ans=tmp;
	}

	cout << ans;
	
    return;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

	solve();

    return 0;
}
