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

int A[1001][1001];
int next[1001][1001];
int dist[1001];
bool chk[1001];

void path(int x, int y) {
	if (next[x][y] == -1) {
		std::cout << "0\n";
		return;
	}

	std::queue<int> Q;
	Q.push(x);
	while (x != y) {
		x = next[x][y];
		Q.push(x);
	}

	std::cout << Q.size() << " ";
	while (!Q.empty()) {
		std::cout << Q.front() << " ";
		Q.pop();
	}
	std::cout << '\n';
}

int main(int argc, char* argv[]) {
	fast_io;
	int n, m;
	std::cin >> n >> m;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) A[i][j] = 0;
			else A[i][j] = iInf;
			next[i][j] = -1;
		}
	}

	for (int i = 0; i < m; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		
		if (A[u][v] > w) {
			A[u][v] = w;
			next[u][v] = v;
		}
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (A[i][j] > A[i][k] + A[k][j]) {
					A[i][j] = A[i][k] + A[k][j];
					next[i][j] = next[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (A[i][j] == iInf)
				std::cout << "0 ";
			else
				std::cout << A[i][j] << " ";
		}
		std::cout << '\n';
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) std::cout << "0\n";
			else if (A[i][j] == iInf) std::cout << "0\n";
			else path(i, j);
		}
	}
	
	return 0;
}

