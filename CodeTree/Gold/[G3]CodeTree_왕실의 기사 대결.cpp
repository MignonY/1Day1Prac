//#define PRINT_ printf
//#define PRINT printf
#define PRINT
#define PRINT_
#include <stdio.h>
#include <unordered_map>
using namespace std;
int L, N, Q, r, c, h, w, k, num, d, ans;
int arr[45][45];
bool dmgarr[45][45];
bool wall[45][45];
const int dy[5] = { -1,0,1,0 };
const int dx[5] = { 0,1,0,-1 };
int movelist[45];
int midx = 1;
unordered_map<int, int> dic;

struct GISA {
	int y;
	int x;
	int h;
	int w;
	int hp;
	int getdmg;
	bool destroy;
};
GISA gisa[35];

void PrintArr() {
	for (int i = 1; i <= L; ++i) {
		for (int j = 1; j <= L; ++j) {
			PRINT("%d ", arr[i][j]);
		}
		PRINT("\n");
	}
}


void MoveGisa(int num, int dir) {
	GISA* curgisa = &gisa[num];
	int y = 0; int x = 0; int ny = 0; int nx = 0; int rmvx = 0; int rmvy = 0;
	int minx = curgisa->x; int maxx = curgisa->x + curgisa->w - 1;
	int miny = curgisa->y; int maxy = curgisa->y + curgisa->h - 1;

	if (dir == 0 || dir == 2) {
		//위 아래   
		if (dir == 0) {
			y = miny;
			rmvy = maxy;
			curgisa->y -= 1;
		}
		else if (dir == 2) {
			y = maxy;
			rmvy = miny;
			curgisa->y += 1;
		}
		for (int i = minx; i <= maxx; ++i) {
			ny = y + dy[dir];
			arr[ny][i] = num;
			arr[rmvy][i] = 0;
		}

	}
	else if (dir == 1 || dir == 3) {
		// 오 왼 
		if (dir == 1) {
			x = maxx;
			rmvx = minx;
			curgisa->x += 1;
		}
		else if (dir == 3) {
			x = minx;
			rmvx = maxx;
			curgisa->x -= 1;
		}
		for (int i = miny; i <= maxy; ++i) {
			nx = x + dx[dir];
			arr[i][nx] = num;
			arr[i][rmvx] = 0;
		}
	}
}


bool ValidMove(int num, int dir) {
	GISA* curgisa = &gisa[num];
	PRINT("num:%d, dir:%d\n", num, dir);
	int y = 0; int x = 0; int ny = 0; int nx = 0;
	int minx = curgisa->x; int maxx = curgisa->x + curgisa->w - 1;
	int miny = curgisa->y; int maxy = curgisa->y + curgisa->h - 1;
	PRINT("y(%d-%d), x(%d-%d)\n", miny, maxy, minx, maxx);
	bool valid = 0;
	if (dir == 0 || dir == 2) {
		//위 아래   
		if (dir == 0) {
			y = miny;
		}
		else if (dir == 2) {
			y = maxy;
		}

		for (int i = minx; i <= maxx; ++i) {
			nx = i;
			ny = y + dy[dir];
			if (wall[ny][nx] == 1 || nx<1 || nx>L || ny<1 || ny>L) {
				//못가는경우
				valid = 0;
				break;
			}
			else if (arr[ny][nx] != 0) {
				//다른 기사가 있는 경우 
				valid = ValidMove(arr[ny][nx], dir);
				if (valid == 0) {
					break;
				}
			}
			else {
				//갈 수 있는 경우
				valid = 1;
			}
		}
	}
	else if (dir == 1 || dir == 3) {
		// 오 왼 
		if (dir == 1) {
			x = maxx;
		}
		else if (dir == 3) {
			x = minx;
		}

		for (int i = miny; i <= maxy; ++i) {
			ny = i;
			nx = x + dx[dir];
			if (wall[ny][nx] == 1 || nx<1 || nx>L || ny<1 || ny>L) {
				//못가는경우
				valid = 0;
				break;
			}
			else if (arr[ny][nx] != 0) {
				//다른 기사가 있는 경우 
				valid = ValidMove(arr[ny][nx], dir);
				if (valid == 0) {
					break;
				}
			}
			else {
				//갈 수 있는 경우
				valid = 1;
			}
		}
	}

	if (valid && dic.find(num) == dic.end()) {
		PRINT_("midx-1:%d, midx:%d\n", midx - 1, midx);
		dic[num] += 1;
		movelist[midx] = num;
		midx++;
	}
	PRINT_("valid:%d\n", valid);
	return valid;

}

