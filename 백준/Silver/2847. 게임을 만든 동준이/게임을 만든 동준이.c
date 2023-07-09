#include <stdio.h>
//#include <algorithm>
//using namespace std;

int N, res, arr[105];

void reverse(int a[], int N){
	int temp=0;
	for (int i = 0; i < N / 2; i++){
		temp = a[i];
		a[i] = a[N-i-1]; 
		a[N-i-1] = temp;
	}
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; ++i){
		scanf("%d", &arr[i]);
	}
	reverse(arr, N);
	
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