#include <stdio.h>

int a, b, c;

int main(){
	scanf("%d", &a);
	scanf("%d %d", &b, &c);
	if(b/2 + c > a)
		printf("%d", a);
	else
		printf("%d", b/2+c);
	
	return 0;
}