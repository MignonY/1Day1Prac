#include <iostream>
#include <string>
using namespace std;

int n;

int main() {
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s, missedS = "";
        bool alphabet[26];
        fill(alphabet, alphabet+26, false);
        bool isPangram = true;
        
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                alphabet[(s[i] - 'A')] = true;
            }
            else if (s[i] >= 'a' && s[i] <= 'z') {
                alphabet[(s[i] - 'a')] = true;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (!alphabet[i]) {
                isPangram = false;
                missedS += char(i + 97);
            }
        }
        if (isPangram) {
            cout << "pangram\n";
        }
        else {
            cout << "missing " << missedS << '\n';
        }
    }
    return 0;
}