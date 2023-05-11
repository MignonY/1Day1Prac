#include <stdio.h>

int num,a,b;

int main(){
	scanf("%d", &num);
	for(int i=0; i<num; ++i){
		scanf("%d,%d",&a,&b);
		printf("%d\n", a+b);
	}
	
	return 0;
}