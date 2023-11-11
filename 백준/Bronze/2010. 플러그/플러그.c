#include  <stdio.h>

int N, S, temp;

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++){ 
        scanf("%d", &S);
        temp += S;
    }
    printf("%d", temp - (N - 1));
    return 0;
}