// #define PRINT printf
#define PRINT
#define ABS(x) ((x)>=0 ? (x) : (-(x)))
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, K, r, c, Ey, Ex, time, totaldis;
int copymap[13][13];
int arr[13][13];
vector<int> vec[13][13];
vector<int> copyvec[13][13];
bool totalexit;
const int dy[5] = { 0,0,1,-1 };
const int dx[5] = { -1,1,0,0 };

struct PLAYER {
	int y, x;
	int move;
	bool exit;
};
PLAYER player[15];

int CalDist(int y1, int x1, int y2, int x2) {
	return ABS(x1 - x2) + ABS(y1 - y2);
}

void MovePlayers(int Ey, int Ex) {
	int y = 0; int x = 0; int ny = 0; int nx = 0;
	for (int p = 1; p <= M; ++p) {
		int curdist = CalDist(Ey, Ex, player[p].y, player[p].x); //현재거리
		int mindist = curdist;
		int retdir = -1;
		if (!player[p].exit) {
			y = player[p].y, x = player[p].x;
			for (int i = 0; i < 4; ++i) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && arr[ny][nx] >= 0) {
					//맵 밖 아님, 벽 아님
					int calret = CalDist(Ey, Ex, ny, nx);
					if (calret < curdist) {
						//현재 출구까지 거리보다 더 가까워져야함
						if (calret <= mindist) {
							//그러면서 이때까지의 최솟값 이하여야함
							mindist = calret;
							retdir = i;
						}
					}
				}
			}
			if (retdir >= 0) {
				ny = y + dy[retdir];
				nx = x + dx[retdir];

				if (ny == Ey && nx == Ex) {
					//만약 이동할 곳이 출구
					player[p].exit = 1;
				}
				else {
					vec[ny][nx].push_back(p);
					for (int v = 0; v < vec[y][x].size(); ++v) {
						if (vec[y][x][v] == p) vec[y][x][v] = 0;
					}
					//이동처리
					arr[ny][nx] = p;
				}
				if (arr[y][x] = p) {
					arr[y][x] = 0;
				}
				player[p].y = ny, player[p].x = nx;
				player[p].move++;
			}
		}
	}
}

void RotateSquare(int dis, int y, int x) {
	//dis = 좌표차 기준 폭, (y,x)= 좌상단좌표
	bool MoveExit = 0;
	int num1 = -1;
	for (int i = y; i <= y + dis; ++i) {
		num1++;
		int num2 = -1;
		for (int j = x; j <= x + dis; ++j) {
			num2++;
			copymap[i][j] = arr[(y + dis) - num2][x + num1];
			if (!MoveExit && Ey == (y + dis - num2) && Ex == (x + num1)) {
				PRINT("EXIT (%d,%d) <- (%d,%d)\n", i, j, (y + dis) - num2, x + num1);
				//출구 회전이동
				Ey = i, Ex = j;
				MoveExit = 1;
			}
			if (copymap[i][j] < 0) {
				copymap[i][j] += 1;
			}
			int oriy = y + dis - num2;
			int orix = x + num1;
			if (vec[oriy][orix].size()) {

				PRINT("human[%d]\n", copymap[i][j]);
				int num = 0;

				for (int k = 0; k < vec[oriy][orix].size(); ++k) {
					if (vec[oriy][orix][k] == 0) continue;
					num = vec[oriy][orix][k];
					player[num].y = i;
					player[num].x = j;
					copyvec[i][j].push_back(num);
				}
			}
		}
	}

	for (int i = y; i <= y + dis; ++i) {
		for (int j = x; j <= x + dis; ++j) {
			arr[i][j] = copymap[i][j];
			copymap[i][j] = 0;
			vec[i][j] = copyvec[i][j];
			copyvec[i][j].clear();
		}
	}
}

struct PAIR {
	int y, x;
};


PAIR Calrc(int y1, int x1, int y2, int x2, int dis) {
	PAIR ret = { -1,-1 };
	int maxv = 0;
	int pairn = 0;
	int rx = 0; int ry = 0;
	ry = max(y1, y2)-dis;
	rx = max(x1, x2)-dis;
	if (ry < 1) ry = 1;
	if (rx < 1) rx = 1;
	ret.y = ry;
	ret.x = rx;
	return ret;
}

void RotateMap(int Ey, int Ex) {
	//출구부터 참가자까지 max(|x1-x2|, |y1-y2|) 중 min을 찾음 => 폭
	int pnum = 0;
	int mdis = 10000000;
	int dret = 0;
	PAIR minyx;
	int my = -1; int mx = -1; // 좌상단 최적 좌표 
	for (int i = 1; i <= M; ++i) {
		if (!player[i].exit) {
			dret = max(ABS(Ey - player[i].y), ABS(Ex - player[i].x));
			if (mdis > dret) {
				mdis = dret;
				pnum = i;
				minyx = Calrc(Ey, Ex, player[i].y, player[i].x, mdis);
				my = minyx.y, mx = minyx.x;
			}
			else if (mdis == dret) {
				minyx = Calrc(Ey, Ex, player[i].y, player[i].x, mdis);
				if (minyx.y < my) {
					pnum = i;
					my = minyx.y, mx = minyx.x;
				}
				else if (minyx.y == my) {
					if (minyx.x < mx) {
						pnum = i;
						my = minyx.y, mx = minyx.x;
					}
				}
			}
		}
	}
	RotateSquare(mdis, my, mx);
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j]) {
				arr[i][j] *= -1;
			}
		}
	}
	for (int i = 1; i <= M; ++i) {
		scanf("%d %d", &r, &c);
		player[i].y = r;
		player[i].x = c;
		arr[r][c] = i;
		vec[r][c].push_back(i);
	}
	scanf("%d %d", &Ey, &Ex);

	while (time < K) {
		int totaldi = 0;
		time++;

		MovePlayers(Ey, Ex);
		for (int i = 1; i <= M; ++i) {
			totaldi += player[i].move;
		}
		totalexit = 1;
		for (int i = 1; i <= M; ++i) {
			if (player[i].exit == 0) {
				totalexit = 0;
				break;
			}
		}
		if (totalexit) break;
		RotateMap(Ey, Ex);
	}

	for (int i = 1; i <= M; ++i) {
		totaldis += player[i].move;
	}

	printf("%d\n", totaldis);
	printf("%d %d\n", Ey, Ex);

	return 0;
}
