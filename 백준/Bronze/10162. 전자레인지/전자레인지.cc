#include <stdio.h>

int t;
int arr[3] = {300, 60, 10}, count[3];

int main() {
	
	scanf("%d", &t);
	if (t % 10 == 0) {
		for(int i=0; i<3; i++) {
			while (t>=arr[i]) {
				t -= arr[i];
				count[i] ++;
			}
			if(t == 0) {
				break;
			}
		}
		for (int i=0; i<3; i++) {
			printf("%d ", count[i]);
		}
	} else {
		printf("-1");
	}
}