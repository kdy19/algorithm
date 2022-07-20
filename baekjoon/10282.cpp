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

const int iInf=(1<<30);
const int MOD=1e9+7;
const int d4x[4]={1,-1,0,0};
const int d4y[4]={0,0,1,-1};

struct Edge {
	int to;
	int cost;
	Edge(int to, int cost): to(to), cost(cost) {};
};

int dist[100001];
bool chk[100001];

void solve() {
	int T;
	cin >> T;
	while(T--) {
		vector<Edge> A[100001];
		int n, d, c;
		cin >> n >> d >> c;

		for(int i=1; i<=n; ++i) {
			dist[i]=iInf;
			chk[i]=0;
		}

		for(int i=0; i<d; ++i) {
			int u, v, w;
			cin >> u >> v >> w;

			A[v].push_back(Edge(u, w));
		}
		
		priority_queue<pair<int, int>> pq;
		pq.push(make_pair(0, c));
		dist[c]=0;

		while(!pq.empty()) {
			auto p=pq.top();
			pq.pop();
			int x=p.second;

			if(chk[x]) continue;
			chk[x]=1;

			for(int i=0; i<A[x].size(); ++i) {
				int y=A[x][i].to;
				if(dist[y]>dist[x]+A[x][i].cost) {
					dist[y]=dist[x]+A[x][i].cost;
					pq.push(make_pair(-dist[y], y));
				}
			}
		}

		int cnt=0, maxN=-1;
		for(int i=1; i<=n; ++i) {
			if(dist[i]!=iInf) {
				++cnt;
				if(maxN<dist[i])
					maxN=dist[i];
			}
		}
		cout << cnt << ' ' << maxN << '\n';
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	solve();

	return 0;
}