void CalDmg(int num) {
	GISA* curgisa = &gisa[num];
	int minx = curgisa->x; int maxx = curgisa->x + curgisa->w - 1;
	int miny = curgisa->y; int maxy = curgisa->y + curgisa->h - 1;
	bool destroy = 0;
	PRINT_("caldmg[%d], y(%d-%d), x(%d-%d)\n", num, miny, maxy, minx, maxx);

	for (int i = miny; i <= maxy; ++i) {
		for (int j = minx; j <= maxx; ++j) {
			if (dmgarr[i][j] != 0) {
				curgisa->getdmg += 1;
				PRINT_("cur[%d], ij:(%d,%d)\n", num, i, j);
				if (curgisa->getdmg == curgisa->hp) {
					curgisa->destroy = 1;
					destroy = 1;
					break;
				}
			}
		}
		if (destroy) {
			break;
		}
	}

	if (destroy) {
		for (int i = miny; i <= maxy; ++i) {
			for (int j = minx; j <= maxx; ++j) {
				arr[i][j] = 0;
			}
		}
	}

}

int main() {

	scanf("%d %d %d", &L, &N, &Q);
	for (int i = 1; i <= L; ++i) {
		for (int j = 1; j <= L; ++j) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				dmgarr[i][j] = 1;
			}
			else if (arr[i][j] == 2) {
				wall[i][j] = 1;
			}
			arr[i][j] = 0;
		}
	}

	for (int i = 1; i <= N; ++i) {
		scanf("%d %d %d %d %d", &r, &c, &h, &w, &k);
		gisa[i].y = r, gisa[i].x = c;
		gisa[i].h = h, gisa[i].w = w;
		gisa[i].hp = k;

		for (int Y = r; Y < r + h; ++Y) {
			for (int X = c; X < c + w; ++X) {
				arr[Y][X] = i;
			}
		}
	}

	//PrintArr();


	//simulation
	for (int tc = 1; tc <= Q; ++tc) {
		scanf("%d %d", &num, &d);
		//PRINT("tc:%d | num:%d | dir:%d\n", tc, num, d);

		if (gisa[num].destroy == 0 && ValidMove(num, d) == 1) {
			PRINT_("tc:%d | num:%d | dir:%d\n", tc, num, d);
			for (int i = 1; i < midx; ++i) {
				MoveGisa(movelist[i], d);
			}
			PRINT_("PRINT_Movelist : %d\n", midx);
			for (int i = 1; i < midx; ++i) {
				PRINT_("%d ", movelist[i]);
			}
			PRINT_("\n");
			for (int i = 1; i < midx; ++i) {
				if (movelist[i] != num) {
					CalDmg(movelist[i]);
				}
			}
		}

		//PrintArr();
		dic.clear();
		midx = 1;
		PRINT_("\n");
	}

	for (int i = 1; i <= N; ++i) {
		if (gisa[i].getdmg) {
			PRINT_("gisa[%d], dmg:%d, hp:%d, destroy:%d\n", i, gisa[i].getdmg, gisa[i].hp, gisa[i].destroy);
		}
		if (gisa[i].destroy == 0) {
			ans += gisa[i].getdmg;
		}
	}

	printf("%d\n", ans);

	return 0;
}
