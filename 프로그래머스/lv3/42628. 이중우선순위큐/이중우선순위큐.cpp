#include <string>
#include <vector>
#include <queue>

using namespace std;

class _priority_queue {
public:
    int heap[1005000];
    int heapSize = 0;

    void push(int value)
    {
        heap[heapSize] = value;

        int current = heapSize;
        while (current > 0 && heap[current] < heap[(current - 1) / 2]) // min heap, max일때는 부호 바꿔주기
        {
            int temp = heap[(current - 1) / 2];
            heap[(current - 1) / 2] = heap[current];
            heap[current] = temp;
            current = (current - 1) / 2;
        }

        heapSize = heapSize + 1;
    }
    
    void maxback(){
    	int maxv = -999999999;
    	int maxidx = 0;
    	int maxtemp = 0;
    	for(int i = (heapSize-1)/2 ; i<heapSize; ++i){
//    		printf("i: %d\n", i);
    		if (maxv < heap[i]){
				maxv = heap[i];
				maxidx = i;
			}
		}
//		printf("maxidx: %d, maxv: %d\n", maxidx, maxv);
		maxtemp = heap[maxidx];
		heap[maxidx] = heap[heapSize-1];
		heap[heapSize-1] = maxtemp;
	}
	
	int back(){
		return heap[heapSize-1];
	}
	
	void pop_back(){
		heapSize = heapSize -1;
	}
	
    void pop()
    {
        heapSize = heapSize - 1;

        heap[0] = heap[heapSize];

        int current = 0;
        while (current * 2 + 1 < heapSize)
        {
            int child;
            if (current * 2 + 2 == heapSize)
                child = current * 2 + 1;
            else
                child = heap[current * 2 + 1] < heap[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2;

            if (heap[current] < heap[child])
                break;

            int temp = heap[current];
            heap[current] = heap[child];
            heap[child] = temp;

            current = child;
        }
    }
    
    int size(){
    	return heapSize;
	}
    
    int top(){
    	return heap[0];
	}
	
	void printq(){
		printf("heapq: ");
		for(int i=0; i<heapSize; ++i)
			printf("%d, ", heap[i]);
		printf("\n");
	}
	
};

_priority_queue pq;


vector<int> solution(vector<string> operations) {
    vector<int> answer;
    string OP= "";
    int num =0;
//    string stnum = "";
    for(int i=0; i<operations.size(); ++i){
    	num = 0;
    	OP = operations[i][0];
    	bool MINUS = 0;
		for(int j=2; j<operations[i].size(); ++j){
			if (j==2 && operations[i][2] == '-'){
				MINUS = 1;
				continue;
			}
//			stnum+= operations[i][j]
			num = num*10 + (operations[i][j] - '0');
		}
		if (MINUS)
			num = num * -1;
//		num = stoi()	
//    	printf("%s, %d\n",OP.c_str(), num);
    	
//    	priority_queue<int, vector<int>, greater<>
		if (OP[0] == 'I'){
			pq.push(num);
		}
		else if (OP[0] == 'D' && num == 1 && pq.heapSize != 0){
			pq.maxback();
			pq.pop_back();
		}
		else if (OP[0] == 'D' && num == -1 && pq.heapSize != 0){
			pq.pop();
		}	
//		pq.printq();
	}
	
	if (pq.heapSize == 0){
		answer.push_back(0);
		answer.push_back(0);
	}
	else{
		pq.maxback();
		answer.push_back(pq.back());
		answer.push_back(pq.top());
	}
//	pq.printq();
	// for(int i=0; i< answer.size(); ++i)
	// 	printf("%d ", answer[i]);
	// printf("\n");
	
	
    return answer;
}


// int main(){
	
// //	solution({"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"});
// 	solution({"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"});
// 	return 0;
// }