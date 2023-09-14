#include <iostream>
#include <vector>
using namespace std;
int n; 

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        int cnt = 1;
        int pre = 1;
        for(int j = 1; j < tmp; j++){
            cnt += (pre * 2);
            pre = pre * 2;
        }
        cout << cnt << '\n';
    }
    return 0;
}