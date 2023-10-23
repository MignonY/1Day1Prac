#include <stdio.h>
 
int n, a, b;

int main() {
    scanf("%d", &n);
 
    a = n *0.78;
    b = n - (n * 0.2 * 0.22);
 
    printf("%d %d", a, b);
    
}