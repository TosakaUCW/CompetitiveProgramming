#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;
const int M = N << 1;

int n, m;
int a[N];
int head[N], num_edge;
int dfn[N], idx[N], size[N], depth[N], fa[N], son[N], top[N];

struct Node
{
    int next, to;
} edge[M];

void add_edge(int u, int v) { edge[++num_edge] = Node{head[u], v}, head[u] = num_edge; }

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

void dfs1(int u, int fa)
{
    ::fa[u] = fa, size[u] = 1, depth[u] = depth[fa] + 1;
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
            dfs1(v, u), size[u] += size[v], son[u] = size[v] > size[son[u]] ? v : son[u];
}

void dfs2(int u)
{
    dfn[u] = ++dfn[0], idx[dfn[u]] = u, top[u] = u == son[fa[u]] ? top[fa[u]] : u;
    if (!son[u])
        return;
    dfs2(son[u]);
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa[u] and v != son[u])
            dfs2(v);
}

struct Segment_Tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) / 2)
    int sum[N << 2], tag[N << 2];
    void push_up(int p) { sum[p] = sum[ls] ^ sum[rs]; }
    void build(int p, int l, int r)
    {
        if (l == r)
        {
            sum[p] = a[idx[l]];
            return;
        }
        build(ls, l, mid), build(rs, mid + 1, r), push_up(p);
    }
    void update(int p, int l, int r, int x, int y, int k)
    {
        if (x == l and r == y)
        {
            sum[p] = k;
            return;
        }
        if (x <= mid)
            update(ls, l, mid, x, std::min(mid, y), k);
        if (mid < y)
            update(rs, mid + 1, r, std::max(mid + 1, x), y, k);
        push_up(p);
    }
    int query(int p, int l, int r, int x, int y)
    {
        if (x == l and r == y)
            return sum[p];
        int res = 0;
        if (x <= mid)
            res ^= query(ls, l, mid, x, std::min(mid, y));
        if (mid < y)
            res ^= query(rs, mid + 1, r, std::max(mid + 1, x), y);
        return res;
    }
} T;

int query(int x, int y)
{
    int res = 0;
    for (; top[x] != top[y]; res ^= T.query(1, 1, n, dfn[top[x]], dfn[x]), x = fa[top[x]])
        if (depth[top[x]] < depth[top[y]])
            std::swap(x, y);
    if (depth[x] > depth[y])
        std::swap(x, y);
    res ^= T.query(1, 1, n, dfn[x], dfn[y]);
    return res;
}

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    dfs1(1, 0), dfs2(1), T.build(1, 1, n);
    for (int opt, x, y; m--;)
    {
        opt = read(), x = read(), y = read();
        if (opt == 1)
            T.update(1, 1, n, dfn[x], dfn[x], y);
        else
            printf("%d\n", query(x, y));
    }
    return 0;
}