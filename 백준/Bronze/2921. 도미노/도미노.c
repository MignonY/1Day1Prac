#include<stdio.h>

int i, j, n, sum = 3;

int main(){
    scanf("%d", &n);
    for (i = 3; i <n+2 ; i++){
        sum += i;
    }
    printf("%d", sum*(i-2));
}