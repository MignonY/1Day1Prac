#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int N, x, temp;

struct pqcmp{
	bool operator()(int a, int b){
		return a>b;
	}
};

priority_queue<int,vector<int>,pqcmp> pq;

int main(){
	scanf("%d", &N);
	for (int i=0; i<N; ++i){
		scanf("%d", &x);
		if (x>0){
			pq.push(x);
		}
		else{
			if(pq.empty()){
				printf("0\n");
			}
			else{
				temp = pq.top();
				printf("%d\n", temp);
				pq.pop();

			}
		}
	}
	
	return 0;
}