#include <string>
#include <vector>


using namespace std;

struct ITEM{
	unsigned long long key;
	int value;
	bool valid;
};

const int TABLE_SIZE = 100000;
class _unordered_map{
public:
	ITEM item[TABLE_SIZE];
	
	_unordered_map() {}
	
	
	int& operator[] (string str){
		unsigned long long key = 0;
		int idx = 0;	
		int str_size =str.size(); 
		while(idx++ < str_size)
			key = (key * 27) + (str[idx] - 'a' + 1);
			
		unsigned long long hash_key = key % TABLE_SIZE;
		
		while(item[hash_key].valid && item[hash_key].key != key)
			hash_key = (hash_key + 1) % TABLE_SIZE;
			
		item[hash_key].key = key;
		item[hash_key].valid = 1;
		
		return item[hash_key].value;
	}
	
};

//unordered_map<string, int> dic_P;
//unordered_map<string, int> dic_cnt;

_unordered_map dic_P;
_unordered_map dic_cnt;

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

NODE temp[10005];
void merge_sort(int start, int end, vector<NODE> &arr){
	if(end - start<=1)
		return;
	
	int mid = (start + end) / 2;
	merge_sort(start, mid, arr);
	merge_sort(mid, end, arr);
	
	int p = start, p1 = start, p2 = mid;
	while (p<end){
		if(p2 == end || p1 < mid &&  cmp(arr[p1], arr[p2]))
			temp[p++] = arr[p1++];
		else
			temp[p++] = arr[p2++];
	}
	
	for(int i=start; i<end; ++i)
		arr[i] = temp[i];
	
}


//void print_(unordered_map<string,int> const &dic_P){
//	printf("dic= {");
//	for(auto const &pair:dic_P){
//		printf("%s:%d, ",pair.first.c_str(), pair.second);
//	}
//	printf("}\n");
//}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
	int vsize = genres.size();
    vector<NODE> Nodelist(vsize);
    int Nidx=0;
    for(int i=0; i<vsize; ++i){
    	dic_P[genres[i]]+= plays[i];
    	dic_cnt[genres[i]]=0;
    	Nodelist[i].id = Nidx++;
    	Nodelist[i].GENRE = genres[i];
    	Nodelist[i].self_plays = plays[i];
	}
    
    
//    print_(dic_P);
//    print_(dic_cnt);
    
//    sort(Nodelist.begin(), Nodelist.end(), cmp);
	merge_sort(0,vsize,Nodelist);
    for(int i=0; i<vsize; ++i){
    	if(dic_cnt[Nodelist[i].GENRE]>=2)
    		continue;
    	answer.push_back(Nodelist[i].id);
    	dic_cnt[Nodelist[i].GENRE]++;
	}
   
//     for(int i=0; i<answer.size(); ++i){
//     	printf("%d", answer[i]);  	
// 	}
    
    
    return answer;
}
