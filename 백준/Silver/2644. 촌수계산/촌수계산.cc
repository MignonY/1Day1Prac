#include <stdio.h>

int Graph[105][105];
int visited[105];
int N,M; // 사람 수와 부모 자식들 간의 관계의 수
int start, end;
int u, v;

void Input() {
	scanf("%d", &N);
	scanf("%d %d", &start, &end);
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		Graph[u][v] = 1;
		Graph[v][u] = 1;
	}

	visited[start] = 1;
}

void func(int start) {
	for (int i = 1; i <= N; i++) {
		if (!visited[i] && Graph[start][i]) {
			visited[i] = visited[start] + 1;
			func(i);
		}
	}
}

void Solve() {
	Input();
	func(start);
}

int main() {
	Solve();
	printf("%d", visited[end]-1);

	return 0;
}