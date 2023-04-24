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
				answer =  endi;
				break;
		}
			
		
		temp = 0;
		Flag = true;
	    for(int i=0; i<tsize ; ++i){
    		temp +=(midi / times[i]);
    		if (temp >= N){
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
	}

    
//    end2 = answer;
//    start2 = 0;
//    minv = answer;
//	answer = endi;
	printf("%lld\n", answer);
    
    return answer;
}