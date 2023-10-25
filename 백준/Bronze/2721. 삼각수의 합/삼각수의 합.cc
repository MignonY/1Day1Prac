#include <iostream>
using namespace std;

int getTn(int n){
	return n * (n + 1) / 2;
}

int main(){
	int T;
	cin >> T;
	for (int t = 0; t < T; t++){
		int n;
		cin >> n;
		int result = 0;
		for (int i = 1; i <= n; i++){
			result += i * getTn(i + 1);
		}
		cout << result << "\n";
	}

	return 0;
}