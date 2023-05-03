#include <stdio.h>

int N,M;


int main(){
	scanf("%d %d", &N, &M);
	if(N*100 >= M)
		printf("Yes");
	else
		printf("No");
	
	return 0;
}