#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

#define ll long long

const int iInf=(int)1e9;
const int MOD=(int)1e9+9;
const int d4x[4]={1,-1,0,0};
const int d4y[4]={0,0,1,-1};
const int d8x[8]={-1,-1,0,1,1,1,0,-1};
const int d8y[8]={0,1,1,1,0,-1,-1,-1};

bool chk[100000];

void solve() {
	int N, T, G;
	cin >> N >> T >> G;

	queue<pair<int, int>> Q;
	Q.push(make_pair(N, 0));
	chk[N]=1;

	while(!Q.empty()) {
		int x, cnt;
		tie(x, cnt)=Q.front();
		Q.pop();

		if(x==G) {
			cout << cnt;
			return;
		}
		if(cnt==T) continue;

		if(x+1<=99999&&!chk[x+1]) {
			Q.push(make_pair(x+1, cnt+1));
			chk[x+1]=1;
		}

		if(x!=0) {
			int t=x*2;
			if(t>99999) continue;

			string nx=to_string(t);

			if(nx[0]!='0') {
				char c=nx[0]-'1';
				nx[0]=c+'0';
				t=stoi(nx);
			}

			if(t>99999) continue;
			if(t<=99999&&!chk[t]) {
				Q.push(make_pair(t, cnt+1));
				chk[t]=1;
			}
		}
	}
	cout << "ANG";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	solve();

	return 0;
}

