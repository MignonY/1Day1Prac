#include <stdio.h>

unsigned long long N,ret;


unsigned long long fact(unsigned long long N){
	if (N==1 || N==0)
		return 1;

	return N* fact(N-1);
}



int main(){
	scanf("%d", &N);
	ret = fact(N);
	
	printf("%llu", ret);
	
	return 0;
} 