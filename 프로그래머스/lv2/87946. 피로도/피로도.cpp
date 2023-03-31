#include <string>
#include <vector>

using namespace std;
int temp[5100],visit[5100] = {0},ls[5100], N, piro, ans, maxv;

void nPr(int cnt, int depth, vector<vector<int>> &arr){
//	for(int i=0; i<N; ++i)
//			printf("%d ",arr[i]);
//		printf("\n");
//	printf("%d %d",cnt,temp[cnt-1]);
//	printf("\n");
	if (ans > maxv)
		maxv = ans;
	
	if(cnt==depth){
//		for(int i=0; i<depth; ++i)
//			printf("%d ",temp[i]);
//		printf("\n");
		
		return;
	}
	
	
	
	for(int i=0; i<N; ++i){
		if (visit[i] == 0 && piro>= arr[ls[i]][0]){
//			printf("%d %d",cnt,depth);
			visit[i] = 1;
			temp[cnt] = ls[i];
			piro -= arr[ls[i]][1];
			ans++;
			
			nPr(cnt+1, depth, arr);
			
			visit[i] = 0;
			temp[cnt] = 0;
			piro += arr[ls[i]][1];
			ans--;
		}
	}
		
}



int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    piro = k;
	N = dungeons.size();
    for(int i=0; i<N; i++){
    	ls[i] = i;
    }

    nPr(0,N,dungeons);
//    printf("ans %d", maxv);
    answer = maxv;
    return answer;
}

