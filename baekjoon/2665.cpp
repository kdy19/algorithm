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

int mapp[50][50];
int dist[50][50];
bool chk[50][50];

void solve() {
	int N;
	cin >> N;
	for(int i=0; i<N; ++i) {
		string s;
		cin >> s;
		for(int j=0; j<s.size(); ++j)
			mapp[i][j]=s[j]-'0';
	}

	for(int i=0; i<N; ++i) {
		for(int j=0; j<N; ++j)
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

			if(nx<0||ny<0||nx>=N||ny>=N) continue;
			if(mapp[nx][ny]==0) {
				if(dist[nx][ny]>dist[x][y]+1) {
					dist[nx][ny]=dist[x][y]+1;
					Q.push(make_pair(nx, ny)); 
				}
			}
			else if(mapp[nx][ny]==1) {
				if(dist[nx][ny]>dist[x][y]) {
					dist[nx][ny]=dist[x][y];
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}

	cout << dist[N-1][N-1];


    return;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

	solve();

    return 0;
}
