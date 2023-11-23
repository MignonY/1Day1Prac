#include <stdio.h>
#include <algorithm>
using namespace std;

int H,W,curH, startidx, endidx, leftmax, rightmax, ans;
int bricks[505];
int maxmemo[505][2];

int main(){	
	scanf("%d %d", &H,&W);
	for(int i=0; i<W; ++i){
		scanf("%d", &bricks[i]);
	}
	endidx = W-1;
	
	bool flagstart = 0;
	for(int i=0; i<endidx; ++i){
		if(!flagstart && bricks[i]){
			startidx = i;
			flagstart = 1;
		}
		if(bricks[i] > leftmax)
			leftmax = bricks[i];
		maxmemo[i][0] = leftmax;
//		printf("i:%d, leftmax:%d\n",i,leftmax);
	}
	
	bool flagend = 0;
	for(int i=endidx; i>=startidx; --i){
		if(!flagend && bricks[i]){
			endidx = i;
			flagend = 1;
		}
		if(bricks[i] > rightmax)
			rightmax = bricks[i];
		maxmemo[i][1] = rightmax;
//		printf("i:%d, rightmax:%d\n",i,rightmax);
	}
	
	int left = 0; int right = 0; int val = 0;
	for(int i=startidx+1; i<endidx; ++i){
		curH = bricks[i];
		left = maxmemo[i][0];
		right = maxmemo[i][1];
		val = max(0,min(left,right) - curH);
		ans += val;
//		printf("i:%d, curH:%d, left:%d, right:%d, val:%d, ans:%d\n",i,curH,left,right,val,ans);
	}
	
	printf("%d\n", ans);
	
	return 0;	 
}