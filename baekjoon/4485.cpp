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
	Edge(int to, int cost) : to(to), cost(cost) {};
};

int mapp[125][125];
int dist[125][125];

void solve() {
	int idx=1;

	while(true) {
		int N;
		cin >> N;
		if(N==0) break;
		cout << "Problem " << idx << ": ";
		for(int i=0; i<N; ++i) {
			for(int j=0; j<N; ++j) {
				cin >> mapp[i][j];
				dist[i][j]=iInf;
			}
		}

		queue<pair<int, int>> Q;
		Q.push(make_pair(0, 0));
		dist[0][0]=mapp[0][0];

		while(!Q.empty()) {
			int x, y;
			tie(x, y)=Q.front();
			Q.pop();

			for(int k=0; k<4; ++k) {
				int nx=x+d4x[k];
				int ny=y+d4y[k];

				if(nx<0||ny<0||nx>=N||ny>=N) continue;
				if(dist[nx][ny]>dist[x][y]+mapp[nx][ny]) {
					dist[nx][ny]=dist[x][y]+mapp[nx][ny];
					Q.push(make_pair(nx, ny));
				}
			}
		}
		cout << dist[N-1][N-1] << '\n';
		++idx;
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	solve();

	return 0;
}
