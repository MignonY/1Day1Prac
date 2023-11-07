//#define PRINT printf
#define PRINT
#include <stdio.h>

int T, D, W, K;
int arr[15][23];
int oriarr[15][23];
int comb[15];
int ans = -1;

void printArr() {
	PRINT("PRINTARR\n");
	for (int i = 0; i < D; ++i) {
		for (int j = 0; j < W; ++j) {
			PRINT("%d ",arr[i][j]);
		}
		PRINT("\n");
	}
	PRINT("\n");
}
void init() {
	ans = -1;
}

int CalMbn(int n) {
	if (!n) return 0;
	if (n == 1) return 1;
	int ret = 0;
	for (int i = 0; i <= n-1; ++i) {
		int powN = 1;
		int cnt = i;
		while (cnt) {
			powN *= 2;
			cnt--;
		}
		PRINT("i:%d, ret:%d, pown:%d\n",i, ret, powN);
		ret += powN;
	}
	return ret;
}

bool check3Num() {
	bool ifTotalC = 1;
	for (int i = 0; i < W; ++i) {
		int cnt = 1;
		int cur = -1;
		for (int j = 0; j < D; ++j) {
			if (arr[j][i] != cur) {
				cur = arr[j][i];
				cnt = 1;
			}
			else cnt++;
			//PRINT("j,i:(%d,%d) cur:%d, cnt:%d\n",j,i,cur, cnt);

			if (cnt == K) break;
		}
		if (cnt != K) {
			ifTotalC = 0;
			break;
		}
	}
	PRINT("totalC:%d\n", ifTotalC);
	if (ifTotalC) {
		printArr();
	}
	return ifTotalC;
}

void nCr(int n, int r, int depth, int startidx) {
	if (ans >= 0) return;

	if (depth == r) {
		PRINT("comb:{");
		for (int i = 0; i < r; ++i) {
			PRINT("%d, ", comb[i]);
		}
		PRINT("}\n");
		int maxbn = CalMbn(r);
		PRINT("r:%d maxbn:%d\n", r,maxbn);

		if (!maxbn) {
			if (check3Num()) {
				ans = r;
				return;
			}
		}
		else {
			for (int i = 0; i <= maxbn; ++i) {
				int curbn = 1;
				int curidx = r - 1;
				while (curbn <= maxbn) {
					//comb[curidx]번째 줄을 ABnum으로 바꿨을 때의 경우. 
					int y = comb[curidx];
					int AB =  curbn & i;
					if (AB) AB = 1;
					else AB = 0;

					for (int x = 0; x < W; ++x) {
						arr[y][x] = AB;
					}
					PRINT("curbn:%d, i:%d, curidx:%d, y:%d, AB:%d\n", curbn,i, curidx, y, AB);
					curbn <<= 1;
					curidx--;

				}
				if (check3Num()) {
					ans = r;
					return;
				}
				//init
				for (int i = 0; i < r; ++i) {
					for (int j = 0; j < W; ++j) {
						arr[comb[i]][j] = oriarr[comb[i]][j];
					}
				}
			}
		}
		return;
	}

	for (int i = startidx; i < n; ++i) {
		comb[depth] = i;
		nCr(n, r, depth + 1, i + 1);
		if (ans >= 0) {
			return;
		}
	}

}

int main() {
	//freopen("yakpoom.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d %d %d", &D, &W, &K);
		for (int i = 0; i < D; ++i) {
			for (int j =0; j < W; ++j) {
				scanf("%d", &arr[i][j]);
				oriarr[i][j] = arr[i][j];
 			}
		}



		//D개(0부터 D-1)중 D개까지 뽑아서 각각 1/0으로 초기화시켰을때 성립하면 끝
		for (int r = 0; r <=D; ++r) {
			nCr(D, r, 0, 0);

		}
		

		printf("#%d %d\n", tc, ans);
		init();
	}

	return 0;
}