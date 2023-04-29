#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<int,vector<int>, greater<int>> pq;

int N, num, ans,ans2,savea;

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; ++i){
		scanf("%d",&num);
		pq.push(num);
	}

	
	while(pq.size()>1){
		ans = pq.top();
		pq.pop();
		ans2 = pq.top();
		pq.pop();
		savea += ans+ans2;
		pq.push(ans+ans2);
	}
	
	printf("%d\n" ,savea);
	
	
	return 0;
}
