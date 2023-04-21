#include <stdio.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N, M, x, y;
int arr[500005], aidx, memo[20000005];

unordered_map<int,int> dic;



bool binary_search(int n, int start, int end, int arr[], int* ans){
	while (1){	
		int mid = (start + end) / 2;
//		printf("start = %d mid = %d, end = %d, arr[mid]:%d\n", start, mid, end, arr[mid]);

		if (arr[mid] == n){
//			printf("mid : %d, %d\n", mid, arr[mid]);
			*ans += 1;
			int pt = mid-1;
			while(pt>=0 && arr[pt] == n){
				pt--;
				(*ans)++;
			}
			pt = mid+1;
			while(pt<N && arr[pt] == n){
				pt++;
				(*ans)++;
			}
//			printf("midans : %d\n", *ans);
			return true;
		}
	
		if(end - start <= 1)
			break;
		
		if (arr[mid] < n)
			start = mid;
		
		else
			end = mid;
	}
	
	return false;
}



int main(){
	scanf("%d", &N);

	for(int i=0; i<N; ++i){
		scanf("%d", &x);
		arr[aidx++] = x;
	}
	scanf("%d", &M);
	
	sort(arr, arr+aidx);
//	for(int i=0; i<aidx; ++i){
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
	
	for(int i=0; i<M; ++i){
		scanf("%d", &y);
		int ans = 0;
		if (memo[y+10000000]){
			ans = memo[y+10000000];
		}
		else{
			binary_search(y,0,aidx,arr, &ans);
			memo[y+10000000] =ans;
		}
		 
		printf("%d ", ans);
	}
	printf("\n");

	return 0;
}