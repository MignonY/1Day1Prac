#include <stdio.h>

int N, temp, cnt, sum; 

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &temp);
        if (temp == 1){
            cnt++;
            sum += cnt;
        }
        else if (temp == 0) cnt = 0;
    }
    printf("%d\n", sum);
    return 0;
}