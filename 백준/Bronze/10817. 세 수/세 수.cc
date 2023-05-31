#include <stdio.h>

int arr[5];
int temp[5];

void merge_sort(int start, int end){
	if(end - start<=1)
		return;
	
	int mid = (start + end) / 2;
	
	merge_sort(start, mid);
	merge_sort(mid, end);
	
	int p1 = start, p2 = mid, p = start;

	while(p < end){
		if(p2 == end || (p1 < mid && arr[p1] >= arr[p2]))
			temp[p++] = arr[p1++];
		else
			temp[p++] = arr[p2++];
	}
	
	for(int i=start; i<end; ++i)
		arr[i] = temp[i];
	
}



int main(){
	scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
	merge_sort(0,3);
	
	printf("%d\n",arr[1]);
	
	return 0;
}