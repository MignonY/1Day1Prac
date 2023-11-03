//#define PRINT printf
#define PRINT
#define ABS(x) ((x)>=0 ? (x) : (-(x)) )

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;


int n, m, ty, tx, time;
int sy, sx, dist, SY, SX, nowy, nowx;
int arr[30][30];
bool SBarr[30][30];
bool visit[30][30];
const int dy[5] = { -1,0,0,1 };
const int dx[5] = { 0,-1,1,0 };

struct PLACE {
	int num;
	int y;
	int x;
	bool visit;
};

struct HUMAN {
	int y;
	int x;
	int visitBase;
	bool visitStore;
};

PLACE storeinfo[450];
PLACE baseinfo[450];
HUMAN humaninfo[450];
int Sidx = 0;
int Bidx = 0;

class cmp {
public:
	bool operator()(pair<int, PLACE*> a, pair<int, PLACE*> b) {
		if (a.first == b.first) {
			if (a.second->y == b.second->y) {
				return a.second->x > b.second->x;
			}
			return a.second->y > b.second->y;
		}
		return a.first > b.first;
	}
};

priority_queue <pair<int, PLACE*>, vector<pair<int,PLACE*>>, cmp> distpq;
pair<int, int> MoveRet;

struct Q {
	int y; 
	int x;
	int firstdir;
	int dis;
};
Q Queue[10000];


void InitVisit() {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			visit[i][j] = 0;
		}
	}
}
void CheckArr() {
	PRINT("CHECKArr\n");
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			PRINT("%d ", arr[i][j]);
		}
		PRINT("\n");
	}
	PRINT("CHECK SBArr\n");
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			PRINT("%d ", SBarr[i][j]);
		}
		PRINT("\n");
	}
}
void CheckHuman() {
	for (int i = 1; i <= m; ++i) {
		PRINT("human[%d] || y,x(%d,%d) | Base: %d | Store: %d\n", i, humaninfo[i].y, humaninfo[i].x, humaninfo[i].visitBase, humaninfo[i].visitStore);
	}
}
void CheckBase() {
	for (int i = 1; i <= Bidx; ++i) {
		PRINT("BASE[%d] || y,x(%d,%d) | visit: %d\n", i, baseinfo[i].y, baseinfo[i].x, baseinfo[i].visit);
	}
}

int CalDist(int y1, int x1, int y2, int x2) {
	return ABS(y1 - y2) + ABS(x1 - x2);
}


void BFS_SEARCH(int SY, int SX, int HumanNum) {

	int rear = -1;
	int start = 0;

	rear++;
	Queue[rear].y = SY;
	Queue[rear].x = SX;
	Queue[rear].dis = 0;

	visit[SY][SX] = 1;


	while (rear + 1 != start) {
		int y = Queue[start].y;
		int x = Queue[start].x;
		int dis = Queue[start].dis;
		if (!distpq.empty()) {
			if (dis > distpq.top().first) {
				return;
			}
		}
		start++;
		

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (1 <= ny && ny <= n && 1 <= nx && nx <= n && visit[ny][nx] == 0) {
				//PRINT("rear:%d | to (%d,%d) | y,x: (%d,%d)| nynx (%d,%d) \n ", rear, TY, TX, y, x, ny, nx);
				if (SBarr[ny][nx] != 1) {
					rear++;
					Queue[rear].y = ny;
					Queue[rear].x = nx;
					Queue[rear].dis = dis+1;
					visit[ny][nx] = 1;

					if (arr[ny][nx] != 0) {
						int num = arr[ny][nx];
						if (baseinfo[num].visit == 0) {
							distpq.push({ Queue[rear].dis, &baseinfo[num]});
						}
					}
				}
				else {
					PRINT("CANT MOVE : (%d %d)\n", ny, nx);
				}
			}

		}
	}

	PRINT("NO STORE\n");

}


