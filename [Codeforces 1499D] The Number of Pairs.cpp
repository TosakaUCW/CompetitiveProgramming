#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 2e7 + 5;

#define pii std::pair<int, int>
#define pb push_back
#define fi first
#define se second

int cnt, pri[N], pw[31], f[N], g[N];
bool vis[N];

void init(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!vis[i]) pri[++cnt] = i, f[i] = 1, g[i] = i;
		for (int j = 1; j <= cnt and i * pri[j] <= n; j++)
		{
			vis[i * pri[j]] = 1, g[i * pri[j]] = pri[j],
			f[i * pri[j]] = f[i] + f[pri[j]] - (i % pri[j] == 0);
			if (i % pri[j] == 0) break;
		}
	}
	pw[0] = 1;
	for (int i = 1; i <= 30; i++) pw[i] = pw[i - 1] << 1;
}

int ans, siz, c, d, x;
std::vector<pii> V;

void split(int x)
{
	V.clear();
	while (x > 1)
	{
		int p = g[x], q = 0;
		while (x % p == 0) q++, x /= p;
		V.pb({p, q});
	}
	siz = V.size();
}

void dfs(int x, int num)
{
	if (num == siz)
	{
		if ((x + d) % c == 0) ans += pw[f[(x + d) / c]];
		return;
	}
	for (int i = 0; i <= V[num].se; i++, x *= V[num].fi) dfs(x, num + 1);
}

void solve()
{
	c = read(), d = read(), x = read(), ans = 0;
	split(x), dfs(1, 0), printf("%d\n", ans);
}

int main()
{
	init(20000000);
	for (int T = read(); T--; solve());
	return 0;
}

