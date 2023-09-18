#include <stdio.h>

int T, C, Quarter, Dime, Nickel, Penny;

int main(){
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        C=0,Quarter=0,Dime=0,Nickel=0,Penny=0;
        scanf("%d",&C);
        
        Quarter = C/25;
        C -= Quarter * 25;
        Dime = C/10;
        C -= Dime * 10;
        Nickel = C/5;
        C -= Nickel * 5;
        Penny = C;
        printf("%d %d %d %d\n",Quarter,Dime,Nickel,Penny);
    }
    return 0;
}