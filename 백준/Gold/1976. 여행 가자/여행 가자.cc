#include <stdio.h>


int N,M,temp,parent[205];


int findP(int a){
	if(parent[a] == a)
		return a;
	
	return parent[a] = findP(parent[a]);
}

void merge(int a, int b){
	a = findP(a);
	b = findP(b);
	
	if(a ==b)
		return;
	if(a > b)
		parent[a] = b;
	else
		parent[b] = a;
}



int main(){
	
	scanf("%d", &N);
	scanf("%d", &M);
	
	for(int i=0; i<N+1; ++i)
		parent[i] = i;
	
	for(int i=1; i<N+1; ++i){
		for(int j=1; j<N+1; ++j){
			scanf("%d", &temp);
			if (temp){
				merge(i,j);
			}
		}
	}

	int k;
	scanf("%d",&k);
	k = findP(k);
	
//	for(int i=0; i<N+1; ++i){
//		printf("%d", parent[i]);
//	}
//	printf("\n");
	
	bool Flag = true;
	for(int i=1; i<M; ++i){
		int x;
		scanf("%d",&x);
//		printf("%d %d\n", k, findP(x));
		if(k != findP(x)){
			Flag = false;
			break;
		}
	}
	
	if(Flag)
		printf("YES\n");
	else
		printf("NO\n");
	
	
	return 0;
}