#include <iostream>

using namespace std;

string N;

int main()
{
    cin >> N;
    cout << (N.substr(0, 3) == "555" ? "YES" : "NO");
}