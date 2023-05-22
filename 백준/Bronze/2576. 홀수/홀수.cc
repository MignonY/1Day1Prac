#include <stdio.h>

int N, sum, minv=10000;

int main(){
	for(int i=0; i<7; ++i){
		scanf("%d", &N);
		if(N % 2){
			sum += N;
			if(minv > N)
				minv = N;
		}
	}
	
	if(!sum)
		printf("-1\n");
	else
		printf("%d\n%d\n",sum, minv);
	
	
	return 0;
}