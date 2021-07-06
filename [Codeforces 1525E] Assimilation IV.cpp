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

const int N = 20 + 5;
const int M = 5e4 + 5;
const int P = 998244353;

int n, m, a[M][N];
int ans, sum, mul, fac = 1;

int pow(int x, int k, int res = 1)
{
	for (x %= P; k; k >>= 1, x = x * x % P)
		if (k & 1) res = res * x % P;
	return res;
}

signed main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[j][read()]++;
	for (int i = 2; i <= n; i++) fac = fac * i % P;
	fac = pow(fac, P - 2);
	for (int i = 1; i <= m; i++)
	{
		sum = 0, mul = 1;
		for (int j = 1; j <= n; j++)
			sum += a[i][n + 2 - j],
			mul = mul * sum % P,
			sum--;
		ans = (ans + 1 - fac * mul % P + P) % P;
	}
	return printf("%lld", ans), 0;
}
