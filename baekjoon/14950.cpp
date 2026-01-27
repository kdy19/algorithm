#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

class Edge {
public:
	int to;
	int cost;

	Edge(int to, int cost) : to(to), cost(cost) {};

	bool operator <(const Edge& other) const {
		return this->cost > other.cost;
	}
};

std::vector<Edge> E[10001];
bool chk[10001];

int
main(int argc, char** argv) {
	int N, M, t;
	int max = 0;

	std::cin >> N >> M >> t;

	for (int i = 0; i < M; ++i) {
		int A, B, C;
		std::cin >> A >> B >> C;

		E[A].push_back(Edge({ B, C }));
		E[B].push_back(Edge({ A, C }));
		max += C;
	}

	chk[1] = true;
	std::priority_queue<Edge> pq;

	for (Edge e : E[1])
		pq.push(e);

	int cnt = 0;
	int ans = 0;
	while (!pq.empty()) {
		Edge e = pq.top();
		pq.pop();

		if (!chk[e.to]) {
			int x;

			x = e.to;
			ans += e.cost + cnt;
			chk[e.to] = true;

			for (Edge ee : E[x])
				pq.push(ee);

			cnt += t;

			//std::cout << ans << '\n';
		}
	}

	std::cout << ans;

	return 0;
}
