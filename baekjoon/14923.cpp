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
const int d8x[8]={-1,-1,0,1,1,1,0,-1};
const int d8y[8]={0,1,1,1,0,-1,-1,-1};

int mapp[1001][1001];
int dist[1001][1001][2];

void solve() {
	int N, M;
	cin >> N >> M;

	int sx, sy, ex, ey;
	cin >> sx >> sy;
	cin >> ex >> ey;

	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=M; ++j) {
			cin >> mapp[i][j]; 
		}
	}

	queue<tuple<int, int, int>> Q;
	Q.push(make_tuple(sx, sy, 0));
	dist[sx][sy][0]=1;

	while(!Q.empty()) {
		int x, y, z;
		tie(x, y, z)=Q.front();
		Q.pop();

		if(x==ex&&y==ey) {
			cout << (dist[x][y][z]-1);
			return;
		}
		
		for(int k=0; k<4; ++k) {
			int nx=x+d4x[k];
			int ny=y+d4y[k];

			if(nx<0||ny<0||nx>N||ny>M) continue;
			if(mapp[nx][ny]==0&&dist[nx][ny][z]==0) {
				dist[nx][ny][z]=dist[x][y][z]+1;
				Q.push(make_tuple(nx, ny, z));
			}
			if(z==0&&mapp[nx][ny]==1&&dist[nx][ny][z+1]==0) {
				dist[nx][ny][z+1]=dist[x][y][z]+1;
				Q.push(make_tuple(nx, ny, z+1));
			}
		}
	}

	cout << -1;

}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	solve();

	return 0;
}

