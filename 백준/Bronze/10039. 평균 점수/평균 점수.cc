#include <stdio.h>
#define BC(x) ((x) >= 40 ? (x) : (40))

int n,N;

int main(){
	for(int i=0; i<5; ++i){
		scanf("%d", &n);
		N += BC(n);
	}
	printf("%d", N/5);
}