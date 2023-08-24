#include <stdio.h>
int n, cnt, x;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < 5; i++){
        scanf("%d", &x);
        if(x == n) 
            cnt++;
    }
    printf("%d",cnt);
    return 0;
}