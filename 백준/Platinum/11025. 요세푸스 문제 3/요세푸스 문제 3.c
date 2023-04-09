#include <stdio.h>

int N, K, num=1;

void GET_NUM(){
	for(int i =2; i<=N; i++)
		num = (num + (K - 1) ) % i + 1;
	
}

int main(){
	scanf("%d %d", &N, &K);
	GET_NUM(); 
	
	printf("%d", num);
	
	return 0;
}
