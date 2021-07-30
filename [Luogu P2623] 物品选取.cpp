#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 100 + 5;
const int M = 2000 + 5;

int n, m, ans, f[M];
int t[N], a[N], b[N], c[N];

int main()
{
	freopen("pack.in", "r", stdin);
	freopen("pack.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
	{
		t[i] = read(), a[i] = read(), b[i] = read();
		if (t[i] == 2) c[i] = read();
		if (t[i] == 2)
			for (int j = m; j >= 0;                j--)
				for (int k = 0; k <= c[i] and j - k * b[i] >= 0; k++)
					f[j] = std::max(f[j], f[j - k * b[i]] + k * a[i]);
		else
			for (int j = b[i]; j <= m; j++) f[j] = std::max(f[j], f[j - b[i]] + a[i]);
	}

	for (int j = 1; j <= m; j++) f[j] = std::max(f[j], f[j - 1]);
	ans = f[m];
#define calc(i, j) (a[i] * j * j - b[i] * j)
	for (int i = 1; i <= n; i++)
		if (t[i] == 1)
			for (int j = 0; j <= m; j++)
				ans = std::max(ans, f[m - j] + calc(i, j));
	return printf("%d", ans), 0;
}
