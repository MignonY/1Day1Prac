#include <stdio.h>

int a,b,minv=100000;

int main(){
	for(int i=0; i<3; ++i){
		scanf("%d",&a);
		if(a < minv){
			minv = a;
		}
	}
	a = minv;
	minv = 100000;
	for(int i=0; i<2; ++i){
		scanf("%d",&b);
		if(b < minv){
			minv = b;
		}
	}
	b = minv;
	printf("%d", a+b-50);
	
	return 0;
}