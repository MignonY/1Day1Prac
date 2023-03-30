#include <string>
#include <vector>

using namespace std;

int arr[10000], temp[10000]; 
 
void merge_sort(int start, int end){
	if(end-start <= 1)
		return;
	
	int mid = (start + end) / 2;
	merge_sort(start, mid);
	merge_sort(mid, end);
	
	int p1 = start, p2 = mid, p = start;
	while (p<end) {
		if (p2 == end || p1 < mid && arr[p1] <= arr[p2])
			temp[p++] = arr[p1++];
		else
			temp[p++] = arr[p2++];
	}	
	
	for(int i = start; i<end; ++i)
		arr[i] = temp[i];	
}


vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
    for(int i=0; i<array.size(); ++i)
    	printf("%d",array[i]);
	printf("\n");
	
	for(int i=0; i<commands.size(); ++i){
		int s = commands[i][0];
		int e = commands[i][1];
		int Asize = 0;
		int z = 0;
		if (s == e){
			answer.push_back(array[s-1]);
			continue;
			}
		else{
			for(int j=s-1; j<e; ++j)			
				arr[Asize++] = array[j];
			merge_sort(0,Asize);
			answer.push_back(arr[commands[i][2]-1]);
//			for(int j=s-1; j<e; ++j)			
//				array[j] = arr[z++];
			} 
		}
//		
//		for(int i=0; i<answer.size(); ++i)
//			printf("%d", answer[i]);
//		printf("\n");
	
	
    return answer;
	}	
