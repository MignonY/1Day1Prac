#include <stdio.h>
#define new_node() (&pool[Pidx++])
#define nullptr (0)
int N,X, rootN, BF_MIDidx ,MIDidx, BIGROOT;
int inord[100005], postord[100005]; 

typedef struct NODE{
	struct NODE *left;
	struct NODE *right;
	int value;
}NODE;

NODE pool[100005];
NODE* access[100005];
NODE *ROOT, *LEFT, *RIGHT;
int Pidx; 

void SORT_ORDER(int inS, int inE, int postS, int postE, int MIDidx){

	//종료조건 
	if(inE - inS < 0 || postE-postS <0){
		return;
	}

	//진행  
	BF_MIDidx = MIDidx;
	rootN= postord[postE];
	
	for(int i=inS; i<=inE; ++i){
		if(inord[i] ==  rootN){
			MIDidx = i;
			ROOT = new_node();
			access[MIDidx] = ROOT;
			ROOT->value = rootN;
			ROOT->left = nullptr;
			ROOT->right= nullptr;
			break;
		}
	}
	
	//연결   
	if (BF_MIDidx>=0){
		if (BF_MIDidx < MIDidx){
			access[BF_MIDidx]->right = access[MIDidx];
		}
		if (BF_MIDidx > MIDidx){
			access[BF_MIDidx]->left = access[MIDidx];
		}
	}

	//분할  
	SORT_ORDER(inS,MIDidx-1, postS, postS+(MIDidx-1 -inS), MIDidx); // left
	SORT_ORDER(MIDidx+1,inE, postE-1-(inE -(MIDidx+1)), postE-1, MIDidx); // right	
}

void pre_order(NODE* ROOT){
	if (ROOT->left == nullptr && ROOT->right == nullptr){
		printf("%d ", ROOT->value);
		return;
	}
	
	printf("%d ", ROOT->value);
	if (ROOT->left != nullptr)
		pre_order(ROOT->left);
	if(ROOT->right != nullptr)
		pre_order(ROOT->right);	
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
	
	
	BIGROOT = postord[N-1];
	SORT_ORDER(0,N-1,0,N-1,-1);
	
	pre_order(&pool[0]);
	
	return 0;
}

