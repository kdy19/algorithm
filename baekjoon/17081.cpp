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

char grid[101][101];

struct Player {
	int R = 0;
	int C = 0;
	int curHp = 20;
	int maxHp = 20;
	int atk = 2;
	int def = 2;
	int exp = 0;
	int needExp = 5;
	int level = 1;
	int weapon = 0;
	int armor = 0;
	std::vector<std::string> acc;
	int accCnt = 0;
	bool ok = 1;
};

struct Monster {
	int R = 0;
	int C = 0;
	std::string S;
	int curHp = 0;
	int W = 0;
	int A = 0;
	int H = 0;
	int E = 0;
	bool ok = 1;
};

struct Item {
	int R = 0;
	int C = 0;
	char T = 0;
	int N = 0;
	std::string S;
};

int max(int x, int y) {
	return x > y ? x : y;
}

void check(Player* player, std::string msg, int turnCnt, int N, int M, bool failed) {
	if (!failed)
		grid[player->R][player->C] = '@';

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j)
			std::cout << grid[i][j];
		std::cout << '\n';
	}

	std::cout << "Passed Turns : " << turnCnt << '\n';
	std::cout << "LV : " << player->level << '\n';
	std::cout << "HP : " << player->curHp << '/' << player->maxHp << '\n';
	std::cout << "ATT : " << player->atk << '+' << player->weapon << '\n';
	std::cout << "DEF : " << player->def << '+' << player->armor << '\n';
	std::cout << "EXP : " << player->exp << '/' << player->needExp << '\n';

	if (failed)
		std::cout << "YOU HAVE BEEN KILLED BY " << msg << "..";
	else
		std::cout << msg;

	exit(0);
}

std::pair<Monster*, int> getMonster(Monster* monster, int R, int C, int K) {
	for (int i = 0; i < K; ++i) {
		if ((monster + i)->R == R && (monster + i)->C == C && (monster + i)->ok) {
			return std::make_pair((monster + i), i);
		}
	}
}

std::pair<Item*, int> getItem(Item* item, int R, int C, int L) {
	for (int i = 0; i < L; ++i) {
		if ((item + i)->R == R && (item + i)->C == C) {
			return std::make_pair((item + i), i);
		}
	}
}

bool fightMonster(Player* player, Monster* tMonster, bool rings[]) {
	int playerAtk = max(1, (player->atk + player->weapon) - tMonster->A);
	int monsterAtk = max(1, tMonster->W - (player->def + player->armor));

	int raiseAtk = 0;
	bool raiseAtkOk = 0;
	if (rings[2]) {
		raiseAtk = max(1, (player->atk + player->weapon) * 2 - tMonster->A);
		raiseAtkOk = 1;
	}
	if (rings[2] && rings[4]) {
		raiseAtk = max(1, (player->atk + player->weapon) * 3 - tMonster->A);
		raiseAtkOk = 1;
	} 

	bool ok = 0;
	while (true) {
		if (raiseAtkOk) {
			tMonster->curHp -= raiseAtk;
			raiseAtkOk = 0;
		}
		else {
			tMonster->curHp -= playerAtk;
		}

		if (tMonster->curHp <= 0) {
			ok = 1;
			break;
		}

		player->curHp -= monsterAtk;
		if (player->curHp <= 0) {
			break;
		}
	}
	return ok;
}

bool fightBoss(Player* player, Monster* tMonster, bool rings[]) {
	int playerAtk = max(1, (player->atk + player->weapon) - tMonster->A);
	int monsterAtk = max(1, tMonster->W - (player->def + player->armor));

	int raiseAtk = 0;
	bool raiseAtkOk = 0;
	if (rings[2]) {
		raiseAtk = max(1, (player->atk + player->weapon) * 2 - tMonster->A);
		raiseAtkOk = 1;
	}
	if (rings[2] && rings[4]) {
		raiseAtk = max(1, (player->atk + player->weapon) * 3 - tMonster->A);
		raiseAtkOk = 1;
	} 

	if (rings[5])
		player->curHp = player->maxHp;

	bool ok = 0;
	while (true) {
		if (raiseAtkOk) {
			tMonster->curHp -= raiseAtk;
			raiseAtkOk = 0;
		}
		else {
			tMonster->curHp -= playerAtk;
		}

		if (tMonster->curHp <= 0) {
			ok = 1;
			break;
		}

		if (rings[5]) {
			rings[5] = 0;
			continue;
		}
		player->curHp -= monsterAtk;
		if (player->curHp <= 0) {
			break;
		}
	}
	return ok;
}

