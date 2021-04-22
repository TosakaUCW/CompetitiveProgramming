#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < '0'  or ch > '9')
		f = ch == '-', ch = getchar();
	while ('0' <= ch and ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

const int N = 2e3 + 5;

int n, ans;
int a[N], f[N][N];

signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	std::sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) f[i][i] = 0;
	for (int k = 2; k <= n; k++)
		for (int i = 1; i + k - 1 <= n; i++)
		{
			int j = i + k - 1;
			f[i][j] = a[j] - a[i] + std::min(f[i + 1][j], f[i][j - 1]);
		}
	printf("%lld", f[1][n]);
	return 0;
}
