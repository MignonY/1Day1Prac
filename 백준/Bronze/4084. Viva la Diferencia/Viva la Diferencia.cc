#include <iostream>
#define ABS(x) ((x)>=0 ? (x): (-(x)))
using namespace std;

int a, b, c, d;

int func(int a, int b, int c, int d, int cnt){
	if (a == b && b == c && c == d && d == a){
		return cnt;
	}
	return func(ABS(a - b), ABS(b - c), ABS(c - d), ABS(d - a), cnt + 1);
}

int main(){
	while (1){
		cin >> a >> b >> c >> d;

		if (a == 0 && b == 0 && c == 0 && d == 0){
			break;
		}

		cout << func(a, b, c, d, 0) << "\n";
	}

	return 0;
}