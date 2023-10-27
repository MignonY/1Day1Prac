#include <stdio.h>

int n, num, sum;

int main(){

	sum = 5;
	num = 7;
	
	scanf("%d",&n);

	for (int i = 2; i <= n; ++i) {
		sum += num;
		num += 3;

		sum %= 45678;
		num %= 45678;
	}
    
    printf("%d",sum);
	return 0;
}