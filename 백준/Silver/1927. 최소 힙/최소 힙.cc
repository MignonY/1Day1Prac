#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int N,x;


int main(){
	scanf("%d", &N);
	
	priority_queue<int, vector<int>, greater<int>>pq;
	
	for(int i=0; i<N; ++i){
		scanf("%d", &x);
		if (x==0){
			if(pq.empty())
				printf("0\n");
			else{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else
			pq.push(x);;
	}		
	return 0 ;
}