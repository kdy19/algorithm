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

const int iInf=(int)1e9;
const int MOD=1e9+7;
const int d4x[4]={1,-1,0,0};
const int d4y[4]={0,0,1,-1};
const int d8x[8]={-1,-1,0,1,1,1,0,-1};
const int d8y[8]={0,1,1,1,0,-1,-1,-1};

ll sum(vector<ll>& tree, int x) {
	ll ans=0;
	for(int i=x; i>0; i-=i&-i)
		ans+=tree[i];
	return ans;
}

void update(vector<ll>& tree, int x, ll diff) {
	for(int i=x; i<tree.size(); i+=i&-i)
		tree[i]+=diff;
}

void solve() {
	int N, M;
	cin >> N >> M;

	vector<ll> A(N+1), tree(N+1);

	while(M--) {
		int q;
		cin >> q;
		if(q==1) {
			int i, k;
			cin >> i >> k;
			ll diff=k-A[i];
			A[i]=k;
			update(tree, i, diff);
		} else {
			int i, j;
			cin >> i >> j;
			if(i>j)
				swap(i, j);
			cout << sum(tree, j) - sum(tree, i-1) << '\n';
		}
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	solve();

	return 0;
}

