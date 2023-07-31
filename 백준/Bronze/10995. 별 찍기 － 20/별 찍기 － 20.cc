#include <stdio.h>

int main() {
	int num;
	scanf("%d", &num);
	
	int i,j;
	for (i = 0; i < num; i++) {
		if (i % 2 != 0) printf(" ");
		for (j = 0; j < num; j++)
			printf("* ");
		printf("\n");
	}
}