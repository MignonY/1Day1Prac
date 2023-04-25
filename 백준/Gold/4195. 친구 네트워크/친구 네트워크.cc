#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string, int> dic;

char a[25], b[25]; 
string A, B;
int parent[200005], cnt[200005], fnum, Alen, Blen;

template<typename K, typename V>
void print_map(unordered_map<K,V> const &dic){
	printf("dic= {");
	for(auto const &pair:dic){
		printf("%s:%d, ",pair.first.c_str(), pair.second);
	}
	printf("}\n");
}


int findP(int a){
	if(a == parent[a])
		return a;
	
	return parent[a] = findP(parent[a]);
}

void merge(int a, int b){
	a = findP(a);
	b = findP(b);
	if (a==b)
		return;
	if (a>b){
		cnt[b] += cnt[parent[a]];
		parent[a] = b;
	}
	else{
		cnt[a] += cnt[parent[b]];
		parent[b] = a;
	}
}


void init(){
//	for(int i=0; i<Alen+1; ++i)
//		a[i] = 0;
//	for(int i=0; i<Blen+1; ++i)
//		b[i] = 0;
	for(int i=0; i<dic.size()+1; ++i){
		cnt[i] = 1;
	}
	fnum = 0;
	dic.clear();
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i=0; i<200005; ++i)
		cnt[i] = 1;
	
	for(int tc= 1; tc<=T; ++tc){
		int F;
		scanf("%d", &F);
		

		
		for(int i=0; i<F; ++i){
			scanf(" %s",a);
			scanf(" %s",b);
			A = string(a);
			B = string(b);
			Alen= A.size();
			Blen= B.size();

//			printf("%d %d", Alen, Blen);
			if(dic.find(A) == dic.end()){
				dic[A] = fnum++;
				parent[fnum] = fnum;
			}
			if(dic.find(B) == dic.end()){
				dic[B] = fnum++;
				parent[fnum] = fnum;
			} 
			
			if (findP(dic[A]) != findP(dic[B])){
				merge(dic[A], dic[B]);
			}
			
//			printf("A:%s B:%s\n", A.c_str(), B.c_str());
//			print_map(dic);
//			printf("cntls: ");
//			for(int i=0; i<dic.size(); ++i){
//				printf("%d ",cnt[i]);
//			}
//			printf("\n");

			printf("%d\n", cnt[parent[findP(dic[A])]]);			
		}
		init();
	}	
	return 0;
}