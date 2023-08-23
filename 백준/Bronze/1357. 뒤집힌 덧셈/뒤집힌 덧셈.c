#include<stdio.h>

int Rev(int X){
	int reversed=0;
    
	while(X>0){
		reversed*=10;
		reversed+=X%10;
		X/=10;
	}

	return reversed;
}

int main(){
	int X, Y;

	scanf("%d %d", &X, &Y);

	X=Rev(X);
	Y=Rev(Y);

	printf("%d\n", Rev(X+Y));

	return 0;
}