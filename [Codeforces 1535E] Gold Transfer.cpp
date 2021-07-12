#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

#define int long long
#define flush fflush(stdout)

const int N = 3e5 + 5;

int n, q, a[N], c[N];
int f[N][21];

int get(int x)
{
	for (int i = 19; i >= 0; i--)
		if (a[f[x][i]]) x = f[x][i];
    return x;
}

signed main()
{
	q = read(), a[1] = read(), c[1] = read();
	for (int i = 2; i <= 1 + q; i++, flush)
	{
		int opt = read();
		if (opt == 1)
		{
			f[i][0] = read() + 1, a[i] = read(), c[i] = read();
			for (int j = 1; j <= 19; j++)
				f[i][j] = f[f[i][j - 1]][j - 1];
		}
		else
		{
			int x = read() + 1, y = read(), res = 0, tot = 0;
			while (a[x] and y)
			{
				int u = get(x);
				if (a[u] >= y)
					a[u] -= y,res += y * c[u], tot += y, y = 0;
				else
					tot += a[u], res += a[u] * c[u], y -= a[u], a[u] = 0;
			}
			printf("%lld %lld\n", tot, res);
		}
	}
	return 0;
}
