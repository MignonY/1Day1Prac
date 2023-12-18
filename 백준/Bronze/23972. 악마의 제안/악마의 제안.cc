#include <iostream>
using namespace std;
long long K, N;

int main() {
	cin >> K >> N;
	if (N == 1) {
		cout << -1;
	}
	else {
		long long x = (K * N) / (N - 1);
		if ((K * N) % (N - 1) != 0) {
			x++;
		}
		cout << x;
	}
	return 0;
}