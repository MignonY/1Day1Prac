#include <stdio.h>

int a[5];

int main() {
    while (1)
    {
        scanf("%d %d %d", &a[0],&a[1],&a[2]);
        if (!a[0] && !a[1] && !a[2])
            break;
        if (a[1] - a[0] == a[2] - a[1] && a[1] - a[0] != 0)
            printf("AP %d\n",a[1] - a[0] + a[2]);
        else
            printf("GP %d\n",a[1] / a[0] * a[2]);
    }
}
