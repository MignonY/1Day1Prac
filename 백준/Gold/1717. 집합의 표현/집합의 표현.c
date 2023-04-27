#include <stdio.h>

int N, M, a, b, c;
int parent[1000005];


int findP(int a){
	if (parent[a] == a)
		return a;
	
	return parent[a] = findP(parent[a]);
}

void merge(int a, int b){
	a = findP(a);
	b = findP(b);
	
	if (a == b)
		return;
	if (a > b)
		parent[a] = b;
	else
		parent[b] = a;
	
}



int main(){
	
	for(int i=0; i<1000005; ++i)
		parent[i] = i;
	
	scanf("%d %d", &N,&M);
	
	for(int i=0; i<M; ++i){
		scanf("%d %d %d", &c, &a, &b);
		if (c == 0){
			merge(a,b);
		}
		else if (c == 1){
			if (findP(a) == findP(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	
	
	return 0;
}