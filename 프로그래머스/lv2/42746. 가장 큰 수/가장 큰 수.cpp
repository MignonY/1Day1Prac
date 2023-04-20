#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string temp[100005];
bool cmp(string a, string b){
		return (a+b > b+a);
	}

void merge_sort(int start, int end, vector<string> &arr){	
	if (end - start<=1)
		return;

	int mid = (start + end) / 2;
	merge_sort(start, mid, arr);
	merge_sort(mid, end, arr);
	
	int p1 = start, p2 = mid, p = start;
	while (p < end) {
		if(p2 == end || (p1 < mid && cmp(arr[p1],arr[p2])))
			temp[p++] = arr[p1++];
		else
			temp[p++] = arr[p2++];
	}
	for (int i=start; i<end; ++i)
		arr[i] = temp[i];	
		
}	


string solution(vector<int> numbers) {
    string answer = "";
    int nsize = numbers.size();
    vector<string> new_num (nsize, "");
    
    for(int i=0; i<nsize; ++i){
    	new_num[i] = to_string(numbers[i]);
	}

    
//    sort(new_num.begin(), new_num.end(), cmp);
    merge_sort(0, new_num.size(), new_num);   
    
    bool Flag = true;
    for(int i=0; i<nsize; ++i){
    	if(new_num[i] != "0")
    		Flag = false;
    	answer+= new_num[i];
	}
    
    if (Flag)
    	answer = "0";
	
    return answer;
}