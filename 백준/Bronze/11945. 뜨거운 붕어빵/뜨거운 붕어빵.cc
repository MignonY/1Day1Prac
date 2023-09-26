#include <stdio.h>
char arr[10][10];

int n, m;

int main() {
    scanf("%d %d", &n, &m);
    
	for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            scanf(" %c", &arr[i][j]);
        }
    }
		
	for (int i = 0; i < n; ++i) {
		for (int j = m - 1; j >= 0; --j){
            printf("%c",arr[i][j]);
        }
		printf("\n");
	}
	return 0;
}
