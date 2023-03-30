#include <string>
#include <vector>

using namespace std;
int yakls[1500], sizey, B, Y;

void yaksoo(int a){
    for(int i=1; i <=a; ++i){
        if (a % i == 0){
        	if (i * i > a){
                break;
            }
            yakls[sizey++] = a/i;            
        }
    }
}


vector<int> solution(int brown, int yellow) {
    vector<int> answer;
	B = brown; 
    Y = yellow;
    yaksoo(Y);
	for(int i=0; i<sizey; ++i){
		// printf("%d ",yakls[i]);
		if ((yakls[i] + 1)*2 + (Y/yakls[i] + 1)*2 == B){		
			answer.push_back(yakls[i]+2);
			answer.push_back(Y/yakls[i]+2);
		}
	}
	
    return answer;
}
