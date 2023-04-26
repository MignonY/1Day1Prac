#include <stdio.h>
#include <vector>
using namespace std;

int Vnum,X,nidx,V,E,dis, maxD,maxV; 
vector <pair<int,int>>graph[100003];
int visit[100003];


void DFS(int start, int D){
	if(maxD < D){
		maxD = D;
		maxV = start;		
	}
		
	for(int i=0; i<graph[start].size(); ++i){
		int next = graph[start][i].first;
		int nD = graph[start][i].second;
		if(visit[next] == 0){
			visit[next] = 1;
			DFS(next, D+nD);	
		}
	}	
	
}


int main(){
	scanf("%d", &Vnum);
	for(int i; i<Vnum; ++i){
		nidx = 0;
		while(1){
			scanf("%d", &X);
			if(X == -1)
				break;
			if(nidx == 0)
				V = X;
			else{
				if(nidx % 2)
					E = X;
				else
					dis = X;
			}
			
//			printf("nidx:%d X:%d V:%d E:%d dis:%d\n",nidx, X, V,E,dis);
			if(nidx>0 && nidx%2==0)
				graph[V].push_back({E,dis});
			
			nidx++;
		}		
	}
	
	
	//1차탐색 
	visit[1] = 1;
	DFS(1,0);
//	printf("%d %d\n", maxD, maxV); 

	//2차탐색 
	for(int i=1; i<Vnum+3; ++i)
		visit[i] = 0;
	maxD = 0;
	
	visit[maxV] = 1;
	DFS(maxV,0);

	printf("%d\n", maxD); 
	
	return 0;
}
