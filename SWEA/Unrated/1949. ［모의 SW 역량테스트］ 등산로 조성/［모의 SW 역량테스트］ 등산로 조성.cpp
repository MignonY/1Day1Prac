#define PRINT printf
//#define PRINT
#include <stdio.h>
using namespace std;

int T, N, K, my, mx, maxL, ans;
int maxv = -500;
int arr[12][12];
bool visit[12][12];
const int dy[5] = { -1,0,1,0 };
const int dx[5] = { 0,1,0,-1 };
 

struct ST {
	int y, x;
};

ST start[7];
int Sidx = 1;

void Findmaxv() {
	Sidx = 1;
	maxv = -500;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i][j] > maxv) {
				maxv = arr[i][j];
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i][j] == maxv) {
				start[Sidx].y = i, start[Sidx].x = j;
				Sidx++;
			}
		}
	}
}

void initvisit() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			visit[i][j] = 0;
		}
	}
}
void init() {
	maxL = ans = 0;
	Sidx = 1;
}
void DFS(int y, int x, int depth) {
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (0 <= ny && ny < N && 0 <= nx && nx < N && visit[ny][nx] == 0 && arr[ny][nx] < arr[y][x]) {
			//벽안뚫, 방문X , 저점으로만 진행 
			visit[ny][nx] = 1;
			if (maxL < depth + 1)
				maxL = depth + 1;
			DFS(ny, nx, depth + 1);
			visit[ny][nx] = 0;
		}
	}
	//네방향 진행해도 이제 갈곳없음 
	return;
}

int main() {
	//freopen("dsro.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j)
				scanf("%d", &arr[i][j]);
		}

		Findmaxv();
		maxL = 0;


		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				for (int k = 0; k <= K; ++k) {
					for (int s = 1; s < Sidx; ++s) {
						int sy = start[s].y;
						int sx = start[s].x;
						if (!(sy == i && sx == j)) {
							for (int k = 0; k <= K; ++k) {
                                arr[i][j] -= k;
								visit[sy][sx] = 1;
								DFS(sy, sx, 1);
								initvisit();
                                arr[i][j] += k;
							}
						}
					}
				}
			}
		}

		ans = maxL;
		printf("#%d %d\n", tc, ans);
		init();
	}
	return 0;
}

