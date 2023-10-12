#include <iostream>
using namespace std;
long long t, a, b;
long long GCD(long long a, long long b)
{
    if (a < b) { return GCD(a,b%a); }
    if (b == 0) { return a; }
    return GCD(b, a%b);
}
int main() {
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << (a / GCD(a, b)) * (b / GCD(a,b)) * GCD(a,b) << '\n';
    }
}