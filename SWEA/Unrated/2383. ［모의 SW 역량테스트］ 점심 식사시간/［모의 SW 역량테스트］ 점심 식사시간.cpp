//#define PRINT printf
#define PRINT
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))
#include <stdio.h>
#include <algorithm>
using namespace std;
int T, N, P, ans, time, mintime = 10000000;
int arr[13][13];
int grp1[12], grp2[12];
bool picked[12];
int Pidx = 1, Sidx = 1, G1idx, G2idx;
struct PPL {
	int y, x;
	int DstartTime;
	bool instair;
	bool exit;
	int stair;
};
PPL people[15];
PPL initp;
struct STAIR {
	int y, x;
	int time;
	int pnum;
};
STAIR stair[4];
bool intcmp(int a, int b) {
	return a < b;
}
bool sortcmp(int a, int b) {
	return people[a].DstartTime < people[b].DstartTime;
}

void init() {
	ans = time = 0;
	mintime = 10000000;
	bool picked[12];
	for (int i = 0; i < 12; ++i) {
		picked[i] = 0;
	}
	Pidx = 1, Sidx = 1;
	G1idx = G2idx = 0;
}

void PrintGrp() {
	PRINT("\nGr[1] {");
	for (int i = 0; i < G1idx; ++i) {
		PRINT("%d ", grp1[i]);
	}
	PRINT("}\n");

	PRINT("Gr[2] {");
	for (int i = 0; i < G2idx; ++i) {
		PRINT("%d ", grp2[i]);
	}
	PRINT("}\n");
}

int CalDist(int y1, int x1, int y2, int x2) {
	return ABS(y1 - y2) + ABS(x1 - x2);
}

void initdata() {
	for (int i = 1; i < Pidx; ++i) {
		people[i].DstartTime = 0;
		people[i].exit = 0;
		people[i].instair = 0;
		people[i].stair = 0;
	}
	G2idx = 0;
	for (int i = 0; i < Pidx; ++i) {
		picked[i] = 0;
	}
}

void nCr(int n, int r, int depth, int startidx) {
	if (depth == r) {
		initdata();
		G1idx = depth;
		for (int j = 0; j < G1idx; ++j) {
			picked[grp1[j]] = 1;
			int py = people[grp1[j]].y; int px = people[grp1[j]].x;
			int sy = stair[1].y; int sx = stair[1].x;
			people[grp1[j]].DstartTime = CalDist(py, px, sy, sx);
			people[grp1[j]].stair = arr[sy][sx];
		}
		for (int j = 1; j < Pidx; ++j) {
			if (!picked[j]) {
				grp2[G2idx++] = j;
				int py = people[j].y; int px = people[j].x;
				int sy = stair[2].y; int sx = stair[2].x;
				people[j].DstartTime = CalDist(py, px, sy, sx);
				people[j].stair = arr[sy][sx];
			}
		}
		//PRINT("%d %d",G1idx, G2idx);
		sort(grp1, grp1 + G1idx, sortcmp);
		sort(grp2, grp2 + G2idx, sortcmp);
		PrintGrp();

		time = 0;
		while (1) {
			time++;
			//PRINT("time[%d]", time);
			for (int g = 0; g < G1idx; ++g) {
				int num = grp1[g];
				if (!people[num].exit) {
					//현재 탈출상태가 아닌 사람들 중
					int exitT = people[num].DstartTime + people[num].stair;
					if (people[num].DstartTime + 1<= time && people[num].instair == 0 && stair[1].pnum < 3) {
						//계단에 도달 가능하고 (대기중) && 현재 계단에 3명 미만일때 
						people[num].DstartTime = time;
						people[num].instair = 1;
						stair[1].pnum++;
					}
					else if (people[num].instair && exitT <= time) {
						//계단 안에 있는데 완료시간됨
						people[num].instair = 0;
						people[num].exit = 1;
						stair[1].pnum--;
					}
				}
			}
			for (int g = 0; g < G2idx; ++g) {
				int num = grp2[g];
				if (!people[num].exit) {
					//현재 탈출상태가 아닌 사람들 중
					int exitT = people[num].DstartTime + people[num].stair;
					if (people[num].DstartTime + 1 <= time && people[num].instair == 0 && stair[2].pnum < 3) {
						//계단에 도달 가능하고 (대기중) && 현재 계단에 3명 미만일때 
						people[num].DstartTime = time;
						people[num].instair = 1;
						stair[2].pnum++;
					}
					else if (people[num].instair && exitT <= time) {
						//계단 안에 있는데 완료시간됨
						people[num].instair = 0;
						people[num].exit = 1;
						stair[2].pnum--;
					}
				}
			}


			bool totalexit = 1;
			//전부 탈출인지 확인
			//PRINT("time[%d]\n",time);
			for (int p = 1; p < Pidx; ++p) {
				//PRINT("people[%d] | DstartT:%d, stair:%d , ing:%d, Exit:%d\n",p, people[p].DstartTime, people[p].stair, people[p].instair, people[p].exit);
				if (!people[p].exit) {
					totalexit = 0;
					//break;
				}
			}
			if (totalexit) {
				PRINT("Time:%d | MinTime:%d\n", time, mintime);
				if (mintime > time) mintime = time;
				break;
			}
		}
		sort(grp1, grp1 + G1idx, intcmp);
		sort(grp2, grp2 + G2idx, intcmp);
		return;
	}

	for (int i = startidx; i <= n; ++i){
		grp1[depth] = i;
		nCr(n, r, depth + 1, i + 1);
	}
}



int main() {
	//freopen("sample_input_.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				scanf("%d", &arr[i][j]);
				if (arr[i][j] == 1) {
					people[Pidx].y = i, people[Pidx].x = j;
					Pidx++;
				}
				if (arr[i][j] >= 2) {
					stair[Sidx].y = i, stair[Sidx].x = j;
					stair[Sidx].time = arr[i][j];
					Sidx++;
				}
			}
		}

		//grp1, grp2에 사람 나눠담는 조합 짜기 
		//계단 거리순으로 오름차순 정렬,
		//while 돌려서 전부 완료되는 시간 도출하고 min값 갱신  

		mintime = 10000000;
		for (int i = 0; i < Pidx; ++i) {
			PRINT("Pidx:%d\n", Pidx);
			nCr(Pidx - 1, i, 0, 1);
			G1idx = 0;
		}

		ans = mintime;

		printf("#%d %d\n", tc, ans);
		init();
	}

	return 0;
}