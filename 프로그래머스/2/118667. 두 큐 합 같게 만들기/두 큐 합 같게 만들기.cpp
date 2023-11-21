// #define PRINT printf
#define PRINT
#include <stdio.h>
#include <vector>

using namespace std;
int qsize, qmemsize,q1head,q1tail,q2head,q2tail; 
unsigned long long q1sum, q2sum, qsum, val;
unsigned long long qmem[600005];

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    qsize = queue1.size();
    qmemsize = qsize*2;
    
    for(int i=0; i<qmemsize; ++i){
        if(i<qsize){
            q1sum += queue1[i];
            qmem[i] = queue1[i];
        }
        else {
            q2sum += queue2[i-qsize];
            qmem[i] = queue2[i-qsize];
        }
        PRINT("qmem[%d]:%llu\n",i,qmem[i]);
    }
    
    if(q1sum == q2sum) return 0;
    
    
    val = (q1sum+q2sum) / 2;
    q1head = 0, q1tail = qsize-1, q2head = qsize, q2tail = qmemsize-1;
    PRINT("val:%llu, qmemsize:%d\n",val, qmemsize);
    while(1){
        PRINT("ans:%d, q1sum:%llu, q2sum:%llu\n",answer,q1sum,q2sum);
        if(q1sum == val){
            if(q1sum != q2sum) answer=-1;
            break;
        }
        else if(q1sum < val){
            q1sum += qmem[q2head];
            q2sum -= qmem[q2head];
            q1tail++;
            q2head++;
        }
        else if(q1sum > val){
            q1sum -= qmem[q1head];
            q2sum += qmem[q1head];
            q1head++;
            q2tail++;
        }
        q1head %= qmemsize;
        q1tail %= qmemsize;
        q2head %= qmemsize;
        q2tail %= qmemsize;
        
        answer++;
        
        if(answer > 3*qsize) return -1;
    }
    

    return answer;
}