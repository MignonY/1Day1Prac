#include<string>
#include <iostream>

using namespace std;


char stack [100005];
int stp = -1;

bool solution(string s)
{
    bool answer = true;
	
	for (int i=0; i<s.size(); ++i){
		if (i==0 && s[i] ==')'){
			answer = false;
			return answer;
		}
		else{	
			if (s[i] == '('){
				stp++;
				stack[i] = '(';
			}
			else{
				stp--;
			}
			if (stp <-1){
				answer = false;
				return answer;
			}
		}
	}
	if (stp==-1)
		answer = true;
	else
		answer = false;
		
	// printf("%d", answer);	


    return answer;
}