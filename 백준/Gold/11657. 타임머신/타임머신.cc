//#define PRINT printf
#define PRINT
#define INF 1e10
#include <stdio.h>
#include <vector>
using namespace std;

int N, M, a,b,c, ans;
long long table[502];
bool cycle;
vector <pair<int,int>> graph[502];

void InitInf(){
	for(int i=1; i<=N; ++i){
		table[i] = INF;
	}
}

bool BellmanFord(int start){
	table[start] = 0;
	
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j){
			for(int k=0; k<graph[j].size(); ++k){
				int next = graph[j][k].first;
				int cost = graph[j][k].second;
				
				if (table[j]!= INF && table[next] > table[j] + cost){
					if (i==N){
						cycle = 1;
						return 1;
					}
					table[next] = table[j] + cost;
				} 	
			}
		}
	}
	
	if (cycle){
		return 1;
	}
	else{
		return 0;
	}
}


int main(){
	
	scanf("%d %d", &N,&M);
	for(int i=0; i<M; ++i){
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({b,c});
	}
	
	InitInf();
	
	bool ret=0;
	ret = BellmanFord(1);
	
	if(ret){
		printf("-1\n");
	}
	else{
		//print_table
		for(int i=2; i<=N; ++i){
			if(table[i] == INF){
				printf("-1\n");
			}
			else{
				printf("%d\n", table[i]);	
			}
		}	
	}
	
	
	
	return 0;
}