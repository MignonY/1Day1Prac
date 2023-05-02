#include <stdio.h>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, string> dic;

char w[10], wsize;

template<typename K,typename V>
void print_(unordered_map<K,V> const &dic){
	printf("dic = { ");
	for(auto &pair: dic){
		printf("%s : %s, ",pair.first.c_str(), pair.second.c_str());
	}
	printf("}\n");	
}

int main(){
	scanf("%s", w);
	while(w[wsize]!= '\0')
		wsize++;
	string word = w;
	
	
	dic["NLCS"] = "North London Collegiate School";
	dic["BHA"] = "Branksome Hall Asia";
	dic["KIS"] = "Korea International School";
	dic["SJA"] = "St. Johnsbury Academy";
	
//	print_(dic);
	printf("%s", dic[word].c_str());
	

	
	return 0;
}