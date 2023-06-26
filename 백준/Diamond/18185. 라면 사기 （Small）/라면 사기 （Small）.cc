#include <stdio.h>
#include <algorithm>
 
using namespace std;
 

 
int n, a[10050];
 
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
 
    int answer = 0;
 
    for (int i = 0; i < n; i++) {
        if (a[i + 1] > a[i + 2]) {
            int two = min(a[i], a[i + 1] - a[i + 2]);
            answer += 5 * two;
            a[i] -= two;
            a[i + 1] -= two;
 
            int three = min(a[i], min(a[i + 1], a[i + 2]));
            answer += 7 * three;
            a[i] -= three;
            a[i + 1] -= three;
            a[i + 2] -= three;
        }
        else {
            int three = min(a[i], min(a[i + 1], a[i + 2]));
            answer += 7 * three;
            a[i] -= three;
            a[i + 1] -= three;
            a[i + 2] -= three;
 
            int two = min(a[i], a[i + 1]);
            answer += 5 * two;
            a[i] -= two;
            a[i + 1] -= two;
        }
    
        answer += 3 * a[i];    
    }
 
    printf("%d\n", answer);
 
    return 0;
}