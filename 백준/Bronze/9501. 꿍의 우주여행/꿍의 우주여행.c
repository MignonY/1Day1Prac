#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--){
        int n, d, ans = 0;
        scanf("%d %d", &n, &d);
        while (n--){ 
            int vi, fi, ci;
            scanf("%d %d %d", &vi, &fi, &ci);
            if (vi * fi / ci>=d)
                ans++;
        }
        printf("%d\n", ans); 
    }
}
