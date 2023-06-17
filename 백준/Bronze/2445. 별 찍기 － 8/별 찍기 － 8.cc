#include <stdio.h>
int main(void) {
    int a;
    int i = 0; 
    int j = 0;

    scanf("%d", &a);
    int l = a-2;
    int m = 0;
    for(i=1;i<a+1;i++) {
        for (j = 0; j < i;j++) {
            printf("*");
        }
        for (int k = l; k>=0;k--) {
            printf(" ");
        }
        for (int k = l; k >= 0; k--) {
            printf(" ");
        }
        for (j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
        l--;
    }
    for (i = a - 1; i >= 0; i--) {
        for (j = i - 1; j >= 0; j--) {
            printf("*");
        }
        for (int k = 0; k <= m; k++) {
            printf(" ");
        }
        for (int k = 0; k <= m; k++) {
            printf(" ");
        }
        for (j = i - 1; j >= 0; j--) {
            printf("*");
        }
        printf("\n");
        m++;
    }
}