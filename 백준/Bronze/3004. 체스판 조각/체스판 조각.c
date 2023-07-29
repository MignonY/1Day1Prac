#include <stdio.h>
int N;
int main(){
	
	scanf("%d",&N);

	int row = N / 2 + 1;
	int col = N - row + 2;
	int res = row * col;

	printf("%d", res);

	return 0;
}