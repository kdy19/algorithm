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

void init(vector<ll>& a, vector<ll>& tree, int node, int st, int ed) {
	if (st == ed) {
		tree[node] = a[st];
	}
	else {
		init(a, tree, node * 2, st, (st + ed) / 2);
		init(a, tree, node * 2 + 1, (st + ed) / 2 + 1, ed);
		tree[node] = tree[node * 2] + tree[node * 2 + 1]; 
	}
}

void update(vector<ll>& tree, int node, int st, int ed, int i, ll diff) {
	if (i < st || i > ed) return;
	tree[node] = tree[node] + diff;
	if (st != ed) {
		update(tree, node * 2, st, (st + ed) / 2, i, diff);
		update(tree, node * 2 + 1, (st + ed) / 2 + 1, ed, i, diff);
	}
}

ll sum(vector<ll>& tree, int node, int st, int ed, int i, int j) {
	if (i > ed || j < st) return 0;
	if (i <= st && ed <= j) return tree[node];
	return sum(tree, node * 2, st, (st + ed) / 2, i, j) +
		sum(tree, node * 2 + 1, (st + ed) / 2 + 1, ed, i, j);
}

int main(int argc, char* argv[]) {
	fast_io;

	int n, m, k;
	cin >> n >> m >> k;

	vector<ll> a(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<ll> tree(tree_size);

	m += k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	init(a, tree, 1, 0, n - 1);
	while (m--) {
		int what;
		cin >> what;

		if (what == 1) {
			int index;
			ll val;
			cin >> index >> val;
			--index;
			ll diff = val - a[index];
			a[index] = val;
			update(tree, 1, 0, n - 1, index, diff);
		}
		else if (what == 2) {
			int st, ed;
			cin >> st >> ed;
			cout << sum(tree, 1, 0, n - 1, st - 1, ed - 1) << '\n';
		}
	}

	return 0;
}

