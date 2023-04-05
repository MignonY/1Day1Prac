#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
int v, e;
int parent[10001];

int getParent(int x) {
    if (parent[x] == x) return x;
        return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) return 1;
    else return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    cin >> v >> e;
    vector<pair<int, pair<int, int>>> vt;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >>a >> b >> c ;
        vt.push_back({ c, {a, b }});
    }
    sort(vt.begin(), vt.end());

    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    for (int i = 0; i<vt.size();i++) {
        if (!findParent(vt[i].second.first, vt[i].second.second)) {
            answer += vt[i].first;
            unionParent(vt[i].second.first, vt[i].second.second);
        }

    }
    cout << answer;

    return 0;
}