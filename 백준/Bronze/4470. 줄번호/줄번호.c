#include <stdio.h>

char arr[55];
int N;

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; ++i){
		getchar();
		scanf("%[^\n]]s",arr);
		printf("%d. %s\n",i, arr);
	}	  
	return 0;
}