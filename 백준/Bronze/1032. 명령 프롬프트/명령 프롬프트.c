#include<stdio.h>
#include<string.h>

struct file{
    char name[55];
};

struct file fc[55];

int main(){
    int n, i, j;
    char comp[51];
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%s", fc[i].name);
    }
    
    strcpy(comp, fc[0].name);

    for(i=0;i<n;i++){
        for(j = 0;j<strlen(comp);j++){
            if(comp[j] != fc[i].name[j])
                comp[j] = '?';
        }
    }
    printf("%s", comp);
}