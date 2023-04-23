#include <string>
#include <vector>
using namespace std;

long long starti, midi, endi, start2, mid2, end2, answer, minv;
unsigned long long temp;
int N;
bool Flag;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    N = n;
    int tsize = times.size();
    starti = 0;
    endi = 1e18;
    
    while(1){
//		printf("%lld\n" ,temp);
		midi = (starti+ endi)/2;
//		printf("start:%lld , mid:%lld, end:%lld\n", starti, midi, endi);
		if (endi - starti <= 1){
			if (answer == 0){
				starti = 0;
				endi = 1e18;
				N++;
			}
			else
				break;
		}
			
		
		temp = 0;
		Flag = true;
	    for(int i=0; i<tsize ; ++i){
    		temp +=(midi / times[i]);
    		if (temp > N){
    			Flag = false;
    			break;
			}
		}
		
//		printf("start:%lld , mid:%lld, end:%lld, flag:%d, N:%d, temp:%lld\n", starti, midi, endi, Flag, N, temp);
		
		if(!Flag){
//			printf("case 1\n");
			endi = midi;
		}
		else if (Flag && temp < N){
//			printf("case 2\n");
			starti = midi;
		}
		else if (Flag && temp == N){
//			printf("case 3\n");
			answer = midi;
			break;
		}
	}
//     printf("%lld\n", answer);
    
    
    end2 = answer;
    start2 = 0;
    minv = answer;
//    temp = 0;
    while(1){
		
    	long long mid2 = (start2+ end2)/2;
    	
    	if (end2-start2<=1)
    		break;
    	
    	temp = 0;
//    	printf("start2:%lld , mid2:%lld, end2:%lld, flag:%d, N:%d, temp:%lld\n", start2, mid2, end2, Flag, N, temp);
		Flag = true;
	    for(int i=0; i<tsize ; ++i){
    		temp +=(mid2 / times[i]);
    		if (temp > N){
    			Flag = false;
    			break;
			}
		}
//		printf("Astart2:%lld , mid2:%lld, end2:%lld, flag:%d, N:%d, temp:%lld\n", start2, mid2, end2, Flag, N, temp);
		
		if(!Flag){
//			printf("case 1\n");
			end2 = mid2;
		}
		else if (Flag && temp < N){
//			printf("case 2\n");
			start2 = mid2;
		}
		else if (Flag && temp == N){
			if (mid2 < minv)
				minv = mid2;
			end2 = mid2;
//			printf("case 3, mid2=%lld, minv=%lld\n", mid2, minv);
		}
	}
	answer = minv;
//	 printf("%lld\n", answer);
    
    return answer;
}
