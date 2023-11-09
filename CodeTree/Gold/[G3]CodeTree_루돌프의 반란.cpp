//#define PRINT printf
#define PRINT

#include <stdio.h>

using namespace std;

struct SANTA {
	int y, x;
	int stunturn;
	bool stun;
	bool fail;
	int score;
};
struct RUDOLF {
	int y, x;
};

SANTA santa[35];
RUDOLF rudolf;

int N, M, P, C, D, Rr, Rc, Pn, Sr, Sc;
int arr[53][53]; //산타만 표시 
int RcollideArr[53];
int ScollideArr[53];
int Ridx, Sidx;
const int dy[10] = { 0,1,0,-1,-1,-1,1,1 };
const int dx[10] = { -1,0,1,0,-1,1,-1,1 };

void printArr() {
	PRINT("PRINT_Arr\n");
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			PRINT("%d ", arr[i][j]);
		}
		PRINT("\n");
	}
	PRINT("rudolf (%d,%d)\n", rudolf.y, rudolf.x);
	PRINT("\n");
}


int CalDist(int y1, int x1, int y2, int x2) {
	return (y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2);
}

void interact(int nowS, int oriy, int orix, int dir) {
	//현재산타 이동시키기
	int y = oriy; int x = orix;
	int ny = 0; int nx = 0;
	int curS = nowS;
	int nextS = arr[y][x];
	if(nextS){
		while (1) {
			PRINT("curS:%d , nextS: %d\n", curS, nextS);
			nextS = arr[y][x];
			santa[curS].y = y;
			santa[curS].x = x;
			arr[y][x] = curS;
			ny = y + dy[dir];
			nx = x + dx[dir];
			y = ny, x = nx;
			curS = nextS;
			if (y<1 || y>N || x<1 || x>N) {
				if (curS != 0) {
					PRINT("santa[%d] | (%d,%d) -> fail\n", curS, y, x);
					santa[curS].y = y;
					santa[curS].x = x;
					santa[curS].fail = 1;
					break;
				}
			}
			else {
				if (arr[y][x] == 0) {
					santa[curS].y = y;
					santa[curS].x = x;
					arr[y][x] = curS;
					break;
				}
			}
		}
	}
	else {
		santa[curS].y = y;
		santa[curS].x = x;
		arr[y][x] = curS;
	}


}

void collide(int snum, int dir, int turn, bool StoR) {
	santa[snum].stunturn = turn;
	santa[snum].stun = 1;
	int ny = 0; int nx = 0;
	int y = rudolf.y; int x = rudolf.x;
	if (StoR) {
		//산타가 루돌프 충돌
		dir = (dir + 2) % 4;
		santa[snum].score += D;
		ny = y + dy[dir] * D;
		nx = x + dx[dir] * D;
		PRINT("stoR [%d] | (%d,%d)\n", snum, ny, nx);
		if (ny<1 || ny>N || nx<1 || nx>N) {
			santa[snum].y = 0;
			santa[snum].x = 0;
			santa[snum].fail = 1;
		}
		else {
			interact(snum, ny, nx, dir);
		}
	}
	else {
		//루돌프가 산타 충돌
		santa[snum].score += C;
		ny = y + dy[dir] * C;
		nx = x + dx[dir] * C;
		PRINT("RtoS [%d] | dir(%d) | (%d,%d)->(%d,%d)\n", snum, dir, y,x,ny, nx);
		if (ny<1 || ny>N || nx<1 || nx>N) {
			santa[snum].y = 0;
			santa[snum].x = 0;
			santa[snum].fail = 1;
		}
		else {
			interact(snum, ny, nx, dir);
		}
	}
}

