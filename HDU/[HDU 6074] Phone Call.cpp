#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 1e5 + 5;
const int M = N << 1;

int n, m;
int head[N], num_edge;
int fa[N], son[N], top[N], depth[N], size[N];
int f[N], g[N], w;
int cnt[N], cost[N];

// f : i 点往上深度最大的一个可能不是和 i 在同一个连通块的祖先
// g : 并查集

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

struct Node
{
    int next, to;
} edge[M];
struct Line
{
    int a, b, c, d, w;
    void input() { a = read(), b = read(), c = read(), d = read(), w = read(); }
    bool friend operator<(Line a, Line b) { return a.w < b.w; }
} e[N];

void add_edge(int u, int v) { edge[++num_edge] = Node{head[u], v}, head[u] = num_edge; }

void dfs1(int u, int fa)
{
    ::fa[u] = fa, size[u] = 1, depth[u] = depth[fa] + 1;
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
            dfs1(v, u), size[u] += size[v], son[u] = size[v] > size[son[u]] ? v : son[u];
}

void dfs2(int u)
{
    top[u] = u == son[fa[u]] ? top[fa[u]] : u;
    if (son[u])
        dfs2(son[u]);
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa[u] and v != son[u])
            dfs2(v);
}

int lca(int x, int y)
{
    for (; top[x] != top[y]; x = fa[top[x]])
        if (depth[top[x]] < depth[top[y]])
            std::swap(x, y);
    return depth[x] < depth[y] ? x : y;
}

int f_find(int x) { return x == f[x] ? x : f[x] = f_find(f[x]); }

int g_find(int x) { return x == g[x] ? x : g[x] = g_find(g[x]); }

void merge(int x, int y)
{
    x = g_find(x), y = g_find(y);
    if (x != y)
        g[x] = y, cnt[y] += cnt[x], cost[y] += cost[x] + w;
}

void go(int x, int y)
{
    for (x = f_find(x); depth[x] > depth[y]; x = f_find(x))
        merge(x, fa[x]), f[x] = fa[x];
}

void chain(int x, int y)
{
    int z = lca(x, y);
    go(x, z), go(y, z);
}

signed main()
{
    for (int T = read(); T--;)
    {
        num_edge = 0;
        memset(head, 0, sizeof head);
        memset(edge, 0, sizeof edge);
        n = read(), m = read();
        for (int i = 1, u, v; i < n; i++)
            u = read(), v = read(), add_edge(u, v), add_edge(v, u);
        dfs1(1, 0), dfs2(1);
        for (int i = 1; i <= n; i++)
            f[i] = g[i] = i, cnt[i] = 1, cost[i] = 0;
        for (int i = 1; i <= m; i++)
            e[i].input();
        std::sort(e + 1, e + 1 + m);
        for (int i = 1; i <= m; i++)
        {
            w = e[i].w;
            chain(e[i].a, e[i].b);
            chain(e[i].c, e[i].d);
            merge(e[i].a, e[i].c);
        }
        printf("%lld %lld\n", cnt[g_find(1)], cost[g_find(1)]);
    }
    return 0;
}