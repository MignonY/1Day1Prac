#include <iostream>
#include <string>
using namespace std;

int T,idx;
string w;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> idx >> w;
        for (int i = 0; i < w.size(); i++)
        {
            if (i != idx - 1)
                cout << w[i];
        }
        cout << '\n';
    }
    return 0;
}