void rudolfMove(int ry, int rx, int turn) {
	//가장 가까운 산타 찾기
	int snum = 0;
	int mindist = 10000000;
	int maxy = 0;
	int maxx = 0;
	int dret = 0;
	for (int i = 1; i <= P; ++i) {
		if (santa[i].fail == 0) {
			dret = CalDist(ry, rx, santa[i].y, santa[i].x);
			PRINT("ori(%d,%d) | san(%d %d) | mindist:%d | dist: %d \n", maxy, maxx, santa[i].y, santa[i].x, mindist, dret);
			if (dret < mindist) {
				snum = i;
				mindist = dret;
				maxy = santa[i].y;
				maxx = santa[i].x;
			}
			else if (dret == mindist) {
				if (maxy == santa[i].y) {
					if (maxx < santa[i].x) {
						snum = i;
						maxx = santa[i].x;
					}
				}
				else if (maxy < santa[i].y) {
					snum = i;
					maxy = santa[i].y;
					maxx = santa[i].x;
				}
			}
		}
	}
	PRINT("r_to_snum: [%d]\n", snum);
	//산타를 향한 가장 가까운 방향 찾기 
	int dir = -1;
	int ny = 0; int nx = 0;
	int newdret = 0;
	int mindret = 10000000;
	for (int i = 0; i < 8; ++i) {
		ny = ry + dy[i];
		nx = rx + dx[i];
		newdret = CalDist(ny, nx, maxy, maxx);
		if (mindret > newdret) {
			mindret = newdret;
			dir = i;
		}
	}

	//해당 방향으로 루돌프 한칸 이동
	rudolf.y += dy[dir];
	rudolf.x += dx[dir];
	if (arr[rudolf.y][rudolf.x] != 0) {
		//만약 그자리에 산타가 있으면 충돌처리 
		arr[rudolf.y][rudolf.x] = 0;
		collide(snum, dir, turn, 0);
	}
}

void santaMove(int turn) {
	for (int sn = 1; sn <= P; ++sn) {
		if (santa[sn].fail == 0) {
			//탈락x
			if (santa[sn].stun == 0) {
				//기절 X 
				int y = santa[sn].y;
				int x = santa[sn].x;

				//루돌프를 향한 가장 가까운 방향 찾기 
				int dir = -1;
				int ny = 0; int nx = 0;
				int newdret = 0;
				int mindret = CalDist(y,x,rudolf.y,rudolf.x);
				bool move = 0;
				for (int i = 0; i < 4; ++i) {
					ny = y + dy[i];
					nx = x + dx[i];
					newdret = CalDist(ny, nx, rudolf.y, rudolf.x);
					if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && mindret >= newdret && arr[ny][nx] == 0) {
						mindret = newdret;
						dir = i;
						//해당 방향으로 santa 이동 갱신
						santa[sn].y = ny;
						santa[sn].x = nx;
						move = 1;
					}
				}
				if (move) {
					if (santa[sn].y == rudolf.y && santa[sn].x == rudolf.x) {
						//가려는 방향에 루돌프가 있으면 충돌처리 
						arr[y][x] = 0;
						collide(sn, dir, turn, 1);
					}
					else {
						//아니면 그냥 전진 
						arr[y][x] = 0;
						arr[santa[sn].y][santa[sn].x] = sn;
					}
				}
			}
		}
	}

}



int main() {
	scanf("%d %d %d %d %d", &N, &M, &P, &C, &D);
	scanf("%d %d", &Rr, &Rc);
	rudolf.y = Rr;
	rudolf.x = Rc;

	for (int i = 1; i <= P; ++i) {
		scanf("%d %d %d", &Pn, &Sr, &Sc);
		santa[Pn].y = Sr;
		santa[Pn].x = Sc;
		arr[Sr][Sc] = Pn;
	}

	printArr();
	for (int turn = 1; turn <= M; ++turn) {

		PRINT("turn [%d]\n", turn);
		rudolfMove(rudolf.y, rudolf.x, turn);
		santaMove(turn);

		bool Exit = 1;
		//santa_check
		for (int i = 1; i <= P; ++i) {
			if (santa[i].fail == 0) {
				Exit = 0;
				santa[i].score++;
				if (turn - santa[i].stunturn >= 1) {
					santa[i].stun = 0;
				}
			}
			PRINT("santa[%d] | (%d,%d) , stun:%d fail:%d | score:%d\n", i, santa[i].y, santa[i].x, santa[i].stunturn, santa[i].fail, santa[i].score);
		}

		printArr();

		if (Exit) {
			break;
		}

	}

	PRINT("ANS_PRINT\n");
	for (int i = 1; i <= P; ++i) {
		printf("%d ", santa[i].score);
	}
	printf("\n");
	;
	return 0;
}
