#include <stdio.h>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e6 + 5;
const int P = 998244353;

int n, a[N], fac[N], ans = 1;
int c[N];

#define lbit (x & -x)
void add(int x, int y) { for (; x <= n; x += lbit) c[x] = (c[x] + y) % P; }
int sum(int x, int res = 0) { for (; x; x -= lbit) res = (res + c[x]) % P; return res % P;}

signed main()
{
	n = read(), fac[0] = 1;
	for (int i = 1; i <= n; i++) a[i] = read(), fac[i] = fac[i - 1] * i % P;
	for (int i = n; i >= 1; i--) ans = (ans + fac[n - i] * sum(a[i] - 1) % P) % P, add(a[i], 1);
	return printf("%lld", ans), 0;
}
