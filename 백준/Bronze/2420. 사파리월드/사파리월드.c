#include <stdio.h>

long long s1, s2, diff; 

int main(){
    scanf("%lld %lld", &s1, &s2);

    diff = s1 >= s2 ? s1 - s2 : s2 - s1;

    printf("%lld\n", diff);

    return 0;
}
