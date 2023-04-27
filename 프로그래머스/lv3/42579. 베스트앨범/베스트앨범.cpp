#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define new_node() (&Nodelist[Nidx++])

using namespace std;


unordered_map<string, int> dic_P;
unordered_map<string, int> dic_cnt;

struct NODE{
	int id;
	string GENRE;
	int self_plays;
};

bool cmp(NODE a, NODE b){
	if(dic_P[a.GENRE] == dic_P[b.GENRE]){
		if (a.self_plays == b.self_plays){
			return b.id > a.id;
		}
		return a.self_plays > b.self_plays;
	}
		
		
	
	return dic_P[a.GENRE] > dic_P[b.GENRE];
}


void print_(unordered_map<string,int> const &dic_P){
	printf("dic= {");
	for(auto const &pair:dic_P){
		printf("%s:%d, ",pair.first.c_str(), pair.second);
	}
	printf("}\n");
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
	int vsize = genres.size();
    vector<NODE> Nodelist(vsize);
    int Nidx=0;
    for(int i=0; i<vsize; ++i){
    	dic_P[genres[i]]+= plays[i];
    	dic_cnt[genres[i]]=0;
    	NODE* Music = new_node();
    	Nodelist[i].id = Nidx-1;
    	Nodelist[i].GENRE = genres[i];
    	Nodelist[i].self_plays = plays[i];
	}
    
    
//    print_(dic_P);
//    print_(dic_cnt);
    
    sort(Nodelist.begin(), Nodelist.end(), cmp);
    for(int i=0; i<vsize; ++i){
    	if(dic_cnt[Nodelist[i].GENRE]>=2)
    		continue;
    	answer.push_back(Nodelist[i].id);
    	dic_cnt[Nodelist[i].GENRE]++;
	}
//    print_(dic_cnt);
//    for(int i=0; i<vsize; ++i){
//    	printf("id:%d, G:%s, plays:%d\n", Nodelist[i].id, Nodelist[i].GENRE.c_str(), Nodelist[i].self_plays);
//	}
//    
//    for(int i=0; i<answer.size(); ++i){
//    	printf("%d", answer[i]);  	
//	}
    
    
    return answer;
}
