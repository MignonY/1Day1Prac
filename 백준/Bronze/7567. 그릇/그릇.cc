#include <iostream>
#include <string>
using namespace std;
int main() {
    string k;
    int sum = 10;
    cin >> k;
    for (int i = 0; i < k.size(); i++){
        if ((k[i] == ')' && k[i + 1] == '(')
            || (k[i] == '(' && k[i + 1] == ')')
            && i + 1 < k.size()){
            sum += 10;
        }
        else if ((k[i] == ')' && k[i + 1] == ')')
            || (k[i] == '(' && k[i + 1] == '(')
            && i + 1 < k.size()){
            sum += 5;
        }
    }
    cout << sum << '\n';
}