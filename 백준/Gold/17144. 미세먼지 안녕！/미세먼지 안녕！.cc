//#define PRINT printf
#define PRINT 
#include <stdio.h>

int Y, X, T, ans, y1,x1, y2,x2;
int arr[52][52];
int arr_ret[52][52];
const int dy[5] = {-1,0,1,0};
const int dx[5] = {0,1,0,-1}; 


int CalculateMise(int Y, int X){
	int MiseSum=0;
	for(int i=0; i<Y; ++i){
		for(int j=0; j<X; ++j){
			if (arr[i][j] != 0 && arr[i][j] != -1){
				MiseSum += arr[i][j];
			}
		}
	}
	
	PRINT("sum: %d\n", MiseSum);
	
	return MiseSum;
}

void MiseDiffuse(int Y, int X){
	//init retarr
	for(int y=0; y<Y; ++y){
		for(int x=0; x<X; ++x){
			arr_ret[y][x] = 0;
		}
	}
	for(int y=0; y<Y; ++y){
		for(int x=0; x<X; ++x){
			int DiffAmount = arr[y][x] / 5;

			for(int i=0; i<4; ++i){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (0<= ny && ny < Y && 0 <= nx && nx < X && arr[y][x] != -1 && arr[ny][nx] != -1){
					arr_ret[ny][nx] += DiffAmount;
					arr_ret[y][x] -= DiffAmount;
				}
			}
		}
	}
	
	for(int i=0; i<Y; ++i){
		for(int j=0; j<X; ++j){
			arr[i][j] += arr_ret[i][j];
		}
	}
}

void UPClean(int Y, int X, int y, int x){
	int oriY = y;
	int oriX = x;
	
	y = oriY-1, x=0;
	while(y>0){
		arr[y][x] = arr[y-1][x];
		y--;
	}
	y=0, x=0; 
	while(x<X-1){
		arr[y][x] =arr[y][x+1];
		x++;
	}
	y=0, x=X-1;
	while(y<oriY){
		arr[y][x] = arr[y+1][x];
		y++;
	} 
	y=oriY, x= X-1;
	while(x>0){
		arr[y][x] = arr[y][x-1];
		x--;
	}
	
	arr[oriY][oriX+1] = 0;
}

void DownClean(int Y, int X, int y, int x){
	int oriY = y;
	int oriX = x;
	
	y = oriY+1, x=0;
	while(y<Y-1){
		arr[y][x] = arr[y+1][x];
		y++;
	}
	y=Y-1, x=0; 
	while(x<X-1){
		arr[y][x] =arr[y][x+1];
		x++;
	}
	y=Y-1, x=X-1;
	while(y>oriY){
		arr[y][x] = arr[y-1][x];
		y--;
	} 
	y=oriY, x= X-1;
	while(x>0){
		arr[y][x] = arr[y][x-1];
		x--;
	}
	
	arr[oriY][oriX+1] = 0;
}


int main(){
	scanf("%d %d %d", &Y, &X, &T);
	for(int i=0; i<Y; ++i){
		for (int j=0; j<X; ++j){
			scanf("%d", &arr[i][j]);
			if(arr[i][j] == -1){
				y2 = i, x2 = j;
			}
		}
	}
	
	y1 = y2-1, x1 = x2;
	
	PRINT("y1x1:(%d,%d) || y2x2:(%d,%d)\n", y1,x1,y2,x2);
	
	
	for(int t=0; t<T; ++t){
		MiseDiffuse(Y,X);
		UPClean(Y,X,y1,x1);
		DownClean(Y,X,y2,x2);
		
		
		PRINT("\nPRINT_Test\n");
		for(int i=0; i<Y; ++i){
			for(int j=0; j<X; ++j){
			PRINT("%d ", arr[i][j]);
			}
			PRINT("\n");
		}
		ans = CalculateMise(Y,X);
		
	}
	
	//ans_test
	PRINT("\n");
	printf("%d\n", ans);
	
	return 0;
}