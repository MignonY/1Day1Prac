#include <stdio.h>
//#define PRINT printf
#define PRINT 
int T, N, M, C, arr[12][12], ans, sum1, sum2;
int Ai,Bi, temp[12];

void nCr(int depth, int r, int beginIdx, int Y, int X, int sum, int ansum, bool flag){
	if(sum > C)
		return;

	if(depth == r){
		if(!flag && ansum > sum1)
			sum1 = ansum;
		if(flag && ansum > sum2)
			sum2 = ansum;
		PRINT("flag:%d || temp:{", flag);
		for(int i=0; i<r; ++i){
			PRINT("%d, ",temp[i]);
		}
		PRINT(" || sum1:%d sum2:%d || ansum:%d}\n",sum1, sum2, ansum);
		return;
	}
	for(int i=beginIdx; i<M; ++i){
		temp[depth] = arr[Y][X+i];
		nCr(depth+1, r, i+1, Y, X, sum+arr[Y][X+i], ansum+arr[Y][X+i] * arr[Y][X+i],flag);
		temp[depth] = 0;
	}
}


int main(){
	scanf("%d", &T);
	
	for(int tc=1; tc<=T; ++tc){
		scanf("%d %d %d", &N, &M, &C);
		
		for(int i=0; i<N; ++i){
			for(int j=0; j<N; ++j){
				scanf("%d", &arr[i][j]);
			}
		}
		ans = 0;
		for(int i=0; i<N; ++i){
			for(int j=0; j<N; ++j){
				sum1 = sum2 = 0; 
				int Ai = i; int Aj = j;
				int Bi = i; int Bj = Aj + M; 
//				PRINT("(%d, %d) (%d, %d)\n", Ai, Aj, Bi, Bj);
				if (Aj + M > N)
					continue;
				if (Aj + M + M >N){
					if(Ai + 1 >= N)
						continue;
					Bi = Ai + 1; Bj = 0;
				}
				bool doOnce =0;				
				for(int w=0; w<N; ++w){
					Bi += w;
					if(doOnce)
						Bj = 0;
					if(Bi >= N)
						break;
					for(int q=0; q<N; ++q){
						Bj += q; 
						if(Bj + M > N){
							Bj -= q;
							continue;
						}
						PRINT("(%d, %d) (%d, %d)\n", Ai, Aj, Bi, Bj);
						bool flag = 0;
						sum1 = sum2 = 0;
						for(int k=1; k<=M; ++k){
							nCr(0,k,0,Ai,Aj,0,0,flag);	
						}
						flag = 1;
						for(int k=1; k<=M; ++k){
							nCr(0,k,0,Bi,Bj,0,0,flag);	
						}
						if(ans < sum1 + sum2)
							ans = sum1 + sum2;	
						Bj -=q;		
					}
					Bi -=w;	
					doOnce = 1;
				}
			}
		}
		printf("#%d %d\n", tc, ans);	
		
	}
	
	
	return 0;
}