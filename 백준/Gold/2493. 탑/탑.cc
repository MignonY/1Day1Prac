#include <stdio.h>
#include <stack>
 
using namespace std;
stack<pair<int, int> > s;  // pair<int, int> : index, height
int num, height;

int main() {
    
    scanf("%d", &num);
 
    for (int i = 0; i < num; i++) {
        scanf("%d", &height);
 
        while (!s.empty()) {
            //수신탑 발견했을 때
            if (height < s.top().second) { // s.top().second
                printf("%d ",s.top().first);
                break;
            }
            //수신탑 찾을 때까지 계속 pop
            s.pop();
        }
        //수신 탑이 없다면
        if (s.empty()) {
            printf("0 ");
        }
        //현재 높이를 스택에 푸쉬
        s.push(make_pair(i + 1, height));
    }
     
    return 0;
}  