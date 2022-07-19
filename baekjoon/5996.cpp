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

const int iInf=(1<<30);
const int d4x[4]={-1, 0, 1, 0};
const int d4y[4]={0, 1, 0, -1};

template<typename T>
void Swap(T &a, T &b) {
	T temp=a;
	a=b;
	b=temp;
}

struct Edge {
	int to;
	int cost;
	Edge(int to, int cost): to(to), cost(cost) {};
};

vector<Edge> A[2501];
int dist[2501];
bool chk[2501];

void solve() {
	int T, C, s, e;
	cin >> T >> C >> s >> e;
	for(int i=0; i<C; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		A[a].push_back(Edge(b, c));
		A[b].push_back(Edge(a, c));
	}

	for(int i=1; i<=T; ++i)
		dist[i]=iInf;

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, s));
	dist[s]=0;

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

	cout << dist[e];

    return;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

	solve();

    return 0;
}
