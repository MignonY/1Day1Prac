#include <iostream>
#include <string>
using namespace std;
int main(){
	while (1){
		string str;
		getline(cin, str);
		if (str == "*")
			break;

		int arr[26] = { 0, }, len;
		len = str.length();
		for (int i = 0; i < len; i++){
			if (str[i] == ' ')
				continue;
			else
				arr[(int)((char)str[i] - 'a')]++;
		}

		bool check = false;
		for (int i = 0; i < 26 && check==false; i++)
			if (arr[i] == 0)
				check = true;

		if (check)
			cout << "N\n";
		else
			cout << "Y\n";
	}
    return 0;
}