#include <string>
#include <vector>
#include <queue>

using namespace std;
int a, b, new_v, cnt;
bool Flag;
priority_queue<int, vector<int>, greater<int>>pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
	for(int i=0; i<scoville.size(); ++i)
		pq.push(scoville[i]);

    if (pq.top()>=K)
        return answer;
    cnt = pq.size()-1;
	while(cnt--){
        
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		new_v = a + b*2;
		pq.push(new_v);
		answer++;

        if (pq.top()>=K)
            return answer;
	}

	

    answer = -1;
	
    return answer;
}