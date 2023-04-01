#include <stdio.h>

char word[105];
int size;

int main(){

	scanf("%s", word);

	for (int i=0; i<105; ++i){
		if (word[i]==NULL)
			break;
		size++;	

	}
	printf("%d", size);
		
	return 0;
}
