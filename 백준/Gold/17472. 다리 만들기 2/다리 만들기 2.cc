//최종본, 완전연결트리인지 확인하고 크루스칼 돌렸음 (순서 의미없는듯)
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int N, M, arr[13][13], visit[13][13], g_visit[10], cnt, ans; //visit, cnt, SNUM , ans초기화필요  
const int dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, -1, 1 };
int parent[10];
int SNUM = 1;

vector<pair<int, pair<int, int>>> SEOM; //SEOM, GRAPH도 초기화 필요  

vector<vector<int>>graph(10);




void DFS(int y, int x) {
	visit[y][x] = 1;
	arr[y][x] = SNUM;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (0 <= ny && ny < N && 0 <= nx && nx < M && visit[ny][nx] == 0 && arr[ny][nx] == 1) {
			visit[ny][nx] = 1;
			DFS(ny, nx);
		}
	}

}

void G_DFS(int start) {
	cnt++;
	g_visit[start] = 1;

	for (int i = 0; i < graph[start].size(); ++i) {
		int next = graph[start][i];
		if (g_visit[next] == 0) {
			g_visit[next] = 1;
			G_DFS(next);
		}
	}
}

void ifnext(int y, int x) {
	int zerocnt = 0, elsecnt = 0;
	int xsave = x, ysave = y;
	int cur = arr[y][x];
	while (x < M - 1) {
		x++;
		if (arr[y][x] == 0)
			zerocnt++;
		else if (arr[y][x] == cur)
			elsecnt++;

		if (elsecnt >= 1) {
			break;
		}

		if (zerocnt < 2 && arr[y][x] != 0 && arr[y][x] != cur)
			break;

		if (zerocnt >= 2 && arr[y][x] != 0 && arr[y][x] != cur) {
			SEOM.push_back({ zerocnt, {cur, arr[y][x]} });
			SEOM.push_back({ zerocnt, {arr[y][x], cur} });
			break;

		}
	}

	zerocnt = 0; elsecnt = 0; x = xsave, y = ysave;

	while (y < N - 1) {
		y++;
		if (arr[y][x] == 0)
			zerocnt++;
		else if (arr[y][x] == cur)
			elsecnt++;

		if (elsecnt >= 1) {
			break;
		}
		if (zerocnt < 2 && arr[y][x] != 0 && arr[y][x] != cur)
			break;

		if (zerocnt >= 2 && arr[y][x] != 0 && arr[y][x] != cur) {
			SEOM.push_back({ zerocnt, {cur, arr[y][x]} });
			SEOM.push_back({ zerocnt, {arr[y][x], cur} });
			break;

		}
	}
}


////////////////

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


int kruskal() {
	int res=0;

	for (int i = 0; i < 10; ++i) {
		parent[i] = i;
	}
	sort(SEOM.begin(), SEOM.end());

	for (int i = 0; i < SEOM.size(); ++i) {
		if (findP(SEOM[i].second.first) != findP(SEOM[i].second.second)) {
			res += SEOM[i].first;
			merge(SEOM[i].second.first, SEOM[i].second.second);
		}
	}

	return res;

}


int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%d", &arr[i][j]);
		}
	}

	//섬 번호 채워넣기 
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] == 1 && visit[i][j] == 0) {
				DFS(i, j);
				SNUM++;
			}
		}
	}


	// 가중치, 간선정보 (a,(b,c)) 벡터에 담았음  
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] != 0) {
				ifnext(i, j);
			}
		}
	}



	// vector로 인접리스트 만들어보고 되는지 안되는지 먼저 체크 
	for (int i = 0; i < SEOM.size(); ++i) {
		if (find(graph[SEOM[i].second.first].begin(), graph[SEOM[i].second.first].end(), SEOM[i].second.second) == graph[SEOM[i].second.first].end()) {
			graph[SEOM[i].second.first].push_back(SEOM[i].second.second);	//순회를 위한 인접리스트 추가 
			graph[SEOM[i].second.second].push_back(SEOM[i].second.first);
		}
	}

	//섬 다 연결되는지 최종확인
	G_DFS(1);
	int wans = -1;

	bool Flag = true;
	if (cnt != SNUM - 1 || SNUM - 1 == 1)
		Flag = false;

	if (Flag == true) {
		ans = kruskal();
		printf("%d\n", ans);
	}
	else
		printf("%d\n", wans);


	return 0;
}