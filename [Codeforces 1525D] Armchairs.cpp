#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return x;
}

const int N = 5e3 + 5;

int n, x, y, ans;
int a[N], b[N], p[N], f[N][N];

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		p[i] = read();
		if (p[i]) a[++x] = i;
		else b[++y] = i;
	}
	memset(f, 0x3f, sizeof f), ans = f[0][0];
	for (int j = 1; j <= y; j++) f[0][j] = 0;
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= y; j++)
			f[i][j] = std::min(f[i][j - 1], f[i - 1][j - 1] + abs(a[i] - b[j]));
	for (int j = 1; j <= y; j++) ans = std::min(ans, f[n][j]);
	return printf("%d", ans), 0;
}
