#include <string>
#include <vector>
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))

using namespace std;
int temp[1000], cnt; 



void merge_sort(int start, int end, vector<int> &arr){
	if(end - start <= 1)
		return;
	int mid = (start + end)/2;	
	merge_sort(start, mid, arr);
	merge_sort(mid, end, arr);
	
	int p1 = start, p2 = mid, p = start;
	while(p<end){
		if (p2==end || (p1<mid && arr[p1]<= arr[p2]))
			temp[p++] = arr[p1++];
		else
			temp[p++] = arr[p2++];
	}
	
	for (int i= start; i<end; ++i)
		arr[i] = temp[i];	
}


int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int lsize = lost.size(); 
    int rsize = reserve.size();
    merge_sort(0,lsize,lost);
    merge_sort(0,rsize,reserve);
    
    for(int i=0; i<lost.size(); ++i){
    	for(int j=0; j<reserve.size(); ++j){
    		if (lost[i] == reserve[j]){
    			lost[i] = -1;
    			reserve[j] = -1;
			}
		}	
	}
		
    for(int i=0; i<lost.size(); ++i){
    	for(int j=0; j<reserve.size(); ++j){
    		if (ABS(lost[i] - reserve[j]) == 1){
    			lost[i] = -1;
    			reserve[j] = -1;
			}
		}
	}

	
	for(int i=0; i<lost.size(); ++i){
		if(lost[i]!= -1)
			cnt++;
	}
	
    answer = n - cnt;
    // printf("%d\n", answer);
    
    return answer;
}
