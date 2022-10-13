#include <iostream>
#include <vector>
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

int grid[102][102];

struct Shark {
	int r = 0;
	int c = 0;
	int s = 0;
	int d = 0;
	int z = 0;
	bool ok = false;
};

void debug(int R, int C, int sharkCnt) {
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j)
			std::cout << grid[i][j] << ' ';
		std::cout << '\n';
	}
	std::cout << sharkCnt << " -----------------------\n\n\n";
}

int catchShark(struct Shark* shark, int& sharkCnt, int idx, int R, int C, int M) {
	int ret = 0;
	for (int i = 1; i <= R; ++i) {
		if (grid[i][idx] == 1) {
			for (int s = 0; s < M; ++s) {
				if (shark[s].r == i && shark[s].c == idx && (!shark[s].ok)) {
					ret = shark[s].z;
					grid[i][idx] = 0;
					shark[s].ok = 1;
					sharkCnt -= 1;
					break;
				}
			}
		}
		if (ret != 0) break;
	}

	return ret;
}

void moveShark(struct Shark* shark, int& sharkCnt, int R, int C, int M) {
	for (int s = 0; s < M; ++s) {
		// up, r - 1
		if (shark[s].ok) continue;
		grid[shark[s].r][shark[s].c] -= 1;
		if (shark[s].d == 1) {
			bool out = 0;
			for (int p = 0; p < shark[s].s; ++p) {
				if (shark[s].r - 1 <= 0) {
					out = 1;
				}
				if (shark[s].r + 1 > R) {
					out = 0;
				}

				if (out) shark[s].r++;
				else shark[s].r--;
			}

			if (out) shark[s].d = 2;
		}
		// down, r + 1
		else if (shark[s].d == 2) {
			bool out = 0;
			for (int p = 0; p < shark[s].s; ++p) {
				if (shark[s].r + 1 > R) {
					out = 1;
				}
				if (shark[s].r - 1 <= 0) {
					out = 0;
				}

				if (out) shark[s].r--;
				else shark[s].r++;
			}

			if (out) shark[s].d = 1;
		}
		// right, j + 1
		else if (shark[s].d == 3) {
			bool out = 0;
			for (int p = 0; p < shark[s].s; ++p) {
				if (shark[s].c + 1 > C) {
					out = 1;
				}
				if (shark[s].c - 1 <= 0) {
					out = 0;
				}

				if (out) shark[s].c--;
				else shark[s].c++;
			}

			if (out) shark[s].d = 4;
		}
		// left, j - 1
		else {
			bool out = 0;
			for (int p = 0; p < shark[s].s; ++p) {
				if (shark[s].c - 1 <= 0) {
					out = 1;
				}
				if (shark[s].c + 1 > C) {
					out = 0;
				}

				if (out) shark[s].c++;
				else shark[s].c--;
			}

			if (out) shark[s].d = 3;
		}
		grid[shark[s].r][shark[s].c] += 1;
	}
}

void removeShark(struct Shark* shark, int& sharkCnt, int R, int C, int M) {
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			if (grid[i][j] >= 2) {
				int maxN = -1;

				for (int s = 0; s < M; ++s) {
					if (shark[s].r == i && shark[s].c == j && (!shark[s].ok)) {
						maxN = std::max(maxN, shark[s].z);
					}
				}
				for (int s = 0; s < M; ++s) {
					if (shark[s].r == i && shark[s].c == j && (!shark[s].ok) && (shark[s].z != maxN)) {
						shark[s].ok = 1;
						sharkCnt -= 1;
					}
				}
				grid[i][j] = 1;
			}
		}
	}
}

int main(int argc, char* argv[]) {
	fast_io;

	int R, C, M;
	std::cin >> R >> C >> M;

	if (M == 0) {
		std::cout << "0\n";
		return 0;
	}

	Shark* shark = new Shark[M]();

	for (int i = 0; i < M; ++i) {
		std::cin >> (shark + i)->r >> (shark + i)->c >> (shark + i)->s >> (shark + i)->d >> (shark + i)->z;
		grid[(shark + i)->r][(shark + i)->c] = 1;
	}


	int ans = 0, sharkCnt = M;
	for (int j = 1; j <= C; ++j) {
		// catchShark
		ans += catchShark(shark, sharkCnt, j, R, C, M);

		// moveShark
		moveShark(shark, sharkCnt, R, C, M);
		// debug(R, C, sharkCnt);
		removeShark(shark, sharkCnt, R, C, M);
	}

	delete[] shark;

	std::cout << ans;

	return 0;
}

