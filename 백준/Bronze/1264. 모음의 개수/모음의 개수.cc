#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
char aeiou[5] = { 'a','e','i','o','u' };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        string s; getline(cin, s);
        if (s == "#") break;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int k = 0; k < 5; k++) {
                if (s[i] == aeiou[k]) cnt++;
            }
        }
        cout << cnt << "\n";
    }

}