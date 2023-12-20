#include <iostream>
#include <algorithm>
using namespace std;

int L, R, A, total; 

int main() {
	cin >> L >> R >> A;
	total = L + R + A;

	if (L < R) {
		int diff = min(R - L, A);
		L += diff;
        A -= diff;
	}
	else {
		int diff = min(L - R, A);
		R += diff;
        A -= diff;
	}

	if (R == L){
        cout << total - (A & 1);
    }
	else{
        cout << total - abs(R - L);
    }
    return 0;
}