#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, pair<int,int>>>VEC;
int parent[105], csize, answer,N;

int findP(int a){
	if(a == parent[a])
		return a;
	return parent[a] = findP(parent[a]);
}

void merge(int a, int b){
	a= findP(a);
	b= findP(b);
	if (a==b)
		return;
	else
        parent[a] = b;
		
}


void KRUSKAL(){
	for(int i=0; i<N; ++i)
		parent[i] = i;
		
	sort(VEC.begin(), VEC.end());
	
	for(int i=0; i < VEC.size(); ++i){
		int cost = VEC[i].first;
		int current = VEC[i].second.first;
		int next = VEC[i].second.second;
		
		if (findP(current) != findP(next)){
			answer += cost;
			merge(current, next);
		}	
	}	
}


int solution(int n, vector<vector<int>> costs) {
    N = n;
    answer = 0;
    csize = costs.size();
    for(int i=0; i<csize; ++i){
    	VEC.push_back({costs[i][2], {costs[i][0], costs[i][1]}});
    	VEC.push_back({costs[i][2], {costs[i][1], costs[i][0]}});
	}
    KRUSKAL();
    printf("%d", answer);
    return answer;
}