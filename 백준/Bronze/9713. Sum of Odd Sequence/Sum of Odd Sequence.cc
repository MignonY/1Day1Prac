#include <iostream>
using namespace std;

int n;

int main() {    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        int sum = 0;
        for (int j = 1; j <= num; j += 2) {
            sum += j;
        }
        cout << sum << endl;
    }
}