#include <stdio.h>
#include <string>
#include <vector>
#include <queue>


using namespace std;
//typedef vector<vector<int>> vvi;
int arr[505], arrsize;
int TIME, start1, len1, start2, len2;

struct cmp {
	bool operator()(vector<int>a, vector<int>b) {
		// printf("time:%d a1:%d b1:%d", TIME, a[1],b[1]);
		return TIME +a[1] -a[0] > TIME + b[1] - a[0] ;
	}
};

void init();

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int jobslen = jobs.size();
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
	priority_queue< vector<int>, vector<vector<int>>, cmp >finpq;
	
	for (int i = 0; i < jobslen; ++i) {
		pq.push(jobs[i]);
	}

	TIME = 0;
	while (!pq.empty()) {
		// printf("%d %d, TIME: %d\n", pq.top()[0], pq.top()[1],TIME);
		auto TASK1 = pq.top();
		start1 = TASK1[0];
		len1 = TASK1[1];
		
		if (start1 >= TIME) {
			TIME = (start1 + len1);
			pq.pop();
			arr[arrsize++] = TIME-start1;
		}
		else {
			while (pq.top()[0]<=TIME){
				finpq.push(pq.top());
				pq.pop();
			}
			auto TASK2 = finpq.top();
			start2 = TASK2[0];
			len2 = TASK2[1];
			TIME += len2;
			arr[arrsize++] = TIME - start2;
			finpq.pop();

			while (!finpq.empty()) {
				pq.push(finpq.top());
				finpq.pop();
			}

		}
	}
	
	for (int i = 0; i < arrsize; ++i) {
		answer += arr[i];
		// printf("%d ", arr[i]);
	}

	answer /=  arrsize;
	// printf("answer: %d\n", answer);
	init();
	return answer;
}

void init() {
	for (int i = 0; i < arrsize; ++i)
		arr[i] = 0;
	arrsize = TIME = start1 = len1 = start2 = len2 = 0;
}
