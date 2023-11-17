#include<iostream>
using namespace std;

int a, b, cnt;
int n[1000];

int main(){
    cin >> a >> b;
    for (int i = 1; cnt<1000 ;i++) {
        for (int j = 0; j < i; j++) {
            n[cnt++] = i; 
            if (cnt == 1000)
                break;
        }
    }
    int sum = 0;
    for (int i = a-1; i <= b-1; i++) { 
        sum += n[i];
    }
    cout << sum << endl;
    return 0;
}