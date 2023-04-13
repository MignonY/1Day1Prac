#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	int stack[100500][2], stp = -1;
    int vsize= prices.size();
    vector<int> answer(vsize);
//	int answer[vsize];
    
    stp++;
    stack[stp][0] = 0;
	stack[stp][1] = prices[0];
    for(int i=1; i<vsize; ++i){
    	if (prices[i] >= stack[stp][1]){
    		stp++;
    		stack[stp][0] = i;
			stack[stp][1] = prices[i];
		}
		else{
			while(prices[i] < stack[stp][1]){
				answer[stack[stp][0]] = i - stack[stp][0];
				stack[stp][0] = i;
				stack[stp][1] = prices[i];
                stp--;
			}
            stp++;
			stack[stp][0] = i;
			stack[stp][1] = prices[i];
		}
	}
    for(int i=0; i<=stp; ++i){
    	answer[stack[i][0]] = (vsize-1) - stack[i][0];
	}
	
	// for(int i=0; i<vsize; ++i)
	// 	printf("%d", answer[i]);    
    
    return answer;
}



