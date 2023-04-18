#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> graph(20005);
int queue[100000][2], cnt=0, maxdepth = -1;
bool visit[20005];

unordered_map<int,int>dic; 

//void init(int Nnum){
//	for(int i=0; i<Nnum+1; ++i){
//		graph[i].clear();
//		queue[i][1] = 0;
//		queue[i][0] = 0;
//		visit[i] = 0;
//	}
//	cnt = 0;
//	maxdepth = 0;
//}

void BFS(int start, int depth){
	int rear = -1;
	int front = 0;
	
	rear += 1;
	queue[rear][0] = depth;
	queue[rear][1] = start;
	visit[start] = 1;
	
	int current = 0;
	
	while(rear+1 != front){
		depth = queue[front][0];
		current = queue[front][1];

		front++;
		
		bool Flag = true;
		for(int i=0; i<graph[current].size(); ++i){
			if(visit[graph[current][i]]==0){
				rear++;
				queue[rear][0] = depth+1;
				queue[rear][1] = graph[current][i];
				visit[graph[current][i]]=1;
				Flag = false;
			}
		}
		
		if (Flag && maxdepth <= depth){
			maxdepth = depth;
			dic[maxdepth]++;
			}
		
		// printf("depth:%d maxdepth:%d\n", depth, maxdepth);
		// printf("current: %d, flag: %d\n", current, Flag);	
		// printf("cnt: %d\n", cnt);
	}
	
}



int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int s = 0;
    int e = 0;
    for(int i=0; i<edge.size(); ++i){
    	s = edge[i][0];
    	e = edge[i][1];
    	graph[s].push_back(e);
    	graph[e].push_back(s);
	}
//    for(int i=0; i<7; ++i){
//    	for(int j=0; j<graph[i].size(); ++j){
//    		printf("s:%d e:%d\n", i, graph[i][j]);
//		}
//	}
	
	BFS(1,0);
	answer = dic[maxdepth];
    // printf("answer : %d", answer);
//    init(n);
    return answer;
}