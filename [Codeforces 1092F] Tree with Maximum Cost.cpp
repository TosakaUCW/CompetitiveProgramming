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

int n, a[N], f[N], sum, ans, g[N];
int hd[N], E;
struct Node { int ne, to; } e[N << 1];
void add(int u, int v) { e[++E] = {hd[u], v}, hd[u] = E; }

void dfs1(int u, int fa, int dep)
{
	f[u] = a[u], g[1] += f[u] * dep;
	for (int i = hd[u], v = e[i].to; i; i = e[i].ne, v = e[i].to)
		if (v ^ fa) dfs1(v, u, dep + 1), f[u] += f[v];
}

void dfs2(int u, int fa)
{
	ans = std::max(ans, g[u]);
	for (int i = hd[u], v = e[i].to; i; i = e[i].ne, v = e[i].to)
		if (v ^ fa) g[v] = g[u] - f[v] + sum - f[v], dfs2(v, u);
}

signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read(), sum += a[i];
	for (int i = 1, u, v; i < n; i++) u = read(), v = read(), add(u, v), add(v, u);
	return dfs1(1, 0, 0), dfs2(1, 0), printf("%lld", ans), 0;
}
