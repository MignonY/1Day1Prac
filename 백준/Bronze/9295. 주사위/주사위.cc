#include <stdio.h>
 
int main() {
 
 
    int n, a, b;
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        printf("Case %d: %d\n", i + 1, a + b);
        // %d는 출력이 될때 원하는 변수가 나오게 하게끔 선언하는 것이다.
        // i+1는 for문이 i가 0으로 시작해서 +1을 해주지 않으면
        // 처음 Case 값은 Case 0: a+b가 나올것이다.
    }
 
}
