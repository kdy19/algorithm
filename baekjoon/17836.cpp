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

int mapp[101][101];
int dist[101][101][2];

void solve() {
	int N, M, T;
	cin >> N >> M >> T;

	for(int i=0; i<N; ++i) {
		for(int j=0; j<M; ++j) {
			cin >> mapp[i][j];
		}
	}

	for(int i=0; i<N; ++i) {
		for(int j=0; j<M; ++j) {
			dist[i][j][0]=iInf;
			dist[i][j][1]=iInf;
		}
	}

	queue<tuple<int, int, int>> Q;
	Q.push(make_tuple(0, 0, 0));
	dist[0][0][0]=0;

	while(!Q.empty()) {
		int x, y, ok;
		tie(x, y, ok)=Q.front();
		Q.pop();

		for(int k=0; k<4; ++k) {
			int nx=x+d4x[k];
			int ny=y+d4y[k];

			if(nx<0||ny<0||nx>=N||ny>=M) continue;
			if(mapp[nx][ny]==2) {
				if(dist[nx][ny][1]>dist[x][y][0]+1) {
					dist[nx][ny][1]=dist[x][y][0]+1;
					Q.push(make_tuple(nx, ny, 1));
				}
			}
			if(mapp[nx][ny]==0) {
				if(dist[nx][ny][ok]>dist[x][y][ok]+1) {
					Q.push(make_tuple(nx, ny, ok));
					dist[nx][ny][ok]=dist[x][y][ok]+1;
				}
			}
			if(mapp[nx][ny]==1&&ok) {
				if(dist[nx][ny][ok]>dist[x][y][ok]+1) {
					Q.push(make_tuple(nx, ny, ok));
					dist[nx][ny][ok]=dist[x][y][ok]+1;
				}
			}
		}	
	}

	int ans=min(dist[N-1][M-1][0], dist[N-1][M-1][1]);

	if(ans>T)
		cout << "Fail";
	else
		cout << ans;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	solve();

	return 0;
}

