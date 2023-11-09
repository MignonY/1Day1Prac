#include <stdio.h>

int n1, n2, k1, k2;

int main() {
    scanf("%d %d %d %d", &n1, &k1, &n2, &k2);
    printf("%d", n1 * k1 + n2 * k2);
    return 0;
}