#include <stdio.h>

int main()
{
	int A, B, C, D;
	int h = 0, m = 0, s = 0;

	scanf("%d %d %d", &A, &B, &C);
	scanf("%d", &D);

	h = D / 3600;
	m = (D % 3600) / 60;
	s = (D % 3600) % 60;

	C += s;
	if (C > 59)
	{
		C -= 60;
		B += 1;
	}
	B += m;
	if (B > 59)
	{
		B -= 60;
		A += 1;
	}
	A += h;
	if (A > 23)
	{
		A %= 24;
	}

	printf("%d %d %d", A, B, C);
	
	return 0;
}