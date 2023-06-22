#include<stdio.h>
int main(){
    int K;
    scanf("%d",&K);
    while(K--){
        int P,M,f[501]={0,},i,s=0;
        scanf("%d%d",&P,&M);
        for(i=0;i<P;i++){
            scanf("%d",&M);
            if(f[M])s++;
            else f[M]=1;
        }
        printf("%d\n",s);
    }
}