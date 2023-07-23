#include <stdio.h>
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int k = N-1; k >= 1; k--) {
		for (int l = 0; l < k; l++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}