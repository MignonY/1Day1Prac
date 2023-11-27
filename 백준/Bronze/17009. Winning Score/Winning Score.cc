#include <iostream>
using namespace std;
int main() {
    int n;
    int a =0 , b = 0;
    for (int i = 3; i > 0; i--){
        cin >> n;
        a += n * i;
    }
    for (int i = 3; i > 0; i--){
        cin >> n;
        b += n * i;
    }
    if (a > b)
        cout << 'A' << '\n';
    else if (a < b)
        cout << 'B' << '\n';
    else
        cout << 'T' << '\n';
}