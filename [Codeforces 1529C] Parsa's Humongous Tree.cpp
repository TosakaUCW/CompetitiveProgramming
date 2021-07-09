#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e5 + 5;

int n, a[N], b[N], f[N][2];
std::vector<int> g[N];

void dfs(int u, int fa)
{
	for (int v : g[u])
		if (v ^ fa)
			dfs(v, u),
			f[u][0] += std::max(f[v][0] + abs(a[u] - a[v]), f[v][1] + abs(a[u] - b[v])),
			f[u][1] += std::max(f[v][0] + abs(b[u] - a[v]), f[v][1] + abs(b[u] - b[v]));
}

void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) 
		a[i] = read(), b[i] = read(),
		f[i][0] = f[i][1] = 0, g[i].clear();
#define pb push_back
	for (int i = 1, u, v; i < n; i++) 
		u = read(), v = read(), g[u].pb(v), g[v].pb(u);
	dfs(1, 0), printf("%lld\n", std::max(f[1][0], f[1][1]));
}

signed main()
{
	for (int T = read(); T--; solve());
	return 0;
}
