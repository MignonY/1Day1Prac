#include <stdio.h>

int N,X, rootN,MIDidx;
int inord[100005], postord[100005]; 

int Pidx; 

void SORT_ORDER(int inS, int inE, int postS, int postE, int MIDidx){

	//종료조건 
	if(inE - inS < 0 || postE-postS <0){
		return;
	}

	//진행  
	rootN= postord[postE];
	printf("%d ", rootN);
	for(int i=inS; i<=inE; ++i){
		if(inord[i] ==  rootN){
			MIDidx = i;
			break;
		}
	}
	

	//분할  
	SORT_ORDER(inS,MIDidx-1, postS, postS+(MIDidx-1 -inS), MIDidx); // left
	SORT_ORDER(MIDidx+1,inE, postE-1-(inE -(MIDidx+1)), postE-1, MIDidx); // right	
}


int main(){
	scanf("%d", &N);
	for(int i=0; i<2; ++i){
		for(int j=0; j<N; ++j){
			scanf("%d", &X);
			if (i==0)
				inord[j] = X;
			
			else
				postord[j] = X;
		}
	}
	
	// printcheck //
//	printf("in: ");
//	for(int i=0; i<N; ++i)
//		printf("%d ", inord[i]);
//	printf("\n");
//	
//	printf("post: ");
//	for(int i=0; i<N; ++i)
//		printf("%d ", postord[i]);
//	printf("\n");
	//------------//
	
	SORT_ORDER(0,N-1,0,N-1,-1);
	
	return 0;
}

