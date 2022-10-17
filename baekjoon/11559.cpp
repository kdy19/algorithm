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

char grid[12][6];
char temp[12][6];
bool chk[12][6];

void debug() {
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 6; ++j)
			std::cout << grid[i][j];
		std::cout << '\n';
	}
	std::cout << "\n\n\n";
}

bool bfs() {
	bool ret = 0;
	memset(chk, 0, sizeof(chk));
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (grid[i][j] != '.' && !chk[i][j]) {
				memcpy(temp, grid, sizeof(grid));
				int cnt = 1;
				char color = grid[i][j];
				std::queue<std::pair<int, int>> Q;
				Q.push(std::make_pair(i, j));
				temp[i][j] = '.';
				chk[i][j] = 1;

				while (!Q.empty()) {
					int x, y;
					std::tie(x, y) = Q.front();
					Q.pop();

					for (int k = 0; k < 4; ++k) {
						int nx = x + d4x[k];
						int ny = y + d4y[k];

						if (0 > nx || 12 <= nx || 0 > ny || 6 <= ny) continue;
						if (grid[nx][ny] == '.') continue;
						if (grid[nx][ny] == color && !chk[nx][ny]) {
							Q.push(std::make_pair(nx, ny));
							temp[nx][ny] = '.';
							chk[nx][ny] = 1;
							++cnt;
						}
					}
				}

				if (cnt >= 4) {
					memcpy(grid, temp, sizeof(temp));
					ret = 1;
				}
			}
		}
	}

	return ret;
}

void down() {
	for (int j = 0; j < 6; ++j) {
		int p1 = 11, p2 = 11;

		while (0 <= p2 && 0 <= p1) {
			if (grid[p1][j] != '.' && grid[p2][j] != '.') {
				--p1;
				--p2;
			}
			else if (grid[p1][j] == '.' && grid[p2][j] != '.') {
				char t = grid[p1][j];
				grid[p1][j] = grid[p2][j];
				grid[p2][j] = t;
				--p1;
				--p2;
			}
			else if (grid[p1][j] == '.') --p2;
			else --p1;
		}
	}

}

int main(int argc, char* argv[]) {
	fast_io;
	
	for (int i = 0; i < 12; ++i) {
		std::string s;
		std::cin >> s;
		for (int j = 0; j < 6; ++j) {
			grid[i][j] = s[j];
		}
	}

	int cnt = 0;
	while (true) {
		bool ok = bfs();
		if (!ok) break;
		down();
		debug();
		++cnt;
	}

	std::cout << cnt;

	return 0;
}

