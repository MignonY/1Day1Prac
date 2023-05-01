#include <stdio.h>
#include <vector>
using namespace std;

struct COPY{
	bool visit[10005];
};
COPY c;

int n,s,e,dis, maxV, maxD, ret;
bool visit[10005];

vector<pair<int,int>>VEC[10005];


void DFS(int start, int D){
	
	if(maxD< D){
		maxV = start;
		maxD = D;
	}
	
	for(int i=0; i<VEC[start].size(); ++i){
		int next = VEC[start][i].first;
		int cost = VEC[start][i].second;
		if(visit[next] == 0){
			visit[next] = 1;
			DFS(next, D+cost);
		}
	}
}


int main(){
	scanf("%d", &n);
	for(int i=0; i<n-1; ++i){
		scanf("%d %d %d", &s,&e,&dis);
		VEC[s].push_back({e,dis});
		VEC[e].push_back({s,dis});
	} 
	
	visit[1] = 1;
	DFS(1,0);
	
	//init
//	for(int i=0; i<n+1; ++i)
//		visit[i]= 0;
	*(struct COPY*)visit = c; 
	maxD = 0;
	visit[maxV]=1;
	DFS(maxV,0);
	
	printf("%d\n", maxD);
	
	return 0;
}