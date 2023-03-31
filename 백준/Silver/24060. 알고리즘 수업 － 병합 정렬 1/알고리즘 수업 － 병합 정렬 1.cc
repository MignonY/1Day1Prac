#include <stdio.h>

int N, K, arr[500050], temp[500050], cnt, ans;

int merge_sort(int start, int end){
//	printf("%d %d\n", start, end);	
	if (end-start<=1)
		return 0;
	int mid = (start + end+1) / 2;	
	merge_sort(start, mid);
	merge_sort(mid, end);
	
	int p = start;
	int p1 = start;
	int p2 = mid;
	


	if(cnt >= K){
		return ans;
	}

	
	while (p<end){
		if(p2 == end || (p1< mid && arr[p1] <= arr[p2])){
		
			temp[p] = arr[p1];
			cnt++;
//			printf("cnt:%d K:%d num:%d\n ", cnt, K, temp[p]);
			if (cnt>=K){
				ans = temp[p];
				break;
			}
			p++;
			p1++;
		}
		else{
			temp[p] = arr[p2];	
			cnt++;
//			printf("cnt:%d K:%d num:%d\n ", cnt, K, temp[p]);
			if (cnt>=K){
				ans = temp[p];
				break;
			}
			p++;
			p2++;
		}
	}
		
		
	
	for (int i = start; i<end ; ++i){
		arr[i] =  temp[i];	
	}
	
	return -1;
}

int main (){
	scanf("%d %d", &N,&K);
	for(int i=0; i<N; ++i)
		scanf("%d", &arr[i]);
	
//	printf("%d %d\n",N,K);
//	for(int i=0; i<N; ++i)
//		printf("%d ", arr[i]);
//	printf("\n");
	
	printf("%d", merge_sort(0,N));
	
	return 0;
}