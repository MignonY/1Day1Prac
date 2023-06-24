#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i <n-1; i++)
	{	
		for (int k = n - 1; k > i; k--)printf(" ");

		for (int j = 0; j <= i*2; j++)
		{	
			if (j == 0 || j == (i*2))
				printf("*");
			else
				printf(" ");
		}

		printf("\n");
	}
	for (int i = n * 2 - 1; i > 0; i--)printf("*");

	return 0;
}