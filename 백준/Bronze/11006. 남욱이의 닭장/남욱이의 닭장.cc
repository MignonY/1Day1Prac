#include <stdio.h>
 
int N;
int A, B, C, D;

int main() {
    scanf("%d", &N);
 
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &A, &B);
        C = B - (A - B);
        D = A - B;
        
        printf("%d %d\n", C, D);
    }
    
    return 0;
}