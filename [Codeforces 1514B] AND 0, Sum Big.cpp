#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < '0' or ch > '9')
		f = ch == '-', ch = getchar();
	while ('0' <= ch and ch <= '9')
		x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

const int P = 1e9 + 7;

int pow(int x, int k, int res = 1)
{
	for (x %= P; k; k >>= 1, x = x * x % P)
		if (k & 1) res = res * x % P;
	return res;
}

signed main()
{
	for (int T = read(), n, k; T--; )
		n = read(), k = read(), printf("%lld\n", pow(n, k));
	return 0;
}
