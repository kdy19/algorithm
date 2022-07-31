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
const int MOD=(int)1e9;
const int d4x[4]={1,-1,0,0};
const int d4y[4]={0,0,1,-1};
const int d8x[8]={-1,-1,0,1,1,1,0,-1};
const int d8y[8]={0,1,1,1,0,-1,-1,-1};

ll dp[201][201];

void solve() {
	int N, K;
	cin >> N >> K;

	dp[0][0]=1;
	for(int i=1; i<=K; ++i) {
		for(int j=0; j<=N; ++j) {
			for(int k=0; k<=j; ++k) {
				dp[i][j]+=dp[i-1][j-k];
				dp[i][j]%=MOD;
			}
		}
	}
	cout << dp[K][N];
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	solve();

	return 0;
}

