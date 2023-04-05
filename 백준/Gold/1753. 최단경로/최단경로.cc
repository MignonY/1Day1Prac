#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e9


vector<pair<int,int>> graph[20050]; // 노드-노드 연결정보 배열
int table[20050]; //최대 노드개수
int V,E,S;

void DIJKST(int start){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq; // 거리, 노드 인덱스 
	
	pq.push({0,start}); //시작노드 자기자신 거리 0 , 큐에 삽입
	table[0] = 0;
	table[start] = 0;
	
	while(!pq.empty()){
		int cost = pq.top().first; // 현재 노드까지 비용 
		int now = pq.top().second;	//현재 노드 
		pq.pop();
		
		if(table[now] < cost)
			continue;
		
		for(int i=0; i<graph[now].size(); ++i){
			int next = graph[now][i].first;
			int nxcost = graph[now][i].second;  //현재 노드까지 비용 + 다음 노드 비용 (거쳐가는값 계산) 
			
			if(table[next] > table[now] + nxcost){
				table[next] = table[now] + nxcost;
				pq.push({table[next],next});
			}
		} 
	}
}
 



int main(void){
	scanf("%d %d", &V,&E);
	scanf("%d", &S);
	
	int u,v,w;
	for(int i=0; i<E; ++i){
		scanf("%d %d %d", &u,&v,&w);
		//u 번 노드에서 v번 노드로 가는 비용이 w 
		graph[u].push_back({v,w});
	}
	
	for(int i=0; i<20050; ++i)
		table[i] = INF;
		
	DIJKST(S);
	for(int i=1; i<V+1; ++i){
		if (table[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", table[i]);
	}
	
	
}