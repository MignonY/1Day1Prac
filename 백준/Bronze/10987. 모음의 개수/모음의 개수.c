#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
	char str[MAX_LENGTH];
	int cnt = 0;

	scanf("%s", str);

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
			cnt++;
	}

	printf("%d\n", cnt);
}