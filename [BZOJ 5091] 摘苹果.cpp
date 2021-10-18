#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e5 + 5;
const int P = 1e9 + 7;

int pow(int x, int k, int res = 1) { for (x %= P, k %= (P - 1); k; k >>= 1, x = x * x % P) if (k & 1) res = res * x % P; return res; }

int ans, n, m, k, a[N], d[N];

signed main()
{
	freopen("apple.in", "r", stdin), freopen("apple.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= m; i++) d[read()]++, d[read()]++;
	for (int i = 1; i <= n; i++) ans = (ans + a[i] * d[i] % P) % P;
	printf("%lld", ans * k % P * pow(2 * m, P - 2) % P);
	return 0;
}
