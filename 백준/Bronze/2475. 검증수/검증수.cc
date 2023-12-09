#include <iostream>
using namespace std;

int num, answer, square;

int main() {
	for (int i = 0; i < 5; i++) {
		cin >> num;
		square += num * num;
	}
	answer = square % 10;
	cout << answer;
}