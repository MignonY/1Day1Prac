#include <string>
#include <vector>
#define ABS(x) ((x)>=0 ? (x) : (-(x)))
using namespace std;
int graph[105][105], gisize[105];
bool visit[105];

void DFS(int start, int &cnt){
//	printf("now:%d\n", start);
	visit[start] = 1;
	
	for(int i=0; i<gisize[start]; ++i){
		if(graph[start][i] != -1 && visit[graph[start][i]] ==0){
			visit[graph[start][i]]== 1;
			cnt++;
			DFS(graph[start][i], cnt);
		}
	}
	 
}


int solution(int n, vector<vector<int>> wires) {
    int answer = 100000;
    
	int vsize = wires.size();
    
	for(int i=0; i<vsize; ++i){
		int s = wires[i][0];
		int e = wires[i][1];
		graph[s][gisize[s]++] = e;
		graph[e][gisize[e]++] = s;
	}
    
    for(int i=1; i<n; ++i){
    	for(int j=0; j<gisize[i]; ++j){
    		//visit초기화 
    		for(int k=0; k<n+1; ++k)
    			visit[k] = 0;
			//연결끊기
			int temp = graph[i][j];
			graph[i][j] = -1;
			
			int cnt1 = 1;
			DFS(i, cnt1);
//			printf("\n");
			int cnt2 = 1;
			DFS(temp, cnt2);
			graph[i][j] = temp;
//			printf("i = %d, temp:%d, cnt1:%d, cnt2:%d\n", i, temp, cnt1, cnt2);
			if(ABS(cnt1-cnt2) < answer){
				answer = ABS(cnt1-cnt2);
//			printf("----\n");
			}	
		} 	
	}
    
    printf("%d", answer);
    
    
    return answer;
}
