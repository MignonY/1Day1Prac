//#define PRINT printf
#define PRINT

#include <stdio.h>
#include <queue>
using namespace std;

int N, M, K, turn, validCanon, ans;
int maxAtt;
int arr[15][15];
int Cmap[15][15];
int visit[15][15];

const int dy[5] = {0,1,0,-1};
const int dx[5] = {1,0,-1,0};

const int by[8] = {-1,-1,-1,0,0,1,1,1};
const int bx[8] = {-1,0,1,-1,1,-1,0,1};

struct CANON {
	int num;
	int y;
	int x;
	int str;
	int attackTurn;
	int destroy;
	bool battle;
};

CANON Cinfo[15000];
int Cidx;

struct AttackerCMP {
	bool operator()(CANON* a, CANON* b) {
		if (a->str == b->str) {
			if (a->attackTurn == b->attackTurn) {
				if ((a->y + a->x) == (b->y + b->x)) {
					return a->x < b->x;
				}
				return (a->y + a->x) < (b->y + b->x);
			}
			return a->attackTurn < b->attackTurn;
		}
		return a->str > b->str;
	}
};
struct DefenserCMP {
	bool operator()(CANON* a, CANON* b) {
		if (a->str == b->str) {
			if (a->attackTurn == b->attackTurn) {
				if ((a->y + a->x) == (b->y + b->x)) {
					return a->x > b->x;
				}
				return (a->y + a->x) > (b->y + b->x);
			}
			return a->attackTurn > b->attackTurn;
		}
		return a->str < b->str;
	}
};

priority_queue<CANON*, vector<CANON*>, AttackerCMP> AttackerPQ;
priority_queue<CANON*, vector<CANON*>, DefenserCMP> DefenserPQ;

struct Q {
	int y;
	int x;
	int from;
	int fromidx;
};

Q Queue[20000];

void CheckArr() {
	PRINT("\nCHECK_Arr\n");
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			PRINT("%d ",arr[i][j]);
		}
		PRINT("\n");
	}
}
void CheckCmap() {
	PRINT("\nC_Arr\n");
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			PRINT("%d ",Cmap[i][j]);
		}
		PRINT("\n");
	}
}
void CheckCanon() {
	PRINT("\nCanons\n");
	for (int i = 1; i <= Cidx; ++i) {
		PRINT("Canon[%d] | yx (%d,%d) | str: %d | Turn: %d | Destroy:%d | Battle:%d\n", i, Cinfo[i].y, Cinfo[i].x, Cinfo[i].str, Cinfo[i].attackTurn,Cinfo[i].destroy, Cinfo[i].battle);
	}
	PRINT("\n");
}

void SetAttackCheck() {
	for (int i = 1; i <= Cidx; ++i) {
		Cinfo[i].battle = 0;
	}
}

void InitVisit() {
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= M; ++j) {
			visit[i][j] = 0;
		}
	}
}

void DestroyCanon(CANON* canon) {
		canon->str = 0;
		canon->destroy = 1;
		Cmap[canon->y][canon->x] = 0;
		arr[canon->y][canon->x] = 0;
		validCanon--;
}


