#include <stdio.h>

int arr[9], price;

int main(){
    scanf("%d", &price);
    for(int i=0; i<9; ++i){
        scanf("%d", &arr[i]);
        price -= arr[i];
    }
    printf("%d\n",price);
    return 0;
}