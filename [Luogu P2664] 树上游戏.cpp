#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return x;
}

const int N = 1e5 + 5;

int n, rt;
int c[N], ans[N], f[N], siz[N];
bool vis[N];
int col[N], cnt[N], tot, sum, num;

int hd[N], E;
struct Edge { int ne, to; } e[N << 1];
void add(int u, int v) { e[++E] = {hd[u], v}, hd[u] = E; };
#define edge(i, u, v) for (int i = hd[u], v = e[i].to; i; i = e[i].ne, v = e[i].to)

void getrt(int u, int fa, int sum)
{
	siz[u] = 1, f[u] = 0;
	edge(i, u, v) if (!vis[v] and v ^ fa)
		getrt(v, u, sum), siz[u] += siz[v], f[u] = std::max(f[u], siz[v]);
	f[u] = std::max(f[u], sum - siz[u]);
	if (f[u] < f[rt] or !rt) rt = u;
}

void change(int u, int fa, int val)
{
	++cnt[c[u]];
	edge(i, u, v) if (!vis[v] and v ^ fa) change(v, u, val);
	if (cnt[c[u]] == 1) sum += siz[u] * val, col[c[u]] += siz[u] * val;
	--cnt[c[u]];
}

void dfs1(int u, int fa)
{
	siz[u] = 1, ++cnt[c[u]];
	edge(i, u, v) if (!vis[v] and v ^ fa) dfs1(v, u), siz[u] += siz[v];
	if (cnt[c[u]] == 1) sum += siz[u], col[c[u]] += siz[u];
	--cnt[c[u]];
}

void dfs2(int u, int fa)
{
	++cnt[c[u]];
	if (cnt[c[u]] == 1) sum -= col[c[u]], ++num;
	ans[u] += sum + num * tot;
	edge(i, u, v) if (!vis[v] and v ^ fa) dfs2(v, u);
	if (cnt[c[u]] == 1) sum += col[c[u]], --num;
	--cnt[c[u]];
}

void clear(int u, int fa)
{
	cnt[c[u]] = col[c[u]] = 0;
	edge(i, u, v) if (v ^ fa and !vis[v]) clear(v, u);
}

void calc(int u)
{
	dfs1(u, 0), ans[u] += sum - col[c[u]] + siz[u];
	edge(i, u, v) if (!vis[v])
	{
		++cnt[c[u]], sum -= siz[v], col[c[u]] -= siz[v], change(v, u, -1), --cnt[c[u]];
		tot = siz[u] - siz[v], dfs2(v, u);
		++cnt[c[u]], sum += siz[v], col[c[u]] += siz[v], change(v, u, 1), --cnt[c[u]];
	}
	sum = num = 0, clear(u, 0);
}

void solve(int u)
{
	vis[u] = 1, calc(u);
	edge(i, u, v) if (!vis[v]) rt = 0, getrt(v, 0, siz[v]), solve(rt);
}

signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) c[i] = read();
	for (int i = 1, u, v; i < n; i++)
		u = read(), v = read(), add(u, v), add(v, u);
	f[rt] = n, getrt(1, 0, n), solve(rt);
	for (int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
	return 0;
}
