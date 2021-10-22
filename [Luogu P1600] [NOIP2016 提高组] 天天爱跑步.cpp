#include <stdio.h>
#include <algorithm>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 6e5 + 5;

int n, m, ans[N];
int ls[N * 25], rs[N * 25], val[N * 25], rt[N * 25], node;
int son[N], fa[N], top[N], siz[N];
int w[N], dep[N];
int hd[N], E;
struct Node { int ne, to; } e[N];
void add(int u, int v) { e[++E] = {hd[u], v}, hd[u] = E; }

#define mid ((l + r) >> 1)

void update(int &p, int l, int r, int pos, int k)
{
    if (!p) p = ++node;
    if (l == r) return val[p] += k, void();
    pos <= mid ? update(ls[p], l, mid, pos, k) : update(rs[p], mid + 1, r, pos, k);
}

int query(int p, int l, int r, int pos)
{
    if (!p) return 0;
    if (l == r) return val[p];
    return pos <= mid ? query(ls[p], l, mid, pos) : query(rs[p], mid + 1, r, pos);
}

int merge(int x, int y, int l, int r)
{
    if (!x or !y) return x + y;
    if (l == r) val[x] += val[y];
    else ls[x] = merge(ls[x], ls[y], l, mid), rs[x] = merge(rs[x], rs[y], mid + 1, r);
    return x;
}

void dfs1(int u, int fa)
{
    siz[u] = 1, dep[u] = dep[fa] + 1, ::fa[u] = fa;
    for (int i = hd[u], v = e[i].to; i; i = e[i].ne, v = e[i].to)
        if (v ^ fa) dfs1(v, u), siz[u] += siz[v], son[u] = siz[v] > siz[son[u]] ? v : son[u];
}

void dfs2(int u)
{
    top[u] = u == son[fa[u]] ? top[fa[u]] : u;
    if (son[u]) dfs2(son[u]);
    for (int i = hd[u], v = e[i].to; i; i = e[i].ne, v = e[i].to)
        if (v ^ fa[u] and v ^ son[u]) dfs2(v); 
}

int LCA(int x, int y)
{
    for (; top[x] ^ top[y]; x = fa[top[x]])
        if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
    return dep[x] < dep[y] ? x : y;
}

void dfs3(int u)
{
    for (int i = hd[u], v = e[i].to; i; i = e[i].ne, v = e[i].to)
        if (v ^ fa[u]) dfs3(v), rt[u] = merge(rt[u], rt[v], 1, n << 1);
    ans[u] = query(rt[u], 1, n << 1, n + dep[u] - w[u]);
    if (w[u] and dep[u] + w[u] <= n)
        ans[u] += query(rt[u], 1, n << 1, n + dep[u] + w[u]);
}

int main()
{
    n = read(), m = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add(u, v), add(v, u);
    dfs1(1, 0), dfs2(1);
    for (int i = 1; i <= n; i++) w[i] = read();

    for (int i = 1; i <= m; i++)
    {
        int x = read(), y = read(), lca = LCA(x, y);
        update(rt[x], 1, n << 1, n + dep[x], 1);
        update(rt[y], 1, n << 1, n + dep[lca] * 2 - dep[x], 1);
        update(rt[lca], 1, n << 1, n + dep[x], -1);
        update(rt[fa[lca]], 1, n << 1, n + dep[lca] * 2 - dep[x], -1);
    }
    dfs3(1);
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}
