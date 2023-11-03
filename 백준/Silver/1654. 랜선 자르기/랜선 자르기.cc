//#define PRINT printf
#define PRINT
#include <stdio.h>
#include <algorithm>
using namespace std;

long long K, N, maxN, maxL, arr[10005];

bool cmp(const int& a, const int& b) {
	return a < b;
}

void binary_search(long long sidx, long long eidx) {
	//최대 길이로 최대 개수 구하기 
	while (1) {
		long long mid = (sidx + eidx) / 2;
		long long num = 0;

		for (int i = 0; i < K; ++i) {
			num += arr[i] / mid;
			if (num > N) {
				break;
			}
		}

		PRINT("start:%d  mid:%d  end:%d  ->  num:%d , maxL:%d\n", sidx, mid, eidx, num, maxL);
		if (num >= N) {
			//N개 이상을 만들면서
			if (maxL <= mid) {
				//길이는 더 짧아지면 안됨 
				maxL = mid;
				//더 큰 쪽으로 탐색
				if (eidx - sidx <= 1) {
					//if (eidx == maxN) maxL = eidx;
					return;
				}
				sidx = mid;
			}
		}
		else {
			//개수가 적게 나옴 (길이 너무 큼) -> 작은쪽 탐색
			eidx = mid;
		}
		PRINT("start:%d  mid:%d  end:%d  ->  num:%d , maxL:%d\n\n", sidx, mid, eidx, num, maxL);
	}
}

int main() {
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; ++i) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + K, cmp);
	maxN = arr[K - 1] + 1;
	maxL = 0;
	binary_search(1, maxN);

	printf("%d\n", maxL);
	return 0;
}