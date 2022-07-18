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

vector<Edge> A[1001];
int inDist[1001];
int outDist[1001];
int tmpDist[1001];
int chk[1001];

void solve() {
	int N, M, X;
	cin >> N >> M >> X;
	for(int i=0; i<M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		A[u].push_back(Edge(v, w));
	}

	for(int i=1; i<=N; ++i) {
		inDist[i]=inf;
		outDist[i]=inf;
	}

	inDist[X]=0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, X));

	while(!pq.empty()) {
		auto p=pq.top();
		pq.pop();
		int x=p.second;
		if(chk[x]) continue;
		chk[x]=1;

		for(int i=0; i<A[x].size(); ++i) {
			int y=A[x][i].to;
			if(inDist[y]>inDist[x]+A[x][i].cost) {
				inDist[y]=inDist[x]+A[x][i].cost;
				pq.push(make_pair(-inDist[y], y));
			}
		}
	}

	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=N; ++j)
			tmpDist[j]=inf;
		memset(chk, 0, sizeof(chk));
		tmpDist[i]=0;
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
				if(tmpDist[y]>tmpDist[x]+A[x][j].cost) {
					tmpDist[y]=tmpDist[x]+A[x][j].cost;
					pq.push(make_pair(-tmpDist[y], y));
				}
			}
		}
		outDist[i]=tmpDist[X];
	}

	int ans=-1;
	for(int i=1; i<=N; ++i) {
		if(inDist[i]+outDist[i]>ans) 
			ans=inDist[i]+outDist[i];
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
