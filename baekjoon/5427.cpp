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

char mapp[1001][1001];
int fdist[1001][1001];
int sdist[1001][1001];

void solve() {
	int T;
	cin >> T;
	
	while(T--) {
		int w, h;
		int sx, sy;
		cin >> w >> h;

		for(int i=0; i<h; ++i) {
			for(int j=0; j<w; ++j) {
				fdist[i][j]=iInf;
				sdist[i][j]=iInf;
			}
		}

		queue<pair<int, int>> Q;
		for(int i=0; i<h; ++i) {
			string s;
			cin >> s;
			for(int j=0; j<s.size(); ++j) {
				mapp[i][j]=s[j];
				if(mapp[i][j]=='@') {
					sx=i;
					sy=j;
					mapp[i][j]='.';
				}
				if(mapp[i][j]=='*') {
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

				if(nx<0||ny<0||nx>=h||ny>=w) continue;
				if(mapp[nx][ny]=='#') continue;
				if(mapp[nx][ny]=='.') {
					if(fdist[nx][ny]>fdist[x][y]+1) {
						fdist[nx][ny]=fdist[x][y]+1;
						Q.push(make_pair(nx, ny));
					}
				}
			}
		}

		Q.push(make_pair(sx, sy));
		sdist[sx][sy]=0;
		
		while(!Q.empty()) {
			int x, y;
			tie(x, y)=Q.front();
			Q.pop();

			for(int k=0; k<4; ++k) {
				int nx=x+d4x[k];
				int ny=y+d4y[k];

				if(nx<0||ny<0||nx>=h||ny>=w) continue;
				if(mapp[nx][ny]=='#') continue;
				if(mapp[nx][ny]=='.') {
					if(sdist[nx][ny]>sdist[x][y]+1) {
						sdist[nx][ny]=sdist[x][y]+1;
						Q.push(make_pair(nx, ny));
					}
				}
			}
		}

		int ans=iInf;
		for(int i=0; i<w; ++i) {
			if(mapp[0][i]=='.') {
				if(fdist[0][i]>sdist[0][i]) {
					if(ans>sdist[0][i])
						ans=sdist[0][i];
				}
			}
			if(mapp[h-1][i]=='.') {
				if(fdist[h-1][i]>sdist[h-1][i]) {
					if(ans>sdist[h-1][i])
						ans=sdist[h-1][i];
				}
			}
		}

		for(int i=0; i<h; ++i) {
			if(mapp[i][0]=='.') {
				if(fdist[i][0]>sdist[i][0]) {
					if(ans>sdist[i][0])
						ans=sdist[i][0];
				}
			}
			if(mapp[i][w-1]=='.') {
				if(fdist[i][w-1]>sdist[i][w-1]) {
					if(ans>sdist[i][w-1])
						ans=sdist[i][w-1];
				}
			}
		}

		if(ans==iInf)
			cout << "IMPOSSIBLE\n";
		else
			cout << (ans+1) << '\n';

		memset(mapp, 0, sizeof(mapp));

	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	solve();

	return 0;
}

