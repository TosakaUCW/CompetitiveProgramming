#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 1e3 + 5;
const int M = 4e3 + 5;
const int INF = 2147483647;

int n, ans = INF, sum;
int a[N], b[N], f[N][M];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), sum += a[i];
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	memset(f, 127, sizeof f);
	f[0][0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= sum; j++)
			if (j < a[i])
				f[i][j] = f[i - 1][j] + b[i];
			else
				f[i][j] = std::min(f[i - 1][j] + b[i], f[i - 1][j - a[i]]);
	for (int j = 0; j <= sum; j++)
		ans = std::min(ans, std::max(j, f[n][j]));
	printf("%d", ans);
	return 0;
}