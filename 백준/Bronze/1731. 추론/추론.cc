#include <stdio.h>

int n, p[50];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }
	if (p[1] - p[0] == p[2] - p[1]){
        //등차수열인 경우
        printf("%d", p[n - 1] + (p[1] - p[0]));
    }		
		
	else{
        //등비수열인 경우
        printf("%d", p[n - 1] * (p[1] / p[0]));
    }					
    return 0;
}
