#include <stdio.h>

double a,b;

int main(){
    
    scanf("%lf %lf", &a, &b);
    printf("%d", ((a*(100-b)/100 >= 100) ? 0 : 1));
    
    return 0;
}