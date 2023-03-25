#include <stdio.h>

int main(){
	char ch[1050];
	int a;
	scanf("%s", &ch);
	scanf("%d", &a);
	
	printf("%c\n", ch[a-1]);
	return 0;
}