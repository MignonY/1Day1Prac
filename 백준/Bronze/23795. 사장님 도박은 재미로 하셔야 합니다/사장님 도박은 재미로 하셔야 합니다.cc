#include <stdio.h>

int input,total;

int main(){
	
	while(input != -1){
		scanf("%d", &input);
		total += input;
	}
	
	printf("%d", total+1);
	return 0;
}