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

int minus(int x, int y, int k)
{
	int res = 0;
	for (int tmp = 1; x or y; tmp *= k)
	{
		int p = (x % k - y % k + k) % k;
		x /= k, y /= k, res += p * tmp;
	}
	return res;
}

void solve()
{
#define flu fflush(stdout)
	int n = read(), k = read(), ans = 0;
	puts("0"), flu, ans = read();
	for (int i = 1; !ans; i++, ans = read())
		printf("%lld\n", i & 1 ? minus(i - 1, i, k) : minus(i, i - 1, k)), flu;
}

signed main()
{
	for (int T = read(); T--; solve());
	return 0;
}

