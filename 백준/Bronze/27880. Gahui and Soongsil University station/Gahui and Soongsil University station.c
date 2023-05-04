#include <stdio.h>
#include <string.h>
 
char CMD[10];
int N, SUM;

int main(){
	
	while(scanf("%s %d", CMD, &N) != EOF){
		if(!strcmp(CMD, "Es")){
			SUM += 21 * N;
		}
		else if (!strcmp(CMD,"Stair")){
			SUM += 17 * N;
		}
//		printf("cmd : %s\n",CMD);
//		printf("n : %d\n",N);
//		printf("sum : %d\n", SUM);
	}
	
	printf("%d", SUM);
	 
	return 0;
}