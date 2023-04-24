#include <string>
#include <vector>

using namespace std;
bool dp[105][105];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int vsize = results.size();
    for(int i=0; i<vsize; ++i){
    	dp[results[i][0]][results[i][1]] = 1;
	}
//	for(int i=1; i<n+1; ++i){
//		for(int j=1; j<n+1; ++j){
//			if (i==j)
//				dp[i][j] = 1;
//		}
//	}

//	for(int i=1; i<n+1; ++i){
//		for(int j=1; j<n+1; ++j){
//			printf("%d ",dp[i][j]);
//		}
//		printf("\n");
//	}

	for(int k=1; k<n+1; ++k){
		for(int i=1; i<n+1; ++i){
			for(int j=1; j<n+1; ++j){
				if (dp[i][k] == 1 && dp[k][j] == 1)
					dp[i][j] = 1;
			}
		}
	}

//	printf("---\n");
//	
//	for(int i=1; i<n+1; ++i){
//		for(int j=1; j<n+1; ++j){
//			printf("%d ",dp[i][j]);
//		}
//		printf("\n");
//	}
	int tmpcnt = 0;
	for(int i=1; i<n+1; ++i){
		for(int j=1; j<n+1; ++j){
			tmpcnt += dp[i][j];
			tmpcnt += dp[j][i];
		}
		if (tmpcnt == n-1)
			answer++;
		tmpcnt = 0;
		
	}
	
	// printf("ans:%d",answer);
    return answer;
}
