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
int fdist[1001][1001];
int jdist[1001][1001];

void solve() {
	int R, C;
	cin >> R >> C;

	for(int i=0; i<R; ++i) {
		for(int j=0; j<C; ++j) {
			jdist[i][j]=iInf;
			fdist[i][j]=iInf;
		}
	}

	int sx, sy;
	queue<pair<int, int>> Q;
	for(int i=0; i<R; ++i) {
		string s;
		cin >> s;
		for(int j=0; j<s.size(); ++j) {
			mapp[i][j]=s[j];
			
			if(mapp[i][j]=='J') {
				sx=i;
				sy=j;
				jdist[i][j]=0;
				mapp[i][j]='.';
			}
			if(mapp[i][j]=='F') {
				Q.push(make_pair(i, j));
				fdist[i][j]=0;
				mapp[i][j]='.';
			}
		}
	}

	while(!Q.empty()) {
		int x, y;
		tie(x, y)=Q.front();
		Q.pop();

		for(int k=0; k<4; ++k) {
			int nx=x+d4x[k];
			int ny=y+d4y[k];

			if(nx<0||ny<0||nx>=R||ny>=C) continue;
			if(mapp[nx][ny]=='#') continue;
			if(fdist[nx][ny]>fdist[x][y]+1) {
				fdist[nx][ny]=fdist[x][y]+1;
				Q.push(make_pair(nx, ny));
			}
		}
	}

	Q.push(make_pair(sx, sy));
	while(!Q.empty()) {
		int x, y;
		tie(x, y)=Q.front();
		Q.pop();

		for(int k=0; k<4; ++k) {
			int nx=x+d4x[k];
			int ny=y+d4y[k];

			if(nx<0||ny<0||nx>=R||ny>=C) continue;
			if(mapp[nx][ny]=='#') continue;
			if(jdist[nx][ny]>jdist[x][y]+1) {
				jdist[nx][ny]=jdist[x][y]+1;
				Q.push(make_pair(nx, ny));
			}
		}
	}

	int ans=iInf;
	for(int i=0; i<C; ++i) {
		if(mapp[0][i]=='.') {
			if(fdist[0][i]>jdist[0][i]) {
				if(ans>jdist[0][i])
					ans=jdist[0][i];
			}
		}
		if(mapp[R-1][i]=='.') {
			if(fdist[R-1][i]>jdist[R-1][i]) {
				if(ans>jdist[R-1][i])
					ans=jdist[R-1][i];
			}
		}
	}

	for(int i=0; i<R; ++i) {
		if(mapp[i][0]=='.') {
			if(fdist[i][0]>jdist[i][0]) {
				if(ans>jdist[i][0])
					ans=jdist[i][0];
			}
		}
		if(mapp[i][C-1]=='.') {
			if(fdist[i][C-1]>jdist[i][C-1]) {
				if(ans>jdist[i][C-1])
					ans=jdist[i][C-1];
			}
		}
	}

	if(ans==iInf)
		cout << "IMPOSSIBLE\n";
	else
		cout << (ans+1) << '\n';

}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	solve();

	return 0;
}

