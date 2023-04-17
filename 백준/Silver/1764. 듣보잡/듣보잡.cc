#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N, M, strsize;
string temp ="";
string str[500005];
unordered_map<string, int> dic;



int main(){
	scanf("%d %d", &N, &M);
	cin.ignore(); 
	for(int i=0; i<N; ++i){
		getline(cin,temp);
//		printf("gl1 :%s\n ", temp.c_str()); 
		dic[temp] = 0;	
	}
	for(int i=0; i<M; ++i){
		getline(cin,temp);
//		printf("gl2 :%s\n ", temp.c_str());
		if (dic.find(temp) != dic.end()){
			str[strsize++] = temp;
//			printf("str: %s\n", str[strsize].c_str());
//			strsize++;
		}
	}
	
	
	sort(str, str+strsize);
	printf("%d\n", strsize);
	for (int i=0; i<strsize; ++i){
		printf("%s\n", str[i].c_str());
	}
	
	return 0;
}