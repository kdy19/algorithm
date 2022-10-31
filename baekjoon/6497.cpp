#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>

#define fast_io std::ios_base::sync_with_stdio(NULL); std::cin.tie(0); std::cout.tie(0);
#define ll long long int

const int iInf = (int)1e9;
const int MOD = (int)1e9 + 9;
const int d4x[4] = { 1,-1,0,0 };
const int d4y[4] = { 0,0,1,-1 };
const int d8x[8] = { -1,-1,0,1,1,1,0,-1 };
const int d8y[8] = { 0,1,1,1,0,-1,-1,-1 };

struct Edge {
	int to;
	int cost;

	bool operator < (const Edge& other) const {
		return cost > other.cost;
	}
};

std::vector<Edge> A[200001];
bool chk[2000001];

int main(int argc, char* argv[]) {
	fast_io;

	while (true) {
		int M, N;
		std::cin >> M >> N;

		if (M == 0 && N == 0) break;

		int sum = 0;
		for (int i = 0; i < N; ++i) {
			int u, v, w;
			std::cin >> u >> v >> w;
			A[u].push_back(Edge({ v, w }));
			A[v].push_back(Edge({ u, w }));
			sum += w;
		}

		chk[0] = true;
		std::priority_queue<Edge> Q;
		for (int i = 0; i < A[0].size(); ++i) {
			Q.push(A[0][i]);
		}

		int ans = 0;
		while (!Q.empty()) {
			Edge e = Q.top();
			Q.pop();

			if (chk[e.to]) continue;
			chk[e.to] = true;
			ans += e.cost;
			int x = e.to;
			for (int i = 0; i < A[x].size(); ++i)
				Q.push(A[x][i]);
		}

		std::cout << (sum - ans) << '\n';

		memset(chk, 0, sizeof(chk));
		for (int i = 0; i < 200001; ++i)
			A[i].clear();
	}
	

	return 0;
}

