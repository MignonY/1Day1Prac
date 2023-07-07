#include <stdio.h>
long long i, j;

int main(){
	scanf("%lld %lld", &i,&j);
	if (j >= i)
		printf("%lld", (j - i + 1)*(i + j) / 2);
	else
		printf("%lld",(i - j + 1)*(i + j) / 2);
}