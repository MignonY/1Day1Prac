#include<stdio.h>
int main() {
	int t, i, score[5];

	scanf("%d", &t);

	while (t--) {
		int sum = 0, max = 0, max2 = 0, min = 10, min2 = 10;
		for (i = 0; i < 5; i++) {
			scanf("%d", &score[i]);
			sum += score[i];
			if (max <= score[i]) {
				max2 = max;    
				max = score[i]; 
			}
			else if (max2 < score[i] && max > score[i])  
				max2 = score[i];

			if (min >= score[i]) {
				min2 = min;    
				min = score[i];  
			}
			else if (min2 > score[i] && min < score[i])
				min2 = score[i];

		}

		if (max2 - min2 >= 4)   
			printf("KIN\n");
		else                   
			printf("%d\n", sum - (max + min));
	}

	return 0;
}