#include <string>
#include <vector>

using namespace std;

string answer = "";
int N, idx, maxv, K;
void MAKE(int depth,int begin, string &number){
	if (depth == N-K){
		// printf("%s\n", answer.c_str());
		return;
	}
		
	idx = 0;
	maxv = -1;
	for(int i=begin; i<=K+depth; ++i){
		// printf("num:%d maxv:%d\n",number[i]-'0', maxv);
		if(number[i]-'0' > maxv){
			maxv = number[i]-'0';
			idx = i;
		}
	}
	answer += maxv+'0';
	MAKE(depth+1, idx+1,number);
}



string solution(string number, int k) {
    N = number.size();
    K = k;
    MAKE(0,0,number);
    
    return answer;
}