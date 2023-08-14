#include <stdio.h>

int a, b, sum, max;

int main() {
    for (int i = 0; i < 4; i++) {
        scanf("%d %d", &a, &b);
        sum += -a + b;
        if (sum > max)
            max = sum;
    }
    printf("%d", max);
    return 0;
}