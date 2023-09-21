#include <stdio.h>

int t; 
int n, k, temp, cnt;

int main() {	

    scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%d %d", &n,&k);
		cnt = 0;
		for (int j = 0; j < n; ++j) {
			scanf("%d",&temp);
			while (temp >= k) {
				cnt++;
				temp -= k;
			}
		}
		printf("%d\n",cnt);
	}
}
