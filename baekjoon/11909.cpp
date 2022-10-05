#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;

#define ll long long

const int iInf=(int)1e9;
const int MOD=(int)1e9;
const int d4x[4]={1,-1,0,0};
const int d4y[4]={0,0,1,-1};
const int d8x[8]={-1,-1,0,1,1,1,0,-1};
const int d8y[8]={0,1,1,1,0,-1,-1,-1};

int A[2223][2223];
int dp[2223][2223];

void solve() {
	int N;
	cin >> N;

	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=N; ++j) {
			cin >> A[i][j];
			dp[i][j]=iInf;
		}
	}

	dp[1][1]=0;
	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=N; ++j) {
			int diff=0;
			if(i==N&&j==N) break;
			if(i!=N) {
				if(A[i+1][j]>=A[i][j]) {
					diff=A[i+1][j]-A[i][j]+1;
					dp[i+1][j]=min(dp[i+1][j], dp[i][j]+diff);
				} else
					dp[i+1][j]=min(dp[i+1][j], dp[i][j]);
			}
			if(j!=N) {
				if(A[i][j+1]>=A[i][j]) {
					diff=A[i][j+1]-A[i][j]+1;
					dp[i][j+1]=min(dp[i][j+1], dp[i][j]+diff);
				} else
					dp[i][j+1]=min(dp[i][j+1], dp[i][j]);
			}
		}
	}

	cout << dp[N][N];

    return;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cout << fixed;
    cout.precision(4);
    cout.tie(NULL);
    cin.tie(NULL);

	solve();

    return 0;
}
