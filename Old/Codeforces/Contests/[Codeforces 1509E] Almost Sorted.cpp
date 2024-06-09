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

const int N = 1e5 + 5;
const int S = 1e18 + 1;

int n, k, a[N];

int pow(int k) { return k > 60 ? S : 1LL << k; }

void solve()
{
	n = read(), k = read() - 1;
	int cnt = 0;
	for (int l = 1, r = 1; l <= n; l = r)
	{
		for (r = l + 1; r <= n and cnt + pow(n - r) <= k; r++)
			cnt += pow(n - r);
		for (int i = l; i <= r; i++) a[i] = l + r - i - 1;
	}
	if (cnt != k) return puts("-1"), void();
	for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
	puts("");
}

signed main()
{
	for (int T = read(); T--; solve());
	return 0;
}
