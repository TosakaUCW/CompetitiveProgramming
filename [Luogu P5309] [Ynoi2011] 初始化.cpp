#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <math.h>

typedef long long ll;

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < '0'  or ch > '9')
		f = ch == '-', ch = getchar();
	while ('0' <= ch and ch <= '9')
		x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

const int N = 2e5 + 5;
const int P = 1e9 + 7;
const int SIZ = 5e2 + 5;
const int S = 80;

int n, m, siz;
int bel[N];
ll a[N], sum[SIZ], pre[SIZ][SIZ], suf[SIZ][SIZ];

void modify(int x, int y, int z)
{
    if (x >= S)
		for (int i = y; i <= n; i += x)
			a[i] += z, sum[bel[i]] += z;
	else
	{
		for (int i = y; i <= x; i++) pre[x][i] += z;
		for (int i = y; i >= 1; i--) suf[x][i] += z;
	}
}

ll block_sum(int x, int y)
{
	ll res = 0;
	if (bel[x] == bel[y])
		for (int i = x; i <= y; i++)
			res += a[i];
	else
	{
		for (int i = x; i <= bel[x] * siz; i++) res += a[i];
		for (int i = bel[x] + 1; i < bel[y]; i++) res += sum[i];
		for (int i = (bel[y] - 1) * siz + 1; i <= y; i++) res += a[i];
	}
	return res;
}

ll query(int x, int y)
{
	ll res = block_sum(x, y);
	for (int i = 1; i < S; i++)
	{
		int L = (x - 1) / i + 1, R = (y - 1) / i + 1;
		if (L == R)
			res += pre[i][(y - 1) % i + 1] - pre[i][(x - 1) % i];
		else
			res += (R - L - 1) * pre[i][i] + suf[i][(x - 1) % i + 1] + pre[i][(y - 1) % i + 1];
	}
	return res % P;
}

int main()
{
	n = read(), m = read(), siz = sqrt(n);
	for (int i = 1; i <= n; i++)
		bel[i] = (i - 1) / siz + 1;
	for (int i = 1; i <= n; i++) 
		a[i] = read(), sum[bel[i]] += a[i];
	while (m--)
	{
		int opt = read(), x = read(), y = read();
		if (opt == 1) modify(x, y, read());
		else printf("%lld\n", query(x, y));
	}
	return 0;
}
