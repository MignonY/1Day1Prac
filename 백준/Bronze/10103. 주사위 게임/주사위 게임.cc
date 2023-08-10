#include <iostream>
using namespace std;
int main() {
    int n,as=100,bs=100;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            bs -= a;
        else if (a < b)
            as -= b;
 
    }
    cout << as << '\n'<< bs <<'\n';
}
