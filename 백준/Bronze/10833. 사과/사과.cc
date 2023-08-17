#include <stdio.h>
 
int main() {
 
    int n;
    scanf("%d", &n);
    int a, b,sum=0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
 
        if (a < b)
            sum += b % a;
        else if (a > b)
            sum += b;
 
    }
    printf("%d", sum);
 
}