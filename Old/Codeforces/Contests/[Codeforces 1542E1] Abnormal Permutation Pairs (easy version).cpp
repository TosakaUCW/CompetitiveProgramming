#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 50 + 5;

int n, P, f[N][N * N], sum[N][N * N], ans[N];

int plus(const int &x, const int &y) { return (x + y) % P; }
int minus(const int &x, const int &y) { return (x - y + P) % P; }

signed main()
{
	n = read(), P = read();
	sum[0][0] = f[0][0] = 1;
	for (int j = 1; j <= n * (n - 1) / 2; j++) sum[0][j] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n * (n - 1) / 2; j++)
		{
			if (j - i >= 0)
				f[i][j] = minus(sum[i - 1][j], sum[i - 1][j - i]);
			else
				f[i][j] = sum[i - 1][j];
			sum[i][j] = plus(f[i][j], j ? sum[i][j - 1] : 0);
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			for (int k = j + 1; k <= i; k++)
				for (int w = 0; w <= (i - 1) * (i - 2) / 2; w++)
				{
					int t = w - (k - j) - 1;
					if (t >= 0)
						ans[i] = plus(ans[i], f[i - 1][w] * sum[i - 1][t] % P);
				}
	for (int i = 2; i <= n; i++) ans[i] = plus(ans[i], i * ans[i - 1] % P);
	return printf("%lld", ans[n]), 0;
}
