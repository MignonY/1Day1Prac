#include <stdio.h>

#include <string.h>



int main(){

	

	char fbi[5][11];

	int n, i, j, chk[5] = {0,}, length, cnt = 0;

	

	for(i = 0; i < 5; i++){

		

		scanf("%s", fbi[i]);

		

		length = strlen(fbi[i]);

		

		for(j = 0; j < length; j++){

			

			if(fbi[i][j] == 'F' && fbi[i][j + 1] == 'B' && fbi[i][j + 2] == 'I')

				chk[i] = i + 1;

		}

	}

	

	for(i = 0; i < 5; i++){

		

		if(chk[i] != 0){

			

			printf("%d ", chk[i]);

			cnt++;

		}

		

	}

	

	if(cnt == 0)

		printf("HE GOT AWAY!");

}