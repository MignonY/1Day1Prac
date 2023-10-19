#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int n, m;
const int inf = 2e9;
//인접 리스트 표현 
vector<pair<int, int>> adj[401];
//
priority_queue<pair<int, int>>pq;
//시작점부터 index까지의 최단거리 저장하는 배열
int dist[401];

//다익스트라 알고리즘
int fun(int src) {
	dist[src] = 0;
	pq.push({ 0,src });
	bool sym = false;
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		if (sym && here == src) {
			//최단 순환 사이클을 찾았다!
			return cost;
		}
		sym = true;
		pq.pop();
		if (dist[here] < cost) {
			continue;
		}
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nowcost = cost + adj[here][i].second;
			//cout << "there : " << there << " nowcost : " << nowcost << endl;
			if (there == src || dist[there] > nowcost) {
				dist[there] = nowcost;
				pq.push({ -nowcost,there });
			}
		}
	}
	//순환 사이클이 발견되지 않을경우
	return inf;
}
void distmake() {
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
	}
}


int main() {
	scanf("%d %d",&n,&m);
	for (int j = 0; j < m; j++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b,c });
	}
	distmake();
	int ans = inf;
	for (int i = 1; i <= n; i++) {
		int num = fun(i);
		if (ans > num) {
			ans = num;
		}
		distmake();
	}
	if (ans == inf) {
		printf("%d\n",-1);
	}
	else {
		printf("%d\n",ans);
	}
}