#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    while(!progresses.empty()){
 	    while(progresses[0]<100){
 	    	int fin = 0;
    		for(int i=0; i<progresses.size(); ++i)
    			progresses[i] += speeds[i];
    			
    		while (!progresses.empty() && progresses[0] >= 100){
  			
    			fin++;
    			progresses.erase(progresses.begin());
    			speeds.erase(speeds.begin());
				

    		}

			if (fin>0)
				answer.push_back(fin);
		}
		
		// for(int i=0; i<answer.size(); ++i)
		// 	printf("%d ", answer[i]);
		// printf("\n");
	}	 
	
    return answer;
}
