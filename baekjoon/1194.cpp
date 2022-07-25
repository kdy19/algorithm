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

char mapp[51][51];
bool vis[51][51][1<<10];

bool check(char c, int key) {
	if((key&(1<<(c-'A')))!=0)
		return true;
	return false;
}

void solve() {
	int N, M;
	cin >> N >> M;

	int sx, sy;
	for(int i=0; i<N; ++i) {
		string s;
		cin >> s;
		for(int j=0; j<s.size(); ++j) {
			mapp[i][j]=s[j];
			if(s[j]=='0') {
				sx=i;
				sy=j;
				mapp[i][j]='.';
			}
		}
	}

	queue<tuple<int, int, int, int>> Q;
	Q.push(make_tuple(sx, sy, 0, 0));
		
	while(!Q.empty()) {
		int x, y, cnt, key;
		tie(x, y, cnt, key)=Q.front();
		Q.pop();

		vis[x][y][key]=1;

		if(mapp[x][y]=='1') {
			cout << cnt;
			return;
		}

		for(int k=0; k<4; ++k) {
			int nx=x+d4x[k];
			int ny=y+d4y[k];

			if(nx<0||ny<0||nx>=N||ny>=M) continue;
			if(mapp[nx][ny]=='#') continue;
			if(mapp[nx][ny]=='.'||mapp[nx][ny]=='1') {
				if(!vis[nx][ny][key]) {
					vis[nx][ny][key]=1;
					Q.push(make_tuple(nx, ny, cnt+1, key));
				}
			}
			if('a'<=mapp[nx][ny]&&mapp[nx][ny]<='f') {
				int nk=key|(1<<mapp[nx][ny]-'a');
				if(!vis[nx][ny][nk]) {
					vis[nx][ny][nk]=1;
					Q.push(make_tuple(nx, ny, cnt+1, nk));
				}
			}
			if('A'<=mapp[nx][ny]&&mapp[nx][ny]<='F') {
				if(check(mapp[nx][ny], key)&&!vis[nx][ny][key]) {
					vis[nx][ny][key]=1;
					Q.push(make_tuple(nx, ny, cnt+1, key));
				}
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

