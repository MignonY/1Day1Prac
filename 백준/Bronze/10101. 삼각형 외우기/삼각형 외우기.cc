#include <stdio.h>

int A,B,C;

int main(){
	scanf("%d %d %d", &A, &B, &C);
	int add = A + B + C;
	if (A == 60 && A == B && B == C) {
			printf("Equilateral");
		}
		else if (add == 180 && (A == B || B == C || C == A)) {
			printf("Isosceles");
		}
		else if (add == 180) {
			printf("Scalene");
		}
		else {
			printf("Error");
		}
}
