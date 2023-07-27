#include <stdio.h>

int main() {

	int n,i,j,temp,AB = 0;
	int arrA[50];
	int arrB[50];

	scanf("%d", &n);
	
	for (i=0; i<n; i++) 
		scanf("%d", &arrA[i]);
	for (i=0; i<n; i++)
		scanf("%d", &arrB[i]);


	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n - (1 + i); j++) {
			if (arrA[j] < arrA[j + 1]) {
				temp = arrA[j];
				arrA[j] = arrA[j + 1];
				arrA[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - (1 + i); j++) {
			if (arrB[j] > arrB[j + 1]) {
				temp = arrB[j];
				arrB[j] = arrB[j + 1];
				arrB[j + 1] = temp;
			}
		}
	}
    
	for (i = 0; i < n; i++) {
		AB += arrA[i] * arrB[i];
	}

	printf("%d", AB);

}