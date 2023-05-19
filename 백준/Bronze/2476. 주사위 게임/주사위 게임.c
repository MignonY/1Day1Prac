#include <stdio.h>

int arr[1005],N,a,b,c,maxv;

int max(int a, int b){
	if(a >= b)
		return a;
	else
		return b;
}

int func(int a, int b, int c){
	int ret = 0;
	if (a==b&& b==c && a==c){
		ret = 10000 + (a*1000);
	}
	else if (a != b && b != c && a != c)
		ret = max(a, max(b,c)) * 100;
	else{
		if(a==b||a==c)
			ret = 1000 + a*100;
		else
			ret = 1000 + b*100;
	}
	
	return ret;
}


int main(){
	scanf("%d", &N);
	for(int i=0; i<N; ++i){
		scanf("%d %d %d", &a,&b,&c);
		arr[i] = func(a,b,c);
		if(maxv < arr[i])
			maxv = arr[i];
	}
	
	printf("%d", maxv);
	
	return 0;
}