#include <stdio.h>
#include <string.h>

int T, N, L[100];
char S[100][21];

int main() {
	scanf("%d", &T);			

	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		int max_num = 0;			
		int max_sul = 0;				
		
		for (int j = 0; j < N; j++) {
			scanf("%s%d", &S[j], &L[j]);
			if (L[j] > max_sul) {		// 술 소비량 비교
				max_sul = L[j];
				max_num = j;
			}
		}
		printf("%s\n", S[max_num]);
	}

}