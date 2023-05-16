#include <stdio.h>

int N=0;

int main(){
	scanf("%d",&N);
	for(int i=N; i>0; i--){
		for(int j=0; j<i; j++){
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}