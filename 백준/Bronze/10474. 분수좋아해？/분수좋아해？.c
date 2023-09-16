#include <stdio.h>

main(a,b){
    for(;scanf("%d%d",&a,&b)*a*b;)
        printf("%d %d / %d\n",a/b,a%b,b);
}