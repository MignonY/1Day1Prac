#include <stdio.h>

int a, b, c, d,arr[6], maxv = 0, maxidx=0;

int main(){
	for(int i=1; i<=5; ++i){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		arr[i] = a+b+c+d;
		if(maxv<arr[i]){
			maxv = arr[i];
			maxidx = i;
		}
	}
	printf("%d %d\n", maxidx, maxv);
	
	return 0;
}