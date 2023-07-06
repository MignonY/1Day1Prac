#include <stdio.h>

int result, n, max = 2, map[101][101], visited[101][101];

void	visited_init(int cur){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			visited[i][j] = 0;
			if (map[i][j] <= cur)
				visited[i][j]++;
		}
	}
}

void	dfs(int y, int x){
	if (0 <= x && x < n && 0 <= y && y < n && !visited[y][x]){
		visited[y][x]++;
		dfs(y + 1, x);
		dfs(y - 1, x);
		dfs(y, x + 1);
		dfs(y, x - 1);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &map[i][j]);
			if (map[i][j] > max)
				max = map[i][j];
		}
	}
	result = 0;
	for (int i = 0; i <= max; i++){
		int t = 0;
		visited_init(i);
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (!visited[j][k] && ++t)
					dfs(j, k);
		if (t > result)
			result = t;
	}
	printf("%d\n", result);
	return (0);
}