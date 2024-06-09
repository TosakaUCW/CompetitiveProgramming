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

const int N = 1e6 + 5;
const int P = 1e9 + 7;

int n, k, ans;
int fac[N], inv[N], pw[N];

int C(int n, int k) { return fac[n] * inv[k] % P * inv[n - k] % P; }

int pow(int x, int k, int res = 1)
{
	for (x %= P; k; k >>= 1, x = x * x % P)
		if (k & 1)
			res = res * x % P;
	return res;
}

signed main()
{
	n = read(), k = read();
	fac[0] = pw[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % P,
		pw[i] = 2LL * pw[i - 1] % (P - 1);
	inv[n] = pow(fac[n], P - 2);
	for (int i = n - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % P;
	for (int i = k; i <= n; i++)
	{
		int g = C(n, i) * pow(2, pw[n - i]) % P;
		if ((i - k) & 1)
			ans = (ans - C(i, k) * g % P + P) % P;
		else
			ans = (ans + C(i, k) * g % P) % P;
	}
	return printf("%lld", ans), 0;
}