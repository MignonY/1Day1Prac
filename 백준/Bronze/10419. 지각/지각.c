#include <stdio.h>

int q, s, t, CT, ans;
int main(){
    scanf("%d", &q);
    while (q--){
        s=0, t=0, ans=0;
        scanf("%d", &CT);
        while (1){
            if (CT < s + t){
                t--;
                break;
            }
            t++;
            s= t*t;
        }
        printf("%d\n", t);        
    }
    return 0;
}