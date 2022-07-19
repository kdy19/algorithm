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

int mapp[501][501];
int dist[501][501];

template<typename T>
void Swap(T &a, T &b) {
	T temp=a;
	a=b;
	b=temp;
}

void solve() {
	int N, M;
	cin >> N;
	for(int i=0; i<N; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		if(x1>x2) Swap(x1, x2);
		if(y1>y2) Swap(y1, y2);

		for(int j=x1; j<=x2; ++j) {
			for(int k=y1; k<=y2; ++k)
				mapp[j][k]=1;
		}
	}

	cin >> M;
	for(int i=0; i<M; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		if(x1>x2) Swap(x1, x2);
		if(y1>y2) Swap(y1, y2);

		for(int j=x1; j<=x2; ++j) {
			for(int k=y1; k<=y2; ++k)
				mapp[j][k]=2;
		}
	}

	for(int i=0; i<501; ++i) {
		for(int j=0; j<501; ++j)
			dist[i][j]=iInf;
	}

	queue<pair<int, int>> Q;
	Q.push(make_pair(0, 0));
	dist[0][0]=0;

	while(!Q.empty()) {
		int x, y;
		tie(x, y)=Q.front();
		Q.pop();

		for(int k=0; k<4; ++k) {
			int nx=x+d4x[k];
			int ny=y+d4y[k];

			if(nx<0||ny<0||nx>500||ny>500) continue;
			if(mapp[nx][ny]==2) continue;
			if(mapp[nx][ny]==1) {
				if(dist[nx][ny]>dist[x][y]+1) {
					dist[nx][ny]=dist[x][y]+1;
					Q.push(make_pair(nx, ny));
				}
			}
			if(mapp[nx][ny]==0) {
				if(dist[nx][ny]>dist[x][y]) {
					dist[nx][ny]=dist[x][y];
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}

	if(dist[500][500]==iInf) 
		cout << -1;
	else
		cout << dist[500][500];

    return;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

	solve();

    return 0;
}
