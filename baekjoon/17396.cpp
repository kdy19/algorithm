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

const int d4x[4]={-1, 0, 1, 0};
const int d4y[4]={0, 1, 0, -1};

ll inf=9223372036854775807;

struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) {}
};

vector<Edge> A[100001];
int stat[100001];
ll dist[100001];
bool chk[100001];

void solve() {
	int N, M;
	cin >> N >> M;

	for(int i=0; i<N; ++i)
		cin >> stat[i];

	for(int i=0; i<M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		A[a].push_back(Edge(b, c));
		A[b].push_back(Edge(a, c));
	}

	for(int i=0; i<N; ++i)
		dist[i]=inf;

	dist[0]=0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 0));

	while(!pq.empty()) {
		auto p=pq.top();
		pq.pop();
		int x=p.second;
		if(chk[x]) continue;
		chk[x]=1;

		for(int i=0; i<A[x].size(); ++i) {
			int y=A[x][i].to;
			if(stat[y]==0||y==N-1) {
				if(dist[y]>dist[x]+A[x][i].cost) {
					dist[y]=dist[x]+A[x][i].cost;
					pq.push(make_pair(-dist[y], y));
				}
			}
		}
	}

	if(dist[N-1]==inf)
		cout << -1;
	else
		cout << dist[N-1];

    return;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

	solve();

    return 0;
}
