#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 5e3 + 5;

int n, sum, a[N], b[N], f[N][N];

signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) b[i] = read();
	for (int i = 1; i <= n; i++) sum += a[i] * b[i];
	for (int i = 1; i <= n; i++) f[i][i] = f[i + 1][i] = f[i][i + 1] = sum;
	for (int len = 2; len <= n; len++)
		for (int i = 1, j = i + len - 1; j <= n; i++, j++)
			f[i][j] = f[i + 1][j - 1] - a[i] * b[i] - a[j] * b[j] + a[i] * b[j] + a[j] * b[i];
	sum = 0;
	for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) sum = std::max(sum, f[i][j]);
	return printf("%lld", sum), 0;
}
