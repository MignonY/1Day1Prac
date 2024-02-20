#include <stdio.h>
#include <math.h>
#define maxN 1000000
using namespace std;

int N, M, K, a, b, sqrtN;
long long arr[1000005], Sarr[1005], c;

int main(){
	scanf("%d %d %d", &N, &M, &K);
	sqrtN = sqrt(N);
	for(int i=0; i<N; ++i){
		scanf("%lld", &arr[i]);
		Sarr[i/sqrtN] += arr[i]; 
	}
	
	for(int i=0; i<M+K; ++i){
		scanf("%d %d %lld", &a, &b, &c);
		if(a == 1){
			long long diff = c - arr[b-1];
			Sarr[(b-1)/sqrtN] += diff;	
			arr[b-1] = c;	
		}
		else{
			int start = b-1; 
			int end = c-1;
			long long ans = 0;
			
			while(start < end && start%sqrtN){
				ans += arr[start++];
			}
			while(start < end && end%sqrtN){
				ans += arr[end--];
			}
			ans += arr[end];
			
			int cnt = (end-start) / sqrtN;
			int Sidx = start/sqrtN;
			for(int j=0; j<cnt; ++j){
				ans += Sarr[Sidx+j];
			}
			
			printf("%lld\n",ans);
		}
	}
	
	return 0;
}