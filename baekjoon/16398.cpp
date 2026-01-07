#include <algorithm>
#include <iostream>
#include <vector>


class Edge {
public:
	int from;
	int to;
	int distance;

	Edge(int from, int to, int distance) : from(from), to(to), distance(distance) {};

	bool operator <(const Edge &edge) {
		return this->distance < edge.distance;
	}
};

int 
getParent(int s[], int x) {
	if (s[x] == x) return x;
	return s[x] = getParent(s, s[x]);
}

void
unionParent(int s[], int x, int y) {
	x = getParent(s, x);
	y = getParent(s, y);

	if (x < y) s[y] = x;
	else s[x] = y;
}

int
find(int s[], int x, int y) {
	x = getParent(s, x);
	y = getParent(s, y);

	if (x == y) return 1;
	else return 0;
}

int
main(int argc, char** argv) {
	int N, C;
	int s[1000] = { 0, };
	long long sum = 0;

	std::cin >> N;

	std::vector<Edge> v;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> C;
			v.push_back(Edge(i, j, C));
		}
	}

	std::sort(v.begin(), v.end());

	for (int i = 0; i < N; ++i) {
		s[i] = i;
	}

	for (int i = 0; i < v.size(); ++i) {
		if (!find(s, v[i].from, v[i].to)) {
			sum += v[i].distance;
			unionParent(s, v[i].from, v[i].to);
		}
	}

	std::cout << sum;

	return 0;
}
