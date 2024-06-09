#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 5e5 + 5;
const int P = 998244353;

int n, m, L[N], R[N], l[N], r[N], f[N], g[N], ans;
int cnt, pri[N], mu[N];
bool vis[N];

void init(int n)
{
	vis[1] = mu[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!vis[i]) pri[++cnt] = i, mu[i] = -1;
		for (int j = 1; j <= cnt and i * pri[j] <= n; j++)
		{
			vis[i * pri[j]] = 1;
			mu[i * pri[j]] = i % pri[j] == 0 ? 0 : mu[i] * mu[pri[j]];
			if (i % pri[j] == 0) break;
		}
	}
}

signed main()
{
	n = read(), m = read(), init(5e5);
	for (int i = 1; i <= n; i++) L[i] = read(), R[i] = read();
	for (int d = 1; d <= m; d++)
	{
		if (!mu[d]) continue;
		int s = m / d;
		for (int i = 1; i <= n; i++) l[i] = (L[i] + d - 1) / d, r[i] = R[i] / d;
		for (int i = 0; i <= s; i++) g[i] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= s; j++) f[j] = 0;
			for (int j = l[i]; j <= s; j++)
				f[j] = (g[j - l[i]] - (j >= r[i] + 1 ? g[j - r[i] - 1] : 0) + P) % P;
			g[0] = 0;
			for (int j = 1; j <= s; j++) g[j] = (g[j - 1] + f[j]) % P;
		}
		ans = (ans + (mu[d] * g[s] + P)% P) % P;
	}
	return printf("%lld", ans), 0;
}
