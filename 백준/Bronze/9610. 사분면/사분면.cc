#include <iostream>
#include <algorithm>
using namespace std;

int n, x, y, q1, q2, q3, q4, axis;

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x >> y;
		if (x == 0 || y == 0) axis++;
		else if (x > 0 && y > 0) q1++;
		else if (x < 0 && y > 0) q2++;
		else if (x < 0 && y < 0) q3++;
		else if (x > 0 && y < 0) q4++;
	}

	cout << "Q1: " << q1 << "\n";
	cout << "Q2: " << q2 << "\n";
	cout << "Q3: " << q3 << "\n";
	cout << "Q4: " << q4 << "\n";
	cout << "AXIS: " << axis;

	return 0;
}