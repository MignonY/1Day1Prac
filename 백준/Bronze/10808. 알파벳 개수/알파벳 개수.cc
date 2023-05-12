#include <stdio.h>
#include <string.h>
char s[100];
char alpha[26];

int main(){
	scanf("%s",s);
	for(int i=0; i<strlen(s); ++i){
		for(int j=0; j<26; ++j){
			if(s[i] - 'a'== j)
				alpha[j]++;
		}
	}
	
	for(int i=0; i<26; ++i)
		printf("%d ", alpha[i]);		


	return 0;
}