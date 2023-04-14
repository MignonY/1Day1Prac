#include <stdio.h>
#include <queue>
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))
using namespace std;
int N,x;

struct cmp{
	bool operator()(int a, int b){
		if (ABS(a) == ABS(b))
			return a>b;
		else
			return ABS(a) > ABS(b);
	}
};


int main(){
	priority_queue<int, vector<int>, cmp>pq;
	scanf("%d", &N);
	for (int i=0; i<N; ++i){
		scanf("%d", &x);
		if(x ==0){
			if (pq.empty())
				printf("0\n");
			else{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else{
			pq.push(x);			
		}			
	}
	return 0;
}


