#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
bool cmp(int a, int b){
	return a>b;
}
int temp[50500];

void merge_sort(int start, int end, vector<int> &arr){
	
	if (end - start<=1)
		return;

	int mid = (start + end) / 2;
	merge_sort(start, mid, arr);
	merge_sort(mid, end, arr);
	
	int p1 = start, p2 = mid, p = start;
	while (p < end) {
		if(p2 == end || (p1 < mid && arr[p1] >= arr[p2]))
			temp[p++] = arr[p1++];
		else
			temp[p++] = arr[p2++];
	}
	for (int i=start; i<end; ++i)
		arr[i] = temp[i];	
		
}


int solution(vector<int> people, int limit) {
    int answer = 0;
    
    int vsize = people.size();
    int remain = vsize;
    
//    sort(people.begin(), people.end(),cmp);
	merge_sort(0, vsize, people);
    int a=0;
    for(int i=0; i<vsize; ++i){
    	for(int j=vsize-1-a; j>i; --j){
    		if(people[j] && people[i] + people[j]<=limit){
    			people[i] = people[j] = 0;
    			answer++;
                a++;
    			remain -= 2;
    			break;
			}
            else if(people[i] + people[j]>limit)
				break;
		}
	}
    
    answer += remain;

    return answer;
}