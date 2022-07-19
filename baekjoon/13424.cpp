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

struct Edge {
	int to;
	int cost;
	Edge(int to, int cost): to(to), cost(cost) {};
};

int N, M, K;
int res[101];
int dist[101];
bool pos[101];
bool chk[101];

void reset() {
	for(int i=1; i<=N; ++i) {
		dist[i]=iInf;
		chk[i]=0;
	}
}

void solve() {
	int T;
	cin >> T;
	while(T--) {
		vector<Edge> A[101];
		memset(pos, 0, sizeof(pos));
		cin >> N >> M;
		for(int i=0; i<M; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			A[a].push_back(Edge(b, c));
			A[b].push_back(Edge(a, c));
		}

		cin >> K;
		for(int i=1; i<=K; ++i) {
			int x;
			cin >> x;
			pos[x]=1;
		}
		
		int ans=iInf;
		for(int i=1; i<=N; ++i) {
			reset();
			priority_queue<pair<int, int>> pq;
			pq.push(make_pair(0, i));
			dist[i]=0;
			
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
			for(int j=1; j<=N; ++j) {
				if(pos[j]) 
					tmp+=dist[j];
			}

			if(ans>tmp)
				ans=tmp;

			res[i]=tmp;
		}

		for(int i=1; i<=N; ++i) {
			if(res[i]==ans) {
				cout << i << '\n';
				break;
			}
		}
	}

    return;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

	solve();

    return 0;
}
