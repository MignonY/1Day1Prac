//#define PRINT printf
#define PRINT
#define new_shark (&shark_pool[Sidx++])
#include <stdio.h>

int Y, X, M, y,x,s,dir,big, FishKingX, SharkGot;
int SArr[150][150];
const int dy[5] = {-1,1,0,0};
const int dx[5] = {0,0,1,-1};

struct SHARK {
	int y, x, s, dir, big;
	bool caught;
};

SHARK shark_pool[10005];
int Sidx = 1; 


void PrintTest(int Y, int X) {
	PRINT("\nPRINT_TEST\n");
	for (int i = 0; i <= Y; ++i) {
		for (int j = 0; j <= X; ++j) {
			PRINT("%d ", SArr[i][j]);
		}
		PRINT("\n");
	}
}

void SharkCheck() {
	for (int i = 1; i <= Sidx - 1; ++i) {
		PRINT("shark[%c] | %d | y,x: (%d,%d) | dir: %d | speed:%d, big:%d\n", i+64, shark_pool[i].caught, shark_pool[i].y, shark_pool[i].x, shark_pool[i].dir, shark_pool[i].s, shark_pool[i].big);
	}
}

int CatchShark(int Y, int X) {
	int SharkBig = 0; 
	int x = X, y = 0;
	bool Flag = 0;
	while (y < Y && SArr[y][x] == 0) {
		y++;
		if (SArr[y][x]) {
			Flag = 1;
		}
		PRINT("y:%d || SArr[y][x]:%d || Flag:%d \n", y, SArr[y][x], Flag);
	}
	if (Flag) {
		SharkBig = shark_pool[SArr[y][x]].big;
		shark_pool[SArr[y][x]].caught = 1;
		SArr[y][x] = 0;
	}
	PRINT("SharkBig: %d\n", SharkBig);
	return SharkBig;
}


void SharkMove(int Y, int X) {
	//initArr
	for (int i = 0; i <= Y; ++i) {
		for (int j = 0; j <= X; ++j) {
			SArr[i][j] = 0;
		}
	}
	//PrintTest(Y, X);
	for (int i = 1; i <= Sidx-1; ++i) {
		SHARK CurrentShark = shark_pool[i];
		
		if (shark_pool[i].caught == 0) {
			int Speed = CurrentShark.s;
			int Dir = CurrentShark.dir;
			int y = CurrentShark.y;
			int x = CurrentShark.x;

			while (Speed > 0) {
				if (Dir == 0) {
					if (Speed >= y - 1) {
						Speed -= y - 1;
						y = 1;
						Dir = 1;
					}
					else {
						y -= Speed;
						Speed = 0;
					}
				}
				else if (Dir == 1) {
					if (y + Speed >= Y) {
						Speed -= Y - y;
						y = Y;
						Dir = 0;
					}
					else {
						y += Speed;
						Speed = 0;
					}
				}
				else if (Dir == 2) {
					if (x + Speed >= X) {
						Speed -= X - x;
						x = X;
						Dir = 3;
					}
					else {
						x += Speed;
						Speed = 0;
					}
				}
				else if (Dir == 3) {
					if (Speed >= x - 1) {
						Speed -= x - 1;
						x = 1;
						Dir = 2;
					}
					else {
						x -= Speed;
						Speed = 0;
					}
				}
				
			}


			shark_pool[i].y = y;
			shark_pool[i].x = x;
			shark_pool[i].dir = Dir;
			PRINT("shark[%d] | y,x: (%d,%d) | dir: %d | speed:%d, big:%d\n", i, shark_pool[i].y, shark_pool[i].x, shark_pool[i].dir, shark_pool[i].s, shark_pool[i].big);
				
			if (SArr[y][x] == 0) {
				SArr[y][x] = i;
			}
			else {
				PRINT("//PREV shark[%d] | y,x: (%d,%d) | dir: %d | speed:%d, big:%d\n", SArr[y][x], shark_pool[SArr[y][x]].y, shark_pool[SArr[y][x]].x, shark_pool[SArr[y][x]].dir, shark_pool[SArr[y][x]].s, shark_pool[SArr[y][x]].big);
				int prevbig = shark_pool[SArr[y][x]].big;
				int currentbig = shark_pool[i].big;
				if (currentbig > prevbig) {
					shark_pool[SArr[y][x]].caught = 1;
					SArr[y][x] = i;
				}
				else {
					shark_pool[i].caught = 1;
				}
			}

		}
	}
}



int main() {
	scanf("%d %d %d", &Y,&X,&M);
	for (int i = 1; i <= M; ++i) {
		scanf("%d %d %d %d %d", &y, &x, &s, &dir, &big);
		SHARK *shark = new_shark;
		shark->y = y, shark->x = x, shark->s = s, shark->dir = dir-1, shark->big = big;
		//PRINT("%d %d %d %d %d\n", shark_pool[i].y, shark_pool[i].x, shark_pool[i].s, shark_pool[i].dir, shark_pool[i].big);
		SArr[y][x] = i;
	}
	
	PrintTest(Y,X);
	

	while (FishKingX < X) {
		FishKingX++;
		//PRINT("-------\n");
		//PrintTest(Y, X);
		SharkGot += CatchShark(Y,FishKingX);
		PRINT("FishKingX: %d || SharkGot: %d\n", FishKingX, SharkGot);
		SharkMove(Y,X);
		//PrintTest(Y, X);
		//SharkCheck();
	}

	printf("%d", SharkGot);

	return 0;
}