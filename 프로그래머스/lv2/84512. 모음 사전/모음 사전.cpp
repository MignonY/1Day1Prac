#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

char ch[10] = "AEIOU";
char temp[10], tsave[10];
int num;
unordered_map<string,int> dic;

template<typename K, typename V>
void print_map(std::unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

void combi(int depth, int begin){
	
	if (depth == 5){
//		for(int i=0; i<5; ++i)
//			printf("%c", temp[i]);
//		printf("\n");
		return;
	}
	
	for(int idx=0; idx<5; ++idx){
		tsave[depth] = temp[depth];
		num += 1;
		temp[depth] = ch[idx];
		dic[temp] = num;
		
		combi(depth+1, idx);
		
		temp[depth] = tsave[depth];
	}

}


int solution(string word) {
    int answer = 0;
    combi(0,0);    
    answer = dic[word];
//    printf("%d",dic[word]);
    return answer;
}
