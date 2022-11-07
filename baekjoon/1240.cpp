#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>
#include <set>

#define fast_io std::ios_base::sync_with_stdio(NULL); std::cin.tie(0); std::cout.tie(0);
#define ll long long int
#define ull unsigned long long int

const int iInf = (int)1e9;
const int MOD = (int)1e9 + 9;
const int d4x[4] = { 1,-1,0,0 };
const int d4y[4] = { 0,0,1,-1 };
const int d8x[8] = { -1,-1,0,1,1,1,0,-1 };
const int d8y[8] = { 0,1,1,1,0,-1,-1,-1 };

struct Edge {
		int to;
		int cost;
		Edge(int to, int cost) : to(to), cost(cost) {};
};

std::vector<Edge> A[1001];
bool chk[1001];

int main(int argc, char* argv[]) {
		fast_io;
		int N, M;
		std::cin >> N >> M;

		for (int i = 0; i < N - 1; ++i) {
				int u, v, w;
				std::cin >> u >> v >> w;
				A[u].push_back(Edge(v, w));
				A[v].push_back(Edge(u, w));
		}

		for (int i = 0; i < M; ++i) {
				int x, y;
				std::cin >> x >> y;
				std::queue<std::pair<int, int>> Q;
				Q.push(std::make_pair(x, 0));
				chk[x] = 1;

				while (!Q.empty()) {
						int cx, cost;
						std::tie(cx, cost) = Q.front();
						Q.pop();

						if (cx == y) {
								std::cout << cost << '\n';
								break;
						}

						for (int j = 0; j < A[cx].size(); ++j) {
								if (!chk[A[cx][j].to]) {
										Q.push(std::make_pair(A[cx][j].to, cost + A[cx][j].cost));
										chk[A[cx][j].to] = 1;
								}
						}
				}
				memset(chk, 0x00, sizeof(chk));
		}

		return 0;
}


