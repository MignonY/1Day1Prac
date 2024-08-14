#include <stdio.h>
#include <vector>
//#define PRINT printf
#define PRINT
using namespace std; 

int N, M, ans;
char arr[13][13];
bool bGoal, rGoal;

struct POS {
	int y, x;
	bool goal;
};
POS init_rPos, init_bPos;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };


void PrintArr(int ry, int rx, int by, int bx) {
	PRINT("\n");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (i == ry && j == rx) {
				PRINT("%R");
			}
			else if (i == by && j == bx) {
				PRINT("%B");
			}
			else {
				PRINT("%c", arr[i][j]);
			}
		}
		PRINT("\n");
	}
}


struct Q {
	POS rpos, bpos;
	int time, pastDir;
};

Q que[150000];

pair<POS,POS> RollBids(int dir, POS rpos, POS bpos) {
	int ry = rpos.y; int rx = rpos.x;
	int by = bpos.y; int bx = bpos.x;

	if (dir == 0) {
		//상
		while (arr[ry][rx] != '#' && ry > 0) {
			ry += dy[dir];
			if (arr[ry][rx] == 'O') {
				rpos.goal = true;
				ry += dy[dir];
				break;
			}
		}
		ry -= dy[dir];

		while (arr[by][bx] != '#' && by > 0) {
			by += dy[dir];
			if (arr[by][bx] == 'O') {
				bpos.goal = true;
				by += dy[dir];
				break;
			}
		}
		by -= dy[dir];

		if ((ry == by && rx == bx))
		{
			if (rpos.y < bpos.y) {
				by -= dy[dir];
			}
			else {
				ry -= dy[dir];
			}
		}
	}
	else if (dir == 1) {
		//우
		while (arr[ry][rx] != '#' && rx < M-1) {
			rx += dx[dir];
			if (arr[ry][rx] == 'O') {
				rpos.goal = true;
				rx += dx[dir];
				break;
			}
		}
		rx -= dx[dir];

		while (arr[by][bx] != '#' && bx < M-1) {
			bx += dx[dir];
			if (arr[by][bx] == 'O') {
				bpos.goal = true;
				bx += dx[dir];
				break;
			}
		}
		bx -= dx[dir];

		if ((ry == by && rx == bx))
		{
			if (rpos.x < bpos.x) {
				rx -= dx[dir];
			}
			else {
				bx -= dx[dir];
			}
		}
	}
	else if (dir == 2) {
		//하
		while (arr[ry][rx] != '#' && ry < N-1) {
			ry += dy[dir];
			if (arr[ry][rx] == 'O') {
				rpos.goal = true;
				ry += dy[dir];
				break;
			}
		}
		ry -= dy[dir];

		while (arr[by][bx] != '#' && by < N-1) {
			by += dy[dir];
			if (arr[by][bx] == 'O') {
				bpos.goal = true;
				by += dy[dir];
				break;
			}
		}
		by -= dy[dir];

		if ((ry == by && rx == bx))
		{
			if (rpos.y < bpos.y) {
				ry -= dy[dir];
			}
			else {
				by -= dy[dir];
			}
		}
	}
	else {
		//좌
		while (arr[ry][rx] != '#' && rx > 0) {
			rx += dx[dir];
			if (arr[ry][rx] == 'O') {
				rpos.goal = true;
				rx += dx[dir];
				break;
			}
		}
		rx -= dx[dir];

		while (arr[by][bx] != '#' && bx > 0) {
			bx += dx[dir];
			if (arr[by][bx] == 'O') {
				bpos.goal = true;
				bx += dx[dir];
				break;
			}
		}
		bx -= dx[dir];

		if ((ry == by && rx == bx))
		{
			if (rpos.x < bpos.x) {
				bx -= dx[dir];
			}
			else {
				rx -= dx[dir];
			}
		}
	}

	rpos.y = ry, rpos.x = rx;
	bpos.y = by, bpos.x = bx;

	return make_pair(rpos, bpos);
}


int BFS(POS start_rPos, POS start_bPos) {

	int rear = -1; 
	int front = 0; 
	
	rear++;

	que[rear].rpos = start_rPos;
	que[rear].bpos = start_bPos;
	que[rear].time = 0;
	que[rear].pastDir = -1;

	while (rear + 1 != front) {
		POS rpos = que[front].rpos;
		POS bpos = que[front].bpos;
		int time = que[front].time;
		int pastDir = que[front].pastDir;
		front++;

		if (time == 10) {
			return -1;
		}

		for (int i = 0; i < 4; ++i) {
			
			if (i == pastDir) {
				continue;
			}			
			pair<POS, POS> simulRet = RollBids(i, rpos, bpos);
			POS n_rPos = simulRet.first;
			POS n_bPos = simulRet.second;

			if (n_rPos.goal == true && n_bPos.goal == false) {
				return (time + 1);
			}

			if (n_bPos.goal == true) {
				continue;
			}

			rear++;
			que[rear].rpos = n_rPos;
			que[rear].bpos = n_bPos;	
			que[rear].pastDir = (i + 2) % 4;
			que[rear].time = time + 1;
		}
	}

	return -1;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == 'R') {
				init_rPos.y = i;
				init_rPos.x = j;
				arr[i][j] = '.';
			}
			if (arr[i][j] == 'B') {
				init_bPos.y = i;
				init_bPos.x = j;
				arr[i][j] = '.';
			}
		}
	}

	ans = BFS(init_rPos, init_bPos);
	printf("%d", ans);

	return 0;
}