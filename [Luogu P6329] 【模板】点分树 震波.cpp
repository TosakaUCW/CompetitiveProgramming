#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return x;
}

const int N = 1e5 + 5;

int n, m, val[N];
int rt, sum, f[N], siz[N], fa[N], dep[N], d[N][20];
bool vis[N];

int hd[N], E;
struct Edge { int ne, to; } e[N << 1];
void add(int u, int v) { e[++E] = {hd[u], v}, hd[u] = E; }
#define edge(i, u, v) for (int i = hd[u], v = e[i].to; i; i = e[i].ne, v = e[i].to)

struct LCA
{
	int dep[N], fa[N], son[N], siz[N], top[N];
	void init() { dfs1(1, 0), dfs2(1); }
	void dfs1(int u, int fath)
	{
		siz[u] = 1, dep[u] = dep[fath] + 1, fa[u] = fath;
		edge(i, u, v) if (v != fath) dfs1(v, u), siz[u] += siz[v], son[u] = siz[v] > siz[son[u]] ? v : son[u]; 
	}
	void dfs2(int u)
	{
		top[u] = u == son[fa[u]] ? top[fa[u]] : u;
		if (son[u]) dfs2(son[u]);
		edge(i, u, v) if (v != fa[u] and v != son[u]) dfs2(v);
	}
	int lca(int x, int y)
	{
		for (; top[x] != top[y]; x = fa[top[x]])
			if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		return dep[x] < dep[y] ? x : y;
	}
	int query(int x, int y) { return dep[x] + dep[y] - 2 * dep[lca(x, y)]; }
} lca;

struct SegTree
{
#define M (N << 5)
#define ls (lc[p])
#define rs (rc[p])
#define mid ((l + r) >> 1)
	int cnt, rt[N], sum[M], lc[M], rc[M];
	void update(int &p, int l, int r, int x, int v)
	{
		if (!p) p = ++cnt;
		if (l == r) return sum[p] += v, void();
		if (x <= mid) update(ls, l, mid, x, v);
		else update(rs, mid + 1, r, x, v);
		sum[p] = sum[ls] + sum[rs];
	}
	int query(int p, int l, int r, int ql, int qr)
	{
		if (!p or r < ql or l > qr) return 0;
		if (ql <= l and r <= qr) return sum[p];
		return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
	}
} dist, ch;

void getrt(int u, int fa)
{
	siz[u] = 1, f[u] = 0;
	edge(i, u, v) if (!vis[v] and v ^ fa)
		getrt(v, u), siz[u] += siz[v], f[u] = std::max(f[u], siz[v]);
	f[u] = std::max(f[u], sum - siz[u]);
	if (f[u] < f[rt]) rt = u;
}

void dfs1(int x, int fa, int y, int d)
{
	ch.update(ch.rt[y], 0, n, d, val[x]);
	edge(i, x, v) if (!vis[v] and v ^ fa) dfs1(v, x, y, d + 1);
}

void dfs2(int x, int fa, int y, int d)
{
	dist.update(dist.rt[y], 0, n, d, val[x]);
	edge(i, x, v) if (!vis[v] and v ^ fa) dfs2(v, x, y, d + 1);
}

void solve(int u)
{
	vis[u] = 1, dfs2(u, 0, u, 0);
	edge(i, u, v) if (!vis[v]) 
		rt = 0, sum = siz[v], f[rt] = n, getrt(v, 0),
		dfs1(v, 0, rt, 1),
		fa[rt] = u, dep[rt] = dep[u] + 1, solve(rt);
}

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) val[i] = read();
	for (int i = 1, u, v; i < n; i++) u = read(), v = read(), add(u, v), add(v, u);
	lca.init(), f[rt] = sum = n, getrt(1, 0), solve(rt);
	for (int i = 1; i <= n; i++) for (int j = i; j; j = fa[j]) 
		d[i][dep[i] - dep[j]] = lca.query(i, j);
	for (int ans = 0; m--; )
	{
		int opt = read(), x = read() ^ ans, y = read() ^ ans, now = 0;
		if (opt == 0)
		{
			ans = dist.query(dist.rt[x], 0, n, 0, y);
			for (int i = x; fa[i]; i = fa[i])
			{
				now = d[x][dep[x] - dep[fa[i]]];
				ans += dist.query(dist.rt[fa[i]], 0, n, 0, y - now);
				ans -= ch.query(ch.rt[i], 0, n, 0, y - now);
			}
			printf("%d\n", ans);
		}
		else
		{
			dist.update(dist.rt[x], 0, n, 0, y - val[x]);
			for (int i = x; fa[i]; i = fa[i])
			{
				now = d[x][dep[x] - dep[fa[i]]];
				dist.update(dist.rt[fa[i]], 0, n, now, y - val[x]);
				ch.update(ch.rt[i], 0, n, now, y - val[x]);
			}
			val[x] = y;
		}
	}
	return 0;
}
