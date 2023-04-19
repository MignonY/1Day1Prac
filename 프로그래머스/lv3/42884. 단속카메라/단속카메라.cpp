#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>a, vector<int>b){
	if (a[0] == b[0])
		return a[1] < b[1];
	return a[0] < b[0];

}


int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end(), cmp);
    int vsize = routes.size();
//    for (int i=0; i<vsize; ++i){
//    	for (int j=0; j<routes[i].size(); ++j){
//    		printf("%d ", routes[i][j]);
//		}
//		printf("\n");
//	}
    for (int i=0; i<vsize-1; ++i){
    	if (routes[i][1]< routes[i+1][0])
			answer++; 
    	else{
    		routes[i+1][0] = max(routes[i][0], routes[i+1][0]);
    		routes[i+1][1] = min(routes[i][1], routes[i+1][1]);
		}
//	    printf("ans: %d\n", answer);
    		
	}
    
    
    return answer;
}