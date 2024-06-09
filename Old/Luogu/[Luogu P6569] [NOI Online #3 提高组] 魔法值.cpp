#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while ('0' > ch or ch > '9')
		f = ch == '-', ch = getchar();
	while ('0' <= ch and ch <= '9')
		x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

const int N = 1e2 + 5;

struct Matrix
{
	int n, m, a[N][N];
	Matrix() { n = m = 0, memset(a, 0, sizeof a); }
	Matrix friend operator*(Matrix a, Matrix b)
	{
		Matrix c;
		c.n = a.n, c.m = b.m;
		for (int i = 1; i <= a.n; i++)
			for (int j = 1; j <= b.m; j++)
				for (int k = 1; k <= a.m; k++)
					c.a[i][j] ^= a.a[i][k] * b.a[k][j];
		return c;
	}
} a[40];

int n, m, q;
int f[N];

signed main()
{
	n = read(), m = read(), q = read();
	for (int i = 1; i <= n; i++)
		f[i] = read();
	a[0].n = a[0].m = n;
	for (int i = 1, u, v; i <= m; i++)
		u = read(), v = read(), a[0].a[u][v] = a[0].a[v][u] = 1;
	for (int i = 1; i < 32; i++)
		a[i] = a[i - 1] * a[i - 1];
	for (int x; q--;)
	{
		x = read();
		Matrix ans;
		for (int i = 1; i <= n; i++)
			ans.a[1][i] = f[i];
		ans.n = 1, ans.m = n;
		for (int i = 0; i < 32; i++)
			if ((x >> i) & 1)
				ans = ans * a[i];
		printf("%lld\n", ans.a[1][1]);
	}
	return 0;
}