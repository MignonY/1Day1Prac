#include <stdio.h>

int i;
char str[101];

int main(){
    scanf("%[^\n]s", str);
    for(i=0; str[i]!='\0'; i++) {
        if(str[i]<='z' && str[i]>='a') printf("%c", ((str[i]-'a'+13)%26)+'a');
        else if(str[i]<='Z' && str[i]>='A') printf("%c", ((str[i]-'A'+13)%26)+'A');
        else printf("%c", str[i]);
    }
    return 0;

}