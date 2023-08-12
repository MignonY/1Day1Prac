#include <stdio.h>

int count,sum;
int s,n,p,q;

int main() {	
	scanf("%d", &count);
	for (int a = 0; a < count; a++) {
		scanf("%d", &s);
		sum += s;
		scanf("%d", &n);
		for (int b = 0; b < n; b++) {
			scanf("%d %d", &p, &q);
			sum += p * q;
		}
		printf("%d\n", sum);
		sum = 0;
	}
    return 0;
}