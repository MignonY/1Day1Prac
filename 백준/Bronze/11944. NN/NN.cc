#include <bits/stdc++.h>
using namespace std;

char n[5];
int m;
int main(){
    scanf("%s %d", n, &m);
    int sz = strlen(n);
    int val = atoi(n);
    int k = min(sz*val, m);
    for(int i = 0; i < k; i++){
        printf("%c", n[i%sz]);
    }
}