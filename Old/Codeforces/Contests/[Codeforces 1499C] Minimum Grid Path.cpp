#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 2e5 + 5;
const int INF = 2147483647;

int n;
int a[N];

void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	int ans = (a[1] + a[2]) * n;
	int x = 0, y = 0, f = 0, g = 0;
	int p = INF, q = INF;
	for (int i = 1; i <= n; i++)
	{
		if (i & 1) x += a[i], f++, p = std::min(p, a[i]);
		else y += a[i], g++, q = std::min(q, a[i]);
		ans = std::min(ans, x + (n - f) * p + y + (n - g) * q);
	}
	printf("%lld\n", ans);
}

signed main()
{
	for (int T = read(); T--; solve());
	return 0;
}
