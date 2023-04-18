#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

char word[1005];
int wsize, tempsize;
string cha="";
unordered_map<string, int> dic;

template<typename K, typename V>
void print_dic(unordered_map<K,V> const &dic){
	for (auto const &pair: dic){
		cout << "{" << pair.first << ":" << pair.second << "}\n";
	}	
}


int main(){
	scanf("%s", word);
	while(++wsize){
		if(word[wsize] == NULL)
			break;
	}
	
	for(int i=0; i<wsize; ++i){
		for(int j=i; j<wsize; ++j){
			cha+= word[j];
			dic[cha] += 1;
		}
		cha = "";
	}
	
//	print_dic(dic);

	printf("%d", dic.size());

	
	return 0;
}