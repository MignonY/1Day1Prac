#include <stdio.h>
#include <queue>

int N, x, ans;

using namespace std;


int main(){
	scanf("%d", &N);
	
	priority_queue<int>pq;
	
	for(int i=0; i<N; ++i){
		scanf("%d", &x);
		if(x== 0){
			if (pq.empty())
				printf("0\n");
			else if (!pq.empty()){
				ans = pq.top();
				pq.pop();
				printf("%d\n", ans);
			}
		}
		else{
			pq.push(x);
		}
		
		
	}
	
	return 0;
}