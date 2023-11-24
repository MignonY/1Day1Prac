#include <iostream>
#include <string>
using namespace std;

int t,n,m,cnt;

int main(){
    cin >> t;
    while (t--){
        n = m = cnt = 0;
        cin >> n >> m;
        for (int i = n; i <= m; i++){
            string str = to_string(i);
            for (int j = 0; j < str.length(); j++){
                if (str[j] == '0')
                    cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}