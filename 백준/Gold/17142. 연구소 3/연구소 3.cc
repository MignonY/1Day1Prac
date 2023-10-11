//#define PRINT printf
#define PRINT
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, zeronum, savezeronum, ans, tempans, minans = 50000;
int arr[55][55];
int visit[55][55];
pair <int, int> virus;
vector<pair<int, int>> vec;
int temp[15];
bool valid;
const int dy[5] = { -1,0,1,0 };
const int dx[5] = { 0,1,0,-1 };

struct VIRUS {
	int y;
	int x;
	int time;
};

VIRUS queue[10000];

void InitVar() {
	for (int i = 0; i < 55; ++i) {
		for (int j = 0; j < 55; ++j) {
			visit[i][j] = 0;
		}
	}
	tempans = 0;
	zeronum = savezeronum;
}

void PrintArr() {
	PRINT("PRINT_ARR\n");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (visit[i][j]) {
				PRINT("%d ", visit[i][j] - 3);
			}
			else {
				PRINT("%d ", visit[i][j]);
			}
		}
		PRINT("\n");
	}
}
void BFS(int temp[], int r) {
	int rear = -1;
	int front = 0;


	for (int i = 0; i < r; ++i) {
		rear++;
		int idx = temp[i];
		queue[rear].y = vec[idx].first;
		queue[rear].x = vec[idx].second;
		queue[rear].time = 3;
		visit[queue[rear].y][queue[rear].x] = queue[rear].time;
	}

	while (rear + 1 != front) {
		int Y = queue[front].y;
		int X = queue[front].x;
		int time = queue[front].time;
		front++;

		for (int i = 0; i < 4; ++i) {
			int ny = Y + dy[i];
			int nx = X + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N && visit[ny][nx] == 0 && arr[ny][nx] != 1) {
				rear++;
				PRINT("rear:%d | Y,X:(%d,%d) | ny,nx:(%d,%d) | arr[ny][nx]:%d\n", rear, Y, X, ny, nx, arr[ny][nx]);
				queue[rear].y = ny;
				queue[rear].x = nx;
				queue[rear].time = time + 1;
				visit[ny][nx] = time + 1;
				if (arr[ny][nx] == 0) {
					zeronum--;
					if (zeronum == 0) {
						tempans = (time + 1) - 3;
					}
				}
			}
		}


	}

}

void nCr_Simulation(int n, int r, int depth, int start) {
	if (depth == r) {
		//PRINT("idx={");
		//for (int i = 0; i < depth; ++i) {
		//	PRINT("%d, ", temp[i]);
		//}
		//PRINT("}\n");

		BFS(temp, r);

		if (zeronum == 0 && tempans < minans) {
			minans = tempans;
			valid = 1;
		}
		//PrintArr();
		PRINT("tempans:%d, minans:%d, zeronum:%d\n", tempans, minans, zeronum);
		InitVar();

		return;
	}

	for (int i = start; i < n; ++i) {
		temp[depth] = i;
		nCr_Simulation(n, r, depth + 1, i + 1);
		temp[depth] = 0;
	}

}


int main() {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) {
				virus.first = i;
				virus.second = j;
				vec.push_back(virus);
			}
			if (arr[i][j] == 0) {
				zeronum++;
			}

		}
	}

	if (zeronum) {
		int TotalVirusNum = vec.size();
		if (TotalVirusNum) {
			savezeronum = zeronum;
			nCr_Simulation(TotalVirusNum, M, 0, 0);

			if (valid) {
				ans = minans;
			}
			else {
				ans = -1;
			}
		}
		else {
			ans = -1;
		}
	}

	printf("%d\n", ans);
	return 0;
}