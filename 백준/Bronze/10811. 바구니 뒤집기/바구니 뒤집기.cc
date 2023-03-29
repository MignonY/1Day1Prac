#include <stdio.h>

int main(){
	int N; int M; int s; int e; int arr[110]; int temp; int size;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; ++i){
		arr[i] = i+1;
//		printf("%d",arr[i]);
		
		size = i;
	}
//	printf("\n");
	for(int i=0; i<M; ++i){
		scanf("%d %d", &s, &e);
		s -=1; e-=1;
		for(int j=0; j<(e-s+1)/2; ++j){
			temp = arr[s+j];
			arr[s+j] = arr[e-j];
			arr[e-j] = temp;			
		}
//		for(int i=0; i<size+1; ++i){
//		printf("%d ",arr[i]);
//	}
//	printf("\n");
	}
	
	for(int i=0; i<size+1; ++i){
		printf("%d ",arr[i]);
	}
	
	return 0;
}