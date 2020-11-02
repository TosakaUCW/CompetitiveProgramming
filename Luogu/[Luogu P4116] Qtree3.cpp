#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;
const int M = N << 1;
const int INF = 2147483647;

int n, m;
int head[N], num_edge;
int dfn[N], idx[N], top[N], son[N], fa[N], depth[N], size[N];

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
    if (son[u])
        dfs2(son[u]);
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa[u] and v != son[u])
            dfs2(v);
}

struct Segment_Tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
    int min[N << 2];
    void push_up(int p) { min[p] = std::min(min[ls], min[rs]); }
    void build(int p, int l, int r)
    {
        if (l == r)
        {
            min[p] = INF;
            return;
        }
        build(ls, l, mid), build(rs, mid + 1, r), push_up(p);
    }
    void modify(int p, int l, int r, int x, int y)
    {
        if (l == x and r == y)
        {
            min[p] = min[p] == INF ? l : INF;
            return;
        }
        if (x <= mid)
            modify(ls, l, mid, x, std::min(mid, y));
        if (mid < y)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y);
        push_up(p);
    }
    int query(int p, int l, int r, int x, int y)
    {
        if (x == l and r == y)
            return min[p];
        int res = INF;
        if (x <= mid)
            res = std::min(res, query(ls, l, mid, x, std::min(mid, y)));
        if (mid < y)
            res = std::min(res, query(rs, mid + 1, r, std::max(mid + 1, x), y));
        return res;
    }
} T;

int main()
{
    n = read(), m = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    dfs1(1, 0), dfs2(1), T.build(1, 1, n);
    for (int opt, x, y; m--;)
    {
        opt = read(), x = read();
        if (opt == 0)
            T.modify(1, 1, n, dfn[x], dfn[x]);
        else
        {
            int res = INF;
            for (y = 1; top[x] != top[y]; res = std::min(res, T.query(1, 1, n, dfn[top[x]], dfn[x])), x = fa[top[x]])
                if (dfn[top[x]] < dfn[top[y]])
                    std::swap(x, y);
            if (dfn[x] > dfn[y])
                std::swap(x, y);
            res = std::min(res, T.query(1, 1, n, dfn[x], dfn[y]));
            printf("%d\n", res == INF ? -1 : idx[res]);
        }
    }
    return 0;
}