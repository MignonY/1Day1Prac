#include <stdio.h>

int N, W, H;

int main()
{
    scanf("%d %d %d", &N, &W, &H);

    while (N--) {
        int a;
        scanf("%d", &a);
        if (W * W + H * H >= a * a) printf("DA\n");
        else printf("NE\n");
    }
    return 0;
}
