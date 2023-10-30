#include <stdio.h>
#include <algorithm>
using namespace std;
int s[4],m[2], ans;
int main(){
    for (int i = 0; i < 4; i++){
        scanf("%d", &s[i]);
    }
    sort(s, s + 4);
    for (int i = 0; i < 2; i++){
        scanf("%d", &m[i]);
    }
    sort(m, m + 2);
    ans = s[1] + s[2] + s[3] + m[1];
    printf("%d\n", ans);
}