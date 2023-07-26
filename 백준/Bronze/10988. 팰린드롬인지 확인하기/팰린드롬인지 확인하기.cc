#include <bits/stdc++.h>
using namespace std;

int main() {
	string a,b;
	cin>>a;
	b=a;
	reverse(a.begin(),a.end());//거꾸로
	if(a==b){ //거꾸로 읽은 단어와 원본 단어와 같을때.
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}