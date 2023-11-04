#include <stdio.h>

int K, numA, numB;

int main() {
	numA = 1, numB = 0;
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		int temp = numA;
		numA = numB;
		numB = temp + numB;
	}

	printf("%d %d", numA, numB);
	return 0;
}