#include <iostream>
using namespace std;

int main() {
    int Get_on[10], Get_off[10]; 
    int max=0; int people=0;
	for (int i = 0; i < 10; i++) {
		cin >> Get_on[i] >> Get_off[i];
		people = Get_off[i] - Get_on[i] + people;
		if (max < people)
			max = people;
	}

	cout << max << endl;

	return 0;
}