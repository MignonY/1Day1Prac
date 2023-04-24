#include <stdio.h>
#define INF (1e9)

int n, m, s,e,d, dis[105][105];

int main(){
	scanf("%d", &n);
	scanf("%d", &m);
	
	//INF
	for (int i=0; i<n+1; ++i){
		for(int j=0; j<n+1; ++j){
			if(i!=j)
				dis[i][j] = INF;
		}
	}
	
	for(int i=0; i<m; ++i){
		scanf("%d %d %d", &s, &e, &d);
		if(dis[s][e] > d)
			dis[s][e] = d;		
	}
	
//	for(int i=1; i<n+1; ++i){
//		for (int j=1; j<n+1; ++j){
//			printf("%d ", dis[i][j]);
//		}
//		printf("\n");
//	}
//	printf("----\n");
	
	for(int k=1; k<n+1; ++k){
		for (int i=1; i<n+1; ++i){
			for(int j=1; j<n+1; ++j){
				if(dis[i][j] > dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	}
		
	for(int i=1; i<n+1; ++i){
		for (int j=1; j<n+1; ++j){
			if(dis[i][j] == INF){
				printf("0 ");
			}
			else{
				printf("%d ", dis[i][j]);
			}
		}
		printf("\n");
	}	
		
	return 0;
}