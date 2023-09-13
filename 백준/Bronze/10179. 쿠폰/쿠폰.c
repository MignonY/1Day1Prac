#include <stdio.h>
int n, i;
double price;

int main(){
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%lf", &price);
        printf("$%.2lf\n", price*0.8);
    }
    return 0;
}