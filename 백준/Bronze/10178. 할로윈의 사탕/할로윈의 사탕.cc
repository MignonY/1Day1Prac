#include <stdio.h>

int n;
int c, v;

int main() {

    scanf("%d", &n);
 
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &v);
 
        printf("You get %d piece(s) and your dad gets %d piece(s).\n", c / v, c % v);
    }
}