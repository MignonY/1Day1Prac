#include <stdio.h>
#include <queue>
#define INF 1e9
using namespace std;

int V, E, a, b, c; 
vector<pair<int,int>> graph[405];
int distable[405][405];

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> distpq;


int dijkstra(int start){
	
	distable[start][start] = 0;
	distpq.push({0,start});
//	for(int i=0; i<graph[start].size(); ++i){
//		distpq.push({graph[start][i].second, graph[start][i].first});
//		distable[start][graph[start][i].first] = graph[start][i].second;
//	}
	bool Flag = false;
	
	while(!distpq.empty()){
		
		int dis = distpq.top().first;
		int now = distpq.top().second;
//		printf("start:%d, dis:%d, now:%d, flag:%d\n", start, dis, now, Flag);

		if(Flag && now == start){
//			printf("!!\n");
			return dis;
		}
		Flag = true;
		distpq.pop();
		
		if(distable[start][now] < dis ){
			continue;
		}
	
		for(int i=0; i<graph[now].size(); ++i){
			int next = graph[now][i].first;
			int nxdis = dis + graph[now][i].second;
//			printf("next:%d, nxdis:%d\n", next, nxdis);
			if(next == start || distable[start][next] > nxdis){
				distpq.push({nxdis, next});	
				distable[start][next] = nxdis;
			}
		}	
	}
	
	return INF;
}

void inittable(){
	for(int i=0; i<=V; ++i){
		for(int j=0; j<=V; ++j){
			distable[i][j] = INF;	
		}
	}
}


int main(){
	
	scanf("%d %d",&V,&E);
	for(int i=0; i<E; ++i){
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({b,c});
	}
	
	inittable();
	int ret = 0;
	int ans = INF;
	for(int i=1; i<=V; ++i){
		ret = dijkstra(i);	
//		printf("ret:%d\n",ret);
		if(ans > ret){
			ans = ret;
		}
		inittable();
        distpq = priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>();
	}

//	for(int i=0; i<=E; ++i){
//		for(int j=0; j<=E; ++j){
//			printf("%d ",distable[i][j]);
//		}
//		printf("\n");
//	}	

	if(ans == INF){
		ans = -1;
	}
	
	printf("%d\n",ans);
	
	return 0;
}