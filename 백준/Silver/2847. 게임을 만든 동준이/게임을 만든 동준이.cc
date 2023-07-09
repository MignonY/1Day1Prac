#include <stdio.h>
#include <algorithm>

using namespace std;

int N, res, arr[105];

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; ++i){
		scanf("%d", &arr[i]);
	}
	reverse(arr, arr+N);
	
	for (int i=1; i<N; ++i){
		if (arr[i] >= arr[i-1]){
			int a = arr[i] - arr[i-1] + 1;
			arr[i] -= a;
			res += a;
		}
	}
	printf("%d\n", res);
	
	return 0;
}