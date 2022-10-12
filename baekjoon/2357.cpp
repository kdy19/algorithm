#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define fast_io ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
#define ll long long int

const int iInf = (int)1e9;
const int MOD = (int)1e9 + 9;
const int d4x[4] = { 1,-1,0,0 };
const int d4y[4] = { 0,0,1,-1 };
const int d8x[8] = { -1,-1,0,1,1,1,0,-1 };
const int d8y[8] = { 0,1,1,1,0,-1,-1,-1 };

ll min(ll a, ll b) {
	return a > b ? b : a;
}

ll max(ll a, ll b) {
	return a > b ? a : b;
}

void init(vector<ll>& a, vector<ll>& min_tree, vector<ll>& max_tree, int node, int st, int ed) {
	if (st == ed) {
		min_tree[node] = a[st];
		max_tree[node] = a[st];
	}
	else {
		init(a, min_tree, max_tree, node * 2, st, (st + ed) / 2);
		init(a, min_tree, max_tree, node * 2 + 1, (st + ed) / 2 + 1, ed);
		min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
		max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
	}
}

pair<ll, ll> query(vector<ll>& min_tree, vector<ll>& max_tree, int node, int st, int ed, int i, int j) {
	if (i > ed || j < st) return make_pair(iInf, 0);
	if (i <= st && ed <= j) return make_pair(min_tree[node], max_tree[node]);
	pair<ll, ll> l, r;
	l = query(min_tree, max_tree, node * 2, st, (st + ed) / 2, i, j);
	r = query(min_tree, max_tree, node * 2 + 1, (st + ed) / 2 + 1, ed, i, j);
	return make_pair(min(l.first, r.first), max(l.second, r.second));
}

int main(int argc, char* argv[]) {
	fast_io;

	int N, M;
	cin >> N >> M;

	vector<ll> A(N);
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	vector<ll> min_tree(tree_size);
	vector<ll> max_tree(tree_size);

	for (int i = 0; i < N; ++i)
		cin >> A[i];

	init(A, min_tree, max_tree, 1, 0, N - 1);
	while (M--) {
		int l, r;
		cin >> l >> r;
		pair<ll, ll> res = query(min_tree, max_tree, 1, 0, N - 1, l - 1, r - 1);
		cout << res.first << ' ' << res.second << '\n';
	}

	return 0;
}

