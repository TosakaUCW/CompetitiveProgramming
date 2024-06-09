#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 2e5 + 5;
const int P = 998244353;

int n, inv[N], fac[N];
char s[N];

int pow(int x, int k, int res = 1)
{
	for (; k; x = x * x % P, k >>= 1)
		if (k & 1) res = res * x % P;
	return res;
}

int C(int n, int m) { return n >= m ? fac[n] * inv[m] % P * inv[n - m] % P : 0; }

void solve(int x = 0, int y = 0)
{
	n = read();
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) if (s[i] == 48) y++;
	for (int i = 1; i < n; i++)
		if (s[i] == s[i + 1] and s[i] == 49)
			x++, i++;
	printf("%lld\n", C(x + y, x));
}

signed main()
{
	fac[0] = 1;
	for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % P;
	inv[N - 1] = pow(fac[N - 1], P - 2);
	for (int i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % P;
	for (int T = read(); T--; solve());
	return 0;
}

