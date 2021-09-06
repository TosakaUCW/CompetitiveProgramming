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

const int N = 2e5 + 5;
const int NN = 2e5;
const int P = 1e9 + 7;

int fac[N], inv[N];

int pow(int x, int k, int res = 1)
{
	for (x %= P, k %= (P - 1); k; k >>= 1, x = x * x % P) if (k & 1) res = res * x % P;
	return res;
}

int C(int n, int m) { return fac[n] * inv[n - m] % P * inv[m] % P; }

void solve()
{
	int n = read(), k = read(), x = 0, y = 0, res = 0;
	for (int i = 0; i < n; i += 2) x = (x + C(n, i)) % P;
	for (int i = 1; i < n; i += 2) y = (y + C(n, i)) % P;
	if (n & 1) x++;
	for (int i = 1; i <= n; i++) res = (res + pow(x, i - 1) * y % P * pow(2, n * (k - i)) % P) % P;
	printf("%lld\n", (pow(2, n * k) - res + P) % P);
}

signed main()
{
	fac[0] = 1;
	for (int i = 1; i <= NN; i++) fac[i] = fac[i - 1] * i % P;
	inv[NN] = pow(fac[NN], P - 2);
	for (int i = NN - 1; i > 0; i--) inv[i] = inv[i + 1] * (i + 1) % P;
	for (int T = read(); T--; solve());
	return 0;
}

