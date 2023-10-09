#include <stdio.h>

int main(void)
{
	int k, n;
	scanf("%d", &n);
	char a[101][101];
	for(int i = 0; i < n; i++)
	{
			scanf("%s", a[i]);
	}
	scanf("%d", &k);
	if(k == 1)
	{
		for(int l = 0; l < n; l++)
		{
			printf("%s\n", a[l]);
		}
	}
	else if(k ==2)
	{
		for(int m = 0; m < n; m++)
		{
			for(int j = 0; j < n; j++)
			{
				printf("%c", a[m][n-j-1]);
			}
			printf("\n");
		}
	}
	else if(k == 3)
	{
		for(int q = 0; q < n; q++)
		{
			for(int j = 0; j < n; j++)
			{
				printf("%c", a[n-q-1][j]);
			}
			printf("\n");
		}
	}
	return 0;
}