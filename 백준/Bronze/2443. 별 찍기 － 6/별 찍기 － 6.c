#include <stdio.h>
int main()
{
	int N,i,k=0;
	scanf ("%d",&N);
	N=N*2;
	N=N-1;
	while (1)
	{	
		if (0>=N)
		{
			break;
		}
		for (i=k;i>0;i--)
		{
			printf (" ");
		}
		for (i=N;i>0;i--)
		{
			printf ("*");
		}
		k=k+1;
		N=N-2;	
		printf ("\n");
	}
	return 0;
}