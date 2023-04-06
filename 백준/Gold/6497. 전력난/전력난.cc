#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int V, E, x, y, z, parent[200001], maxv, res;

vector <pair<int, pair<int, int>>> VEC;

void scan();
int KRUSKAL();
void print();
void init();

int main() {

	while (1) {

		scan();

		if (V == 0 && E == 0)
			break;

		print();
		init();
	}

	return 0;
}


void scan() {
	scanf("%d %d", &V, &E);
	if (V == 0 && E == 0)
		return;
	for (int i = 0; i < E; ++i) {
		scanf("%d %d %d", &x, &y, &z);
		maxv += z;
		VEC.push_back({ z,{x,y} });
	}
	//printf("%d %d", V, E);
}

int findP(int a) {
	if (a == parent[a])
		return a;

	else
		return parent[a] = findP(parent[a]);
}

void merge(int a, int b) {
	a = findP(a);
	b = findP(b);

	if (a == b)
		return;

	if (a < b)
		parent[a] = b;
	else
		parent[b] = a;
}


int KRUSKAL() {
	for (int i = 0; i < V; ++i) {
		parent[i] = i;
	}

	sort(VEC.begin(), VEC.end());


	for (int i = 0; i < VEC.size(); ++i) {
		int cost = VEC[i].first;
		int current = VEC[i].second.first;
		int next = VEC[i].second.second;

		if (findP(current) != findP(next)) {
			//printf("check %d %d %d\n", current, next, cost);
			res += cost;
			merge(current, next);
		}
	}
	//printf("res:%d\n", res);
	return res;
}


void print() {
	int ans = 0;
	ans = maxv - KRUSKAL();
	printf("%d\n", ans);
}


void init() {
	res = 0;
	maxv = 0;
	for (int i = 0; i < VEC.size(); ++i) {
		VEC.clear();
	}
}