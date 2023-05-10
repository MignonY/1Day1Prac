#include <stdio.h>
 
int a[5]; 
 
int main() {
 
    
    int tmp;
    for (int i = 0; i < 3; i++) {
        scanf("%d", &a[i]);
    }
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                if (a[k] > a[k + 1]){ 
                    tmp = a[k];
                    a[k] = a[k + 1];
                    a[k + 1] = tmp;
                }
            }
        }
 
        for (int i = 0; i < 3; i++) {
            printf("%d ", a[i]);
 
        }
}