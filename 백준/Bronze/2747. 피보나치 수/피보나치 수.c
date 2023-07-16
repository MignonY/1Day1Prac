#include <stdio.h>

int fibo[46] = {0, 1};
int n = 0;

int main(){
    for(int i = 2; i < sizeof(fibo) / sizeof(int); i++){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    scanf("%d", &n);

    printf("%d\n", fibo[n]);

    return 0;
}