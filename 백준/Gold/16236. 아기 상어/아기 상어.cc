#include <stdio.h>
//#define PRINT printf
//#define PRINT 

int N, Fcnt, sy, sx,arr[25][25];
bool visit[25][25];
int size=2, time, eat, savefcnt;
int rear, front;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

struct INFO{
	int x, y, depth;
	int valid;
};

INFO queue[100000], temp;
int Tidx;

void init_visit(){
	for(int i=0; i<N; ++i){
		for (int j=0; j<N; ++j){
			visit[i][j] = 0;
		}
	}
	temp.valid = 0;
//	for(int i=0; i<Tidx; ++i){
//		temp[valid] =0;
//	}
//	Tidx = 0;
}

void BFS(int y, int x, int depth){
	bool exit = 0;
	rear = -1;
	front = 0;
	
	rear++;
	queue[rear].y = y, queue[rear].x = x, queue[rear].depth = depth;
	visit[y][x] = 1;
	
	while (rear + 1 != front){
		y = queue[front].y;
		x = queue[front].x;
		depth = queue[front].depth;
		front++;
		
		if(temp.valid && depth > temp.depth){
//			PRINT("exit : %d, yx: %d,%d\n", temp.depth, temp.y, temp.x);
			eat++;
			Fcnt--;
			time += temp.depth;
			arr[temp.y][temp.x] = 0;
			sy = temp.y;
			sx = temp.x;
			exit = 1;
			break;
		}
		
		for (int i=0; i<=3; ++i){
			int ny = y + dy[i];
			int nx = x + dx[i];
//			PRINT("%d %d / %d,%d \n", arr[ny][nx], size, ny, nx);  
			if(0<=ny && ny<N && 0<=nx && nx<N && visit[ny][nx] != 1 && arr[ny][nx]<= size){
//				PRINT("%d %d / %d, %d / %d,%d/ %d\n", arr[ny][nx], size, y, x, ny, nx, depth); 
				//먹을 수 있는 물고기 발견
				if(arr[ny][nx] && arr[ny][nx]< size){
					
					if (temp.valid == 0){
						//아직 물고기 후보 없음 
						temp.y = ny;
						temp.x = nx;
						temp.depth = depth+1;
						temp.valid = 1;
					}
					else{
						//등록한 물고기 후보 있음
//						PRINT("\n[%d %d] : %d, %d %d / %d, %d %d\n",y,x, temp.depth, temp.y, temp.x, depth+1, ny, nx);
						bool flag = false;
						if(temp.depth >= depth+1){
							if(temp.depth == depth+1){
								if(temp.y >= ny){
									if(temp.y == ny){
										if(temp.x > nx){
											flag = true;
										}
										else{
											flag = false;
										}
									}
									else{
										flag = true;
									}
								}
							}
							else{
								flag = true;
							}
						}
						if (flag)
							temp.y = ny, temp.x = nx, temp.depth = depth+1;	
					}
//					PRINT("final:%d %d %d\n",temp.y, temp.x, temp.depth);

				}
				
				//이동
				rear++;
				queue[rear].y = ny, queue[rear].x = nx, queue[rear].depth = depth + 1;
				visit[ny][nx] = 1;				
			}
		}
		
	}
	if(!exit && temp.valid){
//			PRINT("run : %d, yx: %d,%d\n", temp.depth, temp.y, temp.x);
			eat++;
			Fcnt--;
			time += temp.depth;
			arr[temp.y][temp.x] = 0;
			sy = temp.y;
			sx = temp.x;
		}

	
}


int main(){

	scanf("%d", &N);
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			scanf("%d", &arr[i][j]);
			if(arr[i][j] == 9){
				sy = i, sx = j;
				arr[i][j] = 0;
			}
			if(arr[i][j]){
				Fcnt++;
			}
		}
	}

	//testPR
//	for(int i=0; i<N; ++i){
//		for(int j=0; j<N; ++j){
//			PRINT("%d ", arr[i][j]);
//		}
//		PRINT("\n");
//	}
//	PRINT("i,j == %d %d\n", sy, sx);
//	PRINT("FCNT == %d\n", Fcnt);
	
	
	size = 2;
	while(Fcnt){
		
		savefcnt = Fcnt;
		BFS(sy,sx,0);
		if(eat >= size){
			size++;
			eat=0;
		}
		
//		for(int i=0; i<N; ++i){
//			for (int j=0; j<N; ++j){
//				PRINT("%d ",arr[i][j]);
//			}
//			PRINT("\n");
//		}
		
			
		if(Fcnt == savefcnt || Fcnt == 0)
			break;
		
		init_visit();
	}
	
	
//	PRINT("\n");
	printf("%d", time);
	
	return 0;
}