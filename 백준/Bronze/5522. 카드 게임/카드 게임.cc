#include <stdio.h>
 
int main()
{
    int JOI_score[5] = {0, };
    int total_score = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &JOI_score[i]);
        total_score += JOI_score[i];
    }
    printf("%d", total_score);
}