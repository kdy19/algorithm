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

void update(vector<int>& tree, int i, int diff) {
	while(i<tree.size()) {
		tree[i]+=diff;
		i+=(i&-i);
	}
}

int sum(vector<int>& tree, int i) {
	int ans=0;
	while(i>0) {
		ans+=tree[i];
		i-=(i&-i);
	}
	return ans;
}

int sum(vector<int>& tree, int l, int r) {
	if(l>r) return 0;
	return sum(tree, r)-sum(tree, l-1);
}

void solve() {
	int N, M;
	cin >> N;

	vector<int> A(N+1), tree(N+1);
	for(int i=1; i<=N; ++i) {
		cin >> A[i];
		if(!(A[i]&1))
			update(tree, i, 1);
	}

	cin >> M;
	while(M--) {
		int q;
		cin >> q;
		if(q==1) {
			int i, x;
			cin >> i >> x;
			if(!(A[i]&1)&&x&1) 
				update(tree, i, -1);
			if(A[i]&1&&!(x&1))
				update(tree, i, 1);
			A[i]=x;
		} else {
			int l, r;
			cin >> l >> r;
			int cnt=sum(tree, l, r);
			if(q==3) 
				cnt=(r-l+1)-cnt;
			cout << cnt << '\n';
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

