#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e5 + 5;

int n, m;
int a[N], b[N];
long long sum[N];

void solve()
{
	n = read();
	long long ans = 0;
	for (int i = 1; i <= n; i++) a[i] = b[i] = read();
	std::sort(b + 1, b + 1 + n);
	m = std::unique(b + 1, b + 1 + n) - b - 1;
	for (int i = 1; i <= n; i++) 
		a[i] = std::lower_bound(b + 1, b + 1 + m, a[i]) - b - 1;
	for (int i = 1; i <= n; i++)
		if (!sum[a[i]]) sum[a[i]] = i;
		else
		{
			ans += 1LL * sum[a[i]] * (n - i + 1);
			sum[a[i]] += i;
		}
	printf("%lld\n", ans);
	for (int i = 0; i < m; i++) sum[i] = 0;
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}