pair<int, int> BFS_MOVE(int SY, int SX, int HumanNum) {
	
	int TY = storeinfo[HumanNum].y;
	int TX = storeinfo[HumanNum].x;

	int rear = -1;
	int start = 0;

	rear++;
	Queue[rear].y = SY;
	Queue[rear].x = SX;
	Queue[rear].firstdir = -1;
	
	visit[SY][SX] = 1;

	
	while (rear + 1 != start) {
		int y = Queue[start].y;
		int x = Queue[start].x;
		int firstdir = Queue[start].firstdir;
		start++;


		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (y == SY && x == SX) {
				firstdir = i;
			}

			if (1 <= ny && ny <= n && 1 <= nx && nx <= n && visit[ny][nx] == 0) {
				if (SBarr[ny][nx] != 1) {
					rear++;
					Queue[rear].y = ny;
					Queue[rear].x = nx;
					Queue[rear].firstdir = firstdir;
					visit[ny][nx] = 1;
				
					if (ny == TY && nx == TX) {
						PRINT("rear:%d | to (%d,%d) | y,x: (%d,%d)| nynx (%d,%d) \n ",rear,TY,TX,y,x,ny,nx);
						return { SY + dy[firstdir], SX + dx[firstdir] };
					}
				}
				//else {
				//	PRINT("CANT MOVE : (%d %d)\n", ny, nx);
				//}
			}
		
		}
	}

	PRINT("NO STORE\n");
	return { 0,0 };

}


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				Bidx++;
				arr[i][j] = Bidx;
				baseinfo[Bidx].y = i;
				baseinfo[Bidx].x = j;
				baseinfo[Bidx].num = Bidx;
			}
		}
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d", &ty, &tx);
		Sidx++;
		//arr[ty][tx] = Sidx;
		storeinfo[Sidx].y = ty;
		storeinfo[Sidx].x = tx;
	}


	int TotalStoreNum = Sidx;

	time = 1;
	while (TotalStoreNum) {
		PRINT("\n START : Time[%d]\n", time);
		for (int i = 1; i <= m; ++i) {
		//PRINT("@\n");
			if (humaninfo[i].visitBase != 0 && humaninfo[i].visitStore == 0) {
				nowy = humaninfo[i].y;
				nowx = humaninfo[i].x;
				PRINT("curHU[%d] | yx (%d,%d) | base:%d | store %d\n", i, humaninfo[i].y, humaninfo[i].x, humaninfo[i].visitBase, humaninfo[i].visitStore);
				// 현재 위치부터 최단거리 계산 후 한칸만 이동
				MoveRet = BFS_MOVE(nowy, nowx, i);
				InitVisit();
				if (MoveRet.first == 0) {
					PRINT("NO STORE == FINISH\n");
				}
				PRINT("Time[%d] || human[%d] -> MOVERET: (%d, %d)\n", time, i, MoveRet.first, MoveRet.second);
				humaninfo[i].y = MoveRet.first;
				humaninfo[i].x = MoveRet.second;
				
				//만약 도착시
				if (humaninfo[i].y == storeinfo[i].y && humaninfo[i].x == storeinfo[i].x) {
					SBarr[MoveRet.first][MoveRet.second] = 1;
					storeinfo[i].visit = 1;
					humaninfo[i].visitStore = 1;
					TotalStoreNum--;
				}
			}
		}


		if (time <= m) {
			//PRINT("#\n");
			//베이스캠프 search
			sy = storeinfo[time].y;
			sx = storeinfo[time].x;

			BFS_SEARCH(sy,sx,time);

			if (distpq.empty()) {
				PRINT("distpq EMPTY");
			}
			else {
				//time번째 사람 이동처리, 베이스캠프 이동불가 처리 
				SY = distpq.top().second->y;
				SX = distpq.top().second->x;
				PLACE* retbase = distpq.top().second;
				retbase->visit = 1;
				humaninfo[time].y = SY;
				humaninfo[time].x = SX;
				humaninfo[time].visitBase = retbase->num;
				SBarr[SY][SX] = 1;
			}
			distpq = priority_queue <pair<int, PLACE*>, vector<pair<int, PLACE*>>, cmp> ();

		}

		CheckArr();
		CheckHuman();

		//CheckBase();
		InitVisit();
		time++;

	}
	
	printf("%d", time-1);
	
	return 0;
}
