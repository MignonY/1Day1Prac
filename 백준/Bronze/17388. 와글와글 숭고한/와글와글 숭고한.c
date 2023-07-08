
int s, k, h;

int main() {
	scanf("%d%d%d", &s, &k, &h);

	if (s + k + h >= 100)
		printf("OK");
	else {
		int min = s;
		if (k < min)
			min = k;
		if (h < min)
			min = h;

		if (min == k)
			printf("Korea");
		else if (min == s)
			printf("Soongsil");
		else
			printf("Hanyang");
	}
	return 0;
}