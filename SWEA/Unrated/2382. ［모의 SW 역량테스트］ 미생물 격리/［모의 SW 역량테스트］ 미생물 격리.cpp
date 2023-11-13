#include <stdio.h>
 

int arr[105][105][1000], dy[4]={-1,1,0,0}, dx[4]={0,0,-1,1};
int N,M, K, msmidx, ans, maxK;  

typedef struct Misengmul{
	int Mnum; //1<=Mnum<10000
	int My;
	int Mx;
	int dirr;
	int iftrue;
}NODE; 

NODE msm[1005], temp[1005], msm_init[1005];

//방향 바꿔주는 함수  
int dirRev(int d){
	if (d == 0 || d == 2)
		return d+1;
	else if (d == 1 || d == 3)
		return d-1;
}


void func(){
	int maxarrsize;
	//미생물 배열 업데이트
	for(int i = 0; i<msmidx; ++i){
		
		//위치변경 
		int ny = msm[i].My + dy[msm[i].dirr];
		int nx = msm[i].Mx + dx[msm[i].dirr];
				
		// 만약 가장자리 아니면 위치 방향대로 한칸 ㄱㄱ 
		if (0<=ny && ny<N && 0<=nx && nx<N){
			msm[i].My = ny;
			msm[i].Mx = nx;
		}
		
		// 만약 현재 가장자리면 (가장자리가 되었으면) 미생물수,  방향 갱신   
		if (msm[i].My<=0 || msm[i].My>=N-1 || msm[i].Mx<=0 || msm[i].Mx>=N-1){
			msm[i].Mnum /= 2;
			msm[i].dirr = dirRev(msm[i].dirr);
		}
	}
//		for(int i=0;i<msmidx; ++i){
//			printf("num:%d y,x:(%d,%d) dir:%d iftrue:%d \n",msm[i].Mnum, msm[i].My, msm[i].Mx, msm[i].dirr, msm[i].iftrue);
//			
//		}
//		printf("//////////// \n");
		
		//위치 기록하고  같은거 있는지 체크 
		for (int i=0; i<msmidx; ++i){
			int arrsize = arr[msm[i].My][msm[i].Mx][0];
			arr[msm[i].My][msm[i].Mx][arrsize+1]= i; // 리스트 내 미생물 번호 등록 
			arr[msm[i].My][msm[i].Mx][0] += 1;
		} 
		
		// 같은거 처리
		
		for (int i=0; i<N; ++i){
			for(int j=0; j<N; ++j){
				int maxv = 0;
				int maxnum = 0;
				int hap = 0;
				if (maxK < arr[i][j][0])
					maxK = arr[i][j][0];
				if (arr[i][j][0] >= 2){
					for(int k=1; k<=arr[i][j][0]; ++k){
						int Midx = arr[i][j][k] ;
						hap += msm[Midx].Mnum;
						if (maxv < msm[Midx].Mnum){
							maxv = msm[Midx].Mnum;
							maxnum = Midx;
						}
					for(int k=1; k<=arr[i][j][0]; ++k){
						if (arr[i][j][k] == maxnum){
							msm[maxnum].Mnum = hap;	
							msm[maxnum].iftrue = 1;	
						}
						else
							msm[arr[i][j][k]].iftrue = 0;
						}
					}
				}
			}
		}
//		
//		for(int i=0;i<msmidx; ++i){
//			printf("num:%d y,x:(%d,%d) dir:%d iftrue:%d \n",msm[i].Mnum, msm[i].My, msm[i].Mx, msm[i].dirr, msm[i].iftrue);
//			
//		}
//		printf("////////// \n");
		
		
		int tmpsize = 0;
		//미생물 배열 갱신
		//일단 temp에 담고 
		for (int i=0; i<msmidx; ++i){
			if (msm[i].iftrue == 1){
				temp[tmpsize++] = msm[i];
			}
		} 
		

		for(int i=0; i<1005; ++i)
			msm[i] = temp[i];
		
		msmidx = tmpsize;
}




int main(void)
{
	int test_case;
	int T;
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		//step1. 입력받아서 미생물 초기상태 저장  
		scanf("%d %d %d", &N, &M, &K);  // 배열크기, 실행횟수, 미생물군집개수 
		for (int i=0; i<K; ++i){
			NODE m; 
			scanf("%d %d %d %d", &m.My, &m.Mx, &m.Mnum, &m.dirr);
			m.dirr--;
			m.iftrue = 1;
			msm[msmidx++]= m;
		}
		
		for(int i=0;i<M; ++i){
			func();
			for(int j=0; j<msmidx; ++j){
				for(int k=0; k<maxK; ++k){
					arr[msm[j].My][msm[j].Mx][k] = 0;
				}
			}
		}
		
		for(int i=0;i<msmidx; ++i){
//			printf("num:%d y,x:(%d,%d) dir:%d iftrue:%d \n",msm[i].Mnum, msm[i].My, msm[i].Mx, msm[i].dirr, msm[i].iftrue);
			
			ans += msm[i].Mnum;
		}
		
		printf("#%d %d\n",test_case,ans);
		
		//초기화
		 msmidx = 0;
		 ans = 0;
		 maxK = 0;
		 for(int i=0; i<1005; ++i)
		 	msm[i] = msm_init[i];
	}
	return 0;
}