#include <vector>
#include <stdio.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    int arrsize = arr.size();
    for(int i=1; i<arrsize; ++i){
		if (arr[i] != answer.back()){
			answer.push_back(arr[i]);
		}
	}

//	for(int i=0; i<answer.size(); ++i)
//		printf("%d", answer[i]);
    return answer;
}