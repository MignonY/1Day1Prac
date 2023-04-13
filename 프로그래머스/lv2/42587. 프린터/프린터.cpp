#include <string>
#include <vector>

using namespace std;
int Queue[20000][2], rear, front,current_i, current_v;
bool Flag;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int vsize = priorities.size();
	int ansls[105], ansidx = 0; 
    rear = -1;
    front = 0;
    for(int i=0; i<vsize; ++i){
		rear++;
		Queue[rear][0] = i;
		Queue[rear][1] = priorities[i];
	}
    while (rear+1 != front){
    	current_i = Queue[front][0];
    	current_v = Queue[front][1];
    	// printf("%d %d\n", current_i,current_v);  
		front++;
    	
    	Flag = true;
    	for (int i=front; i<front+vsize; ++i){
    		if (current_v < Queue[i][1]){
    			rear++;
    			Queue[rear][0] = current_i;
				Queue[rear][1] = current_v;
				Flag = false;
				break;
			}	
		}
		
		if (Flag){
			ansls[ansidx++] = current_i;
		}
	}
	
	for(int i=0; i<ansidx; ++i){
		if(ansls[i] == location){
			answer = i+1;
			break;			
		}
	}
	
	// printf("%d",answer);
	
	    
    return answer;
}