int Laser_Search(CANON* Attacker,  CANON* Defenser) {
	int SY = Attacker->y , SX = Attacker->x;
	int TY = Defenser->y , TX = Defenser->x;

	int rear = -1;
	int front = 0;

	rear++;
	Queue->y = SY;
	Queue->x = SX;
	Queue->from = 0;
	visit[SY][SX] = 1;
	int now = Cmap[SY][SX];

	while (rear + 1 != front) {
		int y = Queue[front].y;
		int x = Queue[front].x;
		int from = Queue[front].from;
		int fromidx = Queue[front].fromidx;

		front++;

		for (int i = 0; i < 4; ++i) {
			int ny = ((y + dy[i] -1) % N) + 1;
			int nx = ((x + dx[i] -1) % M) + 1;
			if (ny == 0) { ny = N; }
			if (nx == 0) { nx = M; }

			if (visit[ny][nx] == 0 && arr[ny][nx] !=0) {
				CheckArr();
				CheckCmap();
				PRINT("rear[%d] | y,x (%d,%d) | nynx (%d,%d)| fromidx:%d | from:%d | num:%d \n", front-1, y,x,ny,nx,fromidx,from, Cmap[y][x]);

				rear++;
				Queue[rear].y = ny;
				Queue[rear].x = nx;
				Queue[rear].from = Cmap[y][x];
				Queue[rear].fromidx = front-1;
				visit[ny][nx] = 1;
				//PRINT("//rear[%d] | nynx (%d,%d)| fromidx:%d | from:%d | \n", rear,Queue[rear].y, Queue[rear].x, Queue[rear].fromidx, Queue[rear].from);
	/*			for(int i = 0; i <= rear; ++i) {
					PRINT("Queue[%d] | yx (%d,%d)| fromidx:%d | from:%d | num:%d\n", i, Queue[i].y, Queue[i].x, Queue[i].fromidx, Queue[i].from, Cmap[Queue[i].y][Queue[i].x]);
				}*/

				if (ny == TY && nx == TX) {
					//최단경로 발견, 공격 적용
						//피공격자에게 공격
					Defenser->str -= Attacker->str;
					arr[ny][nx] = Defenser->str;
					if (Defenser->str <= 0) {
						DestroyCanon(Defenser);
					}
						//경로에 있던 포탑들 공격 
					//int num = Queue[rear].from;
					//int bfrear = Queue[rear].fromidx;
					int num = Cmap[ny][nx];
					int bfrear = rear;
					for(int i = 0; i <= rear; ++i) {
						PRINT("//Queue[%d] | yx (%d,%d)| fromidx:%d | from:%d | num:%d\n", i, Queue[i].y, Queue[i].x, Queue[i].fromidx, Queue[i].from, Cmap[Queue[i].y][Queue[i].x]);
					}
					//CheckCanon();
					while (1) {
						PRINT("bf//num:%d | att:%d | bfrear:%d \n", num, Cinfo[num].str,bfrear);
						num = Queue[bfrear].from;
						bfrear = Queue[bfrear].fromidx;
						if (num == Attacker->num) {
							break;
						}
						PRINT("aft//num:%d | att:%d | bfrear:%d \n", num, Cinfo[num].str,bfrear);
						Cinfo[num].str -= (Attacker->str) / 2;
						arr[Cinfo[num].y][Cinfo[num].x] = Cinfo[num].str;
						Cinfo[num].battle = 1;
						if (Cinfo[num].str <= 0) {
							DestroyCanon(&Cinfo[num]);
						}
						//num = Cmap[Queue[bfrear].y][Queue[bfrear].x];
					}

					if (validCanon == 1) {
						PRINT("STOPLaser\n");
						return 2;
					}
					return 1;
				}





			}
		}
	}
	
	PRINT("NO_LASER\n");
	return 0;


}

int Bomb_Attack(CANON *Attacker, CANON *Defenser) {
	int y = Defenser->y;
	int x = Defenser->x;
	PRINT("Bomb | yx:(%d,%d)\n", y, x);
	//CheckCanon();
	//CheckArr();
	//피공격자 공격
	Defenser->str -= Attacker->str;
	arr[y][x] = Defenser->str;

	if (Defenser->str <= 0) {
		DestroyCanon(Defenser);
		//if (validCanon == 1) {
		//	PRINT("STOPBomb\n");
		//	return 2;
		//}
	}
	//주변 8방향 공격
	for (int i = 0; i < 8; ++i) {
		int ny = ((y + by[i] - 1) % N) + 1;
		int nx = ((x + bx[i] - 1) % M) + 1;
		if (ny == 0) { ny = N; }
		if (nx == 0) { nx = M; }
		if (arr[ny][nx] != 0 && !(ny == Attacker->y && nx== Attacker->x)) {
			PRINT("Bomb to (%d,%d)\n", ny, nx);
			CANON* attacked = &Cinfo[Cmap[ny][nx]];
			attacked->str -= (Attacker->str) / 2;
			attacked->battle = 1;
			arr[ny][nx] = attacked->str;
			if (attacked->str <= 0) {
				DestroyCanon(attacked);
			}
		}
		else {
			PRINT("NOne to (%d,%d)\n", ny, nx);

		}
	}
	//CheckCanon();
	//CheckArr();
	//PRINT("Bomb Done\n");
	if (validCanon == 1) {
		PRINT("STOPBomb\n");
		return 2;
	}
	return 1;
}



