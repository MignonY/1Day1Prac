#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9
#define pii pair<int, int> 

int N,E,v1,v2,a,b,c;
vector<pair<int,int>> graph[805];
int table[805];


void DIJKSTRA(int start){

	for(int i=0; i<805; ++i)
		table[i] = INF;
	
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	
	pq.push({0,start});
	table[0] = 0;
	table[start] = 0;
	
	while(!pq.empty()){
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		if (table[now] < cost)
			continue;
	
		for(int i=0; i<graph[now].size(); ++i){
			int next = graph[now][i].first;
			int nxcost = graph[now][i].second;
			
			if(table[next] > table[now] + nxcost){
				table[next] = table[now] + nxcost;
				pq.push({table[next], next});
			}	
		}
	}
}



int main(){
	scanf("%d %d", &N,&E);
	for(int i=0; i<E; ++i){
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}
	scanf("%d %d",&v1, &v2);
	
	bool Flag = false;
	
	DIJKSTRA(v1);
	if (table[v2] >= INF)
		Flag = true;
	
	
	if (Flag)
		printf("-1\n");
	
	else{	
		int v1_N = table[N];
		int v1_v2 = table[v2];
		DIJKSTRA(1);
		int start_v1 = table[v1];
		int start_v2 = table[v2];
		DIJKSTRA(v2);
 		int v2_N = table[N];
 		int v2_v1 = table[v1];
		
		if(start_v1 +v1_v2+ v2_N>= INF && start_v2 + v1_v2+ v1_N >= INF)
			printf("-1\n");
		else if(start_v1 +v1_v2+ v2_N < start_v2 + v1_v2+ v1_N)
			printf("%d\n", start_v1 +v1_v2+ v2_N);
		else
			printf("%d\n", start_v2 + v2_v1+ v1_N);
	}
	
	
	
	
	return 0;
}


