#include <stdio.h>

int main(){
	int a; char win; int Dnum = 0; int Pnum = 0;
	scanf("%d", &a);
	bool Flag = true;
	for(int i=0; i<a; i++){
		scanf(" %c", &win);
		if(win == 'D'){
			Dnum += 1;
		}
		else if(win == 'P'){
			Pnum += 1;
		}
//		printf("%d,%d,%d\n",i,Dnum,Pnum);
		if(Pnum-Dnum == 2 or Dnum-Pnum == 2){
			printf("%d:%d\n",Dnum,Pnum);
			Flag = false;
			break;
		}
	}	
	if (Flag){	
	printf("%d:%d\n", Dnum,Pnum);
	}
	return 0;
}