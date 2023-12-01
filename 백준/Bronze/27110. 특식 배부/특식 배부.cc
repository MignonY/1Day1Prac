#include <iostream>
using namespace std;

int N;

int main() {
	cin >> N;
	int ans = 0;
    for(int i = 0; i < 3; i++){
        int x;
        cin >> x;
        ans += x > N ? N : x;
    }
    cout << ans;
	return 0;
}
