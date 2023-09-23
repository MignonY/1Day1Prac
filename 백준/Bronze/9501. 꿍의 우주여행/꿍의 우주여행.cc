#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, d, ans = 0;
        cin >> n >> d;
        while (n--) 
        {
            int vi, fi, ci;//우주선 최고속도,연료량,연료소비율
            cin >> vi >> fi >> ci;
            //거리는 속력 * 날 수 있는 시간
            if (vi * fi / ci>=d)ans++;
        }
        cout << ans << '\n';
    }
}
