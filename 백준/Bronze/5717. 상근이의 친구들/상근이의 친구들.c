#include <stdio.h>
void friends()
{
    int N, M;
    while (1)
    {
        
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0)
            break;
        printf("%d\n", N + M);
    }
}
int main()
{
    friends();
}