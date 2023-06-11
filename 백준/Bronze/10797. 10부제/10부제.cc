#include <stdio.h>

int main(){
    int n, t, temp, count = 0;
    scanf("%d", &n);
    for(t = 0; t < 5; t++){
        scanf("%d", &temp);
        if(temp == n){
            count += 1;
        }
    }
    printf("%d", count);
    return 0;
}