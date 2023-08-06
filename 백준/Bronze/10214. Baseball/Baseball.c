#include <stdio.h>

int n, y, k, i, j, ys, ks;

int main(){
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 9; j++)
        {
            scanf("%d %d", &y, &k);
            ys += y; 
            ks += k;
        }
        
        if(ys > ks)
        {
            printf("Yonsei\n");
        }
        else if(ys < ks)
        {
            printf("Korea\n");
        }
        else if(ks == ys)
        {
            printf("Draw\n");
        }
    }
}