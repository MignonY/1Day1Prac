#include <stdio.h>
 
int A[10], B[10], aWin, bWin;
int main() {
    // freopen("input.txt", "r", stdin);
 
    for (int i = 0; i < 10; ++i) {
        scanf("%d", A + i);
    }
 
    for (int i = 0; i < 10; ++i) {
        scanf("%d", B + i);
    }
 
    for (int i = 0; i < 10; ++i) {
        if (A[i] > B[i]) aWin++;
        else if (A[i] < B[i]) bWin++;
    }
 
    if (aWin > bWin) printf("A\n");
    else if (aWin < bWin) printf("B\n");
    else printf("D\n");
}