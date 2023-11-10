#include <stdio.h>
 
int T,V,E,ans;

int main() {
    scanf("%d", &T);
 
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &V, &E);
        ans = 2 - V + E;

        printf("%d\n", ans);
    }
    
    return 0;
}