int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0) {
				Cidx++;
				Cinfo[Cidx].num = Cidx;
				Cinfo[Cidx].y = i;
				Cinfo[Cidx].x = j;
				Cinfo[Cidx].str = arr[i][j];
				Cmap[i][j] = Cidx;
			}
		}
	}

	//CheckArr();
	validCanon = Cidx;
	turn = 0;
	//CheckCanon();
	while (turn < K) {
		turn++;
		PRINT("TURN [%d]\n", turn);

		//1. 공격자 선정 : 유효 포탑중 공격력이 가장 낮은 포탑 
		for (int i = 1; i <= Cidx; ++i) {
			if (Cinfo[i].destroy != 1) {
				AttackerPQ.push(&Cinfo[i]);
			}
		}

		CANON* Attacker = AttackerPQ.top();
		Attacker->attackTurn = turn;
		Attacker->str += N + M;
		arr[Attacker->y][Attacker->x] += Attacker->str;
		Attacker->battle = 1;

		//2. 피공격자 선정 : 유효 포탑 중 공격자가 아니면서 공격력이 가장 낮은 포탑 
		for (int i = 1; i <= Cidx; ++i) {
			if (Cinfo[i].destroy != 1 && Cinfo[i].num != Attacker->num) {
				DefenserPQ.push(&Cinfo[i]);
			}
		}
		CANON* Defenser = DefenserPQ.top();
		Defenser->battle = 1;

		PRINT("Attacker:%d | yx:(%d,%d) , att:%d || Defenser:%d | yx:(%d,%d), att:%d \n", Attacker->num ,Attacker->y, Attacker->x, Attacker->str, Defenser->num, Defenser->y, Defenser->x, Defenser->str);

		//3-1. 레이저 공격
		int LaserValid=0;
		LaserValid = Laser_Search(Attacker, Defenser);
		PRINT("LaserValid: %d\n", LaserValid);
		InitVisit();
		CheckArr();
		
		//3-2. 포탄공격
		int BombRet=0;
		if (LaserValid == 2) {
			break;
		}
		if (LaserValid == 0) {
			BombRet = Bomb_Attack(Attacker, Defenser);
			if (BombRet == 2) {
				break;
			}
			InitVisit();
		}

		 //포탑 정비 (전투 무관련 포탑 att++)
		for (int i = 1; i <= Cidx; ++i) {
			if (Cinfo[i].destroy == 0 && Cinfo[i].battle == 0) {
				Cinfo[i].str += 1;
				//PRINT("cinfo: %d\n", i);
				arr[Cinfo[i].y][Cinfo[i].x] += 1;
			}
		}
		
		SetAttackCheck();

		AttackerPQ = priority_queue<CANON*, vector<CANON*>, AttackerCMP> ();
		DefenserPQ = priority_queue<CANON*, vector<CANON*>, DefenserCMP> ();

		CheckCanon();
		CheckArr();
		PRINT("validCanon: %d\n", validCanon);
		if (validCanon <= 1) {
			break;
		}
	}
	PRINT("\nFIN \n");
	CheckCanon();
	CheckArr();
	//가장 강한 포탑의 공격력
	maxAtt = -500;
	for (int i = 0; i <= Cidx; ++i) {
		if (Cinfo[i].destroy == 0) {
			if (Cinfo[i].str > maxAtt) {
				maxAtt = Cinfo[i].str;
			}
		}
	}

	ans = maxAtt;

	printf("%d\n", ans);
	return 0;
}
