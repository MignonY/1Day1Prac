#include <stdio.h>

int main()
{
    int n, i, j;
    int arr[100];
    int count = 0;
    scanf("%d", &n);
    i = 0;
    while (i < n)
    {
        scanf("%d", &arr[i]);
        i++;
    }
    i = 0;
    while (i < n)
    {
        if (arr[i] >= 2)
        {
            j = 2;
            while (j <= arr[i])
            {
                if (j == arr[i])
                    count++;
                if (arr[i] % j == 0)
                    break;
                j++;
            }
            i++;
        }
        else
            i++;
    }
    printf("%d", count);
}