int main(int argc, char* argv[]) {
	fast_io;
	bool boss = 0;
	int N, M, K = 0, L = 0, turnCnt = 0;
	int sx = -1, sy = -1;
	std::cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		std::string s;
		std::cin >> s;

		for (int j = 1; j <= M; ++j) {
			grid[i][j] = s[j - 1];

			if (grid[i][j] == '@') {
				sx = i;
				sy = j;
				grid[i][j] = '.';
			}
			if (grid[i][j] == 'B') ++L;
			if (grid[i][j] == '&' || grid[i][j] == 'M') ++K;
		}
	}
	
	Player* player = new Player();
	Monster* monster = new Monster[K]();
	Item* item = new Item[L]();

	std::string move;
	std::cin >> move;

	for (int i = 0; i < K; ++i) {
		std::cin >> (monster + i)->R >> (monster + i)->C >> (monster + i)->S >> (monster + i)->W >> (monster + i)->A >> (monster + i)->H >> (monster + i)->E;
		(monster + i)->curHp = (monster + i)->H;
	}

	for (int i = 0; i < L; ++i) {
		std::cin >> (item + i)->R >> (item + i)->C >> (item + i)->T;
		if ((item + i)->T == 'O') {
			std::cin >> (item + i)->S;
		}
		else {
			std::cin >> (item + i)->N;
		}
	}

	player->R = sx;
	player->C = sy;
	int moveSize = move.length();

	for (int i = 0; i < moveSize; ++i) {
		int nextR = player->R, nextC = player->C;
		if (move[i] == 'L') {
			nextC = player->C - 1;
		}
		else if (move[i] == 'R') {
			nextC = player->C + 1;
		}
		else if (move[i] == 'U') {
			nextR = player->R - 1;
		}
		else {
			nextR = player->R + 1;
		}

		std::vector<std::string>::iterator iter;
		iter = player->acc.begin();
		bool rings[7] = { 0, };
		int reIdx = 0, idx = 0;

		for (iter; iter != player->acc.end(); ++iter) {
			if (*iter == "HR") rings[0] = 1;
			if (*iter == "RE") {
				rings[1] = 1;
				reIdx = idx;
			}
			if (*iter == "CO") rings[2] = 1;
			if (*iter == "EX") rings[3] = 1;
			if (*iter == "DX") rings[4] = 1;
			if (*iter == "HU") rings[5] = 1;
			if (*iter == "CU") rings[6] = 1;

			++idx;
		}

		if (0 >= nextR || N < nextR || 0 >= nextC || M < nextC || (grid[nextR][nextC] == '#')) {
			player->R = player->R;
			player->C = player->C;
		}
		else {
			player->R = nextR;
			player->C = nextC;
		}

		if (grid[player->R][player->C] == '&') {
			std::pair<Monster*, int> p = getMonster(monster, player->R, player->C, K);
			bool playerWin = fightMonster(player, p.first, rings);

			if (playerWin) {
				(monster + p.second)->ok = 0;
				grid[player->R][player->C] = '.';

				if (rings[0]) {
					player->curHp += 3;

					if (player->curHp > player->maxHp)
						player->curHp = player->maxHp;
				}

				if (rings[3]) {
					player->exp += (p.first->E * 1.2);
				}
				else
					player->exp += (p.first->E);

				if (player->exp >= player->needExp) {
					player->level += 1;
					player->maxHp += 5;
					player->atk += 2;
					player->def += 2;
					player->curHp = player->maxHp;

					player->exp = 0;
					player->needExp = player->level * 5;
				}
			}
			else {
				if (!rings[1]) {
					player->curHp = 0;
					++turnCnt;
					check(player, p.first->S, turnCnt, N, M, 1);
				}

				(monster + p.second)->curHp = (monster + p.second)->H;
				player->curHp = player->maxHp;
				player->R = sx;
				player->C = sy;
				player->acc.erase(player->acc.begin() + reIdx);
				player->accCnt -= 1;
			}
		}
		else if (grid[player->R][player->C] == 'M') {
			std::pair<Monster*, int> p = getMonster(monster, player->R, player->C, K);
			bool playerWin = fightBoss(player, p.first, rings);

			if (playerWin) {
				(monster + p.second)->ok = 0;
				grid[player->R][player->C] = '.';

				if (rings[0]) {
					player->curHp += 3;

					if (player->curHp > player->maxHp)
						player->curHp = player->maxHp;
				}

				if (rings[3]) {
					player->exp += (p.first->E * 1.2);
				}
				else
					player->exp += (p.first->E);

				if (player->exp >= player->needExp) {
					player->level += 1;
					player->maxHp += 5;
					player->atk += 2;
					player->def += 2;
					player->curHp = player->maxHp;

					player->exp = 0;
					player->needExp = player->level * 5;
				}
				++turnCnt;
				check(player, "YOU WIN!", turnCnt, N, M, 0);
			}
			else {
				if (!rings[1]) {
					player->curHp = 0;
					++turnCnt;
					check(player, p.first->S, turnCnt, N, M, 1);
				}

				(monster + p.second)->curHp = (monster + p.second)->H;
				player->curHp = player->maxHp;
				player->R = sx;
				player->C = sy;
				player->acc.erase(player->acc.begin() + reIdx);
				player->accCnt -= 1;
			}
		}
		else if (grid[player->R][player->C] == 'B') {
			std::pair<Item*, int> p = getItem(item, player->R, player->C, L);

			if (p.first->T == 'O' && player->accCnt < 4) {
				bool ok = 1;
				iter = player->acc.begin();
				for (iter; iter != player->acc.end(); ++iter) {
					if (*iter == p.first->S) ok = 0;
				}

				if (ok) {
					player->accCnt += 1;
					player->acc.push_back(p.first->S);
				}
			} 
			else {
				if (p.first->T == 'W') {
					player->weapon = p.first->N;
				}
				if (p.first->T == 'A') {
					player->armor = p.first->N;
				}
			}
			grid[player->R][player->C] = '.';
		}
		else if (grid[player->R][player->C] == '^') {
			if (rings[4])
				player->curHp -= 1;
			else
				player->curHp -= 5;

			if (player->curHp <= 0) {
				if (!rings[1]) {
					player->curHp = 0;
					++turnCnt;
					check(player, "SPIKE TRAP", turnCnt, N, M, 1);
				}
				player->curHp = player->maxHp;
				player->R = sx;
				player->C = sy;
				player->acc.erase(player->acc.begin() + reIdx);
				player->accCnt -= 1;
			}
		}
		++turnCnt;
	}

	check(player, "Press any key to continue.", turnCnt, N, M, 0);

	delete player;
	delete[] monster;
	delete[] item;
	
	return 0;
}

