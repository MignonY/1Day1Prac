#include <stdio.h>
int main(){
    int arr[3]={1,2,3}; //기존배열
    int n,a,a1,b,b1,temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){ // n번반복
        scanf("%d %d",&a,&b);//a,b 숫자 입력
        if(a==b)   // 두값같을때
            continue;
        else{
            for(int k=0;k<3;k++){ // a숫자있는배열a1
                if(arr[k] == a)
                    a1 = k;
                else if(arr[k] == b) // b숫자있는배열b1
                    b1 = k;
                else{}
            }
            // 자리바꿈
            temp = arr[a1];
            arr[a1] = arr[b1];
               arr[b1] = temp;   
        }
    }
    printf("%d",arr[0]);
    return 0;
}