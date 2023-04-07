
// 1+d1<=y<=N-d2 ,1<=x<=N-d1-d2 , 1<=d1<=y-1 , 1<=d2<=N-y
// 중복순열 중 위 조건 만족하는 조합
 
#include <stdio.h>

int N, arr[25][25], arr_ori[25][25]; 
int A1, A2, A3, A4, A5, ALL; 
int ls[21], temp[4], y,x,d1,d2, minv, maxv, finv = 500000; 


int AREA1(int y,int x, int d1, int d2);
int AREA2(int y,int x, int d1, int d2);
int AREA3(int y,int x, int d1, int d2);
int AREA4(int y,int x, int d1, int d2);
int AREA5(int y,int x, int d1, int d2);
void scan();
void print();
void PERM(int depth);
void prepare();
void init();


int main(){
	
	scan();
	prepare();
	PERM(0);
	print();
	init();
	
	return 0;
}

void scan(){
	scanf("%d", &N);
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			scanf("%d", &arr[i][j]);
			ALL += arr[i][j];
		}
	}
}


void prepare(){
	for(int i=0; i<N; ++i)
		ls[i] = i;
	
	for (int i=0; i<4; ++i)
		temp[i] = -1;
		
	for (int i =0; i<N; ++i){
		for (int j=0; j<N; ++j)
			arr_ori[i][j] = arr[i][j];
	}
} 


int AREA1(int y, int x, int d1, int d2){
	int ret = 0;
	int savex = x;
	for(int i=y+d1; i>=0; --i){
		for (int j=0; j<x-d1; ++j){
			if (i>=y+d1 || j>savex)
				continue;
			ret += arr[i][j];
//			arr[i][j] = 1; //test
		}
		x++;
	}	
	return ret;
}


int AREA2(int y, int x, int d1, int d2){
	int ret = 0;
	int savex = x;
	for(int i=y+d2; i>=0; --i){
		for (int j=N-1; j>x+d2; --j){
			if (j<=savex)
				continue;
			ret += arr[i][j];
//			arr[i][j] = 2; //test
		}
		x--;
	}	
	return ret;
}

int AREA3(int y, int x, int d1, int d2){
	int ret = 0;
	int savex = x-d1+d2;
	for(int i=y+d1; i<N; ++i){
		for (int j=0; j<x-d1; ++j){
			if (j>=savex)
				continue;
			ret += arr[i][j];
//			arr[i][j] = 3; //test
		}
		x++;
	}	
	return ret;
}

int AREA4(int y, int x, int d1, int d2){
	int ret = 0;
	int savex = x-d1+d2;
	int savey = y+d2;
	for(int i=y+d2; i<N; ++i){
		for (int j=N-1; j>x+d2; --j){
			if (i<=savey || j<savex)
				continue;
			ret += arr[i][j];
//			arr[i][j] = 4; //test
		}
		x--;
	}	
	return ret;
}

int AREA5(int y, int x, int d1, int d2){
	int ret = 0;
	ret = ALL - (A1+A2+A3+A4);
	return ret;
}

void PERM(int depth){
	
	
	if (depth == 4){
		minv = 5000000;
		maxv = -5;
		y = temp[0]; x = temp[1]; d1 = temp[2]; d2 = temp[3];
		
		// 배열 초기화
		for (int i =0; i<N; ++i){
			for (int j=0; j<N; ++j)
				arr[i][j] = arr_ori[i][j];
		}
	
		if ( y>=0 && y+d1+d2<N && x-d1>=0 && x+d2<N ){
			if (d1>=1 && d2>=1){
//				for(int i=0; i<4; ++i){
//					printf("%d", temp[i]);	
//				}
//				printf("\n");
		
				A1 = AREA1(y,x,d1,d2);
				if (minv > A1)
					minv = A1;
				if (maxv < A1)
					maxv = A1;
				A2 = AREA2(y,x,d1,d2);
				if (minv > A2)
					minv = A2;
				if (maxv < A2)
					maxv = A2;
				A3 = AREA3(y,x,d1,d2);
				if (minv > A3)
					minv = A3;
				if (maxv < A3)
					maxv = A3;
				A4 = AREA4(y,x,d1,d2);
				if (minv > A4)
					minv = A4;
				if (maxv < A4)
					maxv = A4;
				A5 = AREA5(y,x,d1,d2);
				if (minv > A5)
					minv = A5;
				if (maxv < A5)
					maxv = A5;
//				printf("%d %d %d %d %d\n", A1,A2,A3,A4,A5);
//				printf("max:%d min:%d mm:%d\n", maxv,minv, maxv-minv);
				if ( finv > maxv - minv)
					finv = maxv - minv; 
			}
		}
		return;
	}
	
	for(int idx=0; idx<N; ++idx){
		int savetemp = temp[depth];
		temp[depth] = ls[idx];
		PERM(depth+1);
		temp[depth] = savetemp;
	}
}

void print(){
	int ans = finv;
	printf("%d", ans);
}

void init(){
	A1 = A2 = A3 = A4 = A5 = ALL = 0; 
	y = x = d1 = d2 = minv = maxv = 0;
	finv = 500000;
	for(int i=0; i<4; ++i)
	    temp[i] = 0;
}