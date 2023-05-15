#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int t,n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(),a.end());
        int m = 2000000000;
        int tmp = 0;
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
            sum += abs(a[i + 1] - a[i]);
        while (tmp++<a[n-1])
        {
            sum += abs(a[n - 1] - tmp)+abs(a[0]-tmp);
            if (m > sum)
                m = sum;
            sum -= abs(a[n - 1] - tmp) + abs(a[0] - tmp);
        }
        cout << m << '\n';
    }
}