#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;
const int M = N << 1;
const int INF = 2147483647;

int n, m;
int head[N], num_edge;
int dfn[N], idx[N], top[N], son[N], fa[N], size[N], depth[N];

struct Node
{
    int next, to, from;
} edge[M];

void add_edge(int u, int v) { edge[++num_edge] = Node{head[u], v, u}, head[u] = num_edge; }

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
    ::fa[u] = fa, depth[u] = depth[fa] + 1, size[u] = 1;
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
#define mid ((l + r) / 2)
    int min[N << 2], tag[N << 2];
    void push_up(int p) { min[p] = std::min(min[ls], min[rs]); }
    void push_down(int p)
    {
        tag[ls] = std::min(tag[ls], tag[p]);
        tag[rs] = std::min(tag[rs], tag[p]);
        min[ls] = std::min(min[ls], tag[p]);
        min[rs] = std::min(min[rs], tag[p]);
        tag[p] = INF;
    }
    void build(int p, int l, int r)
    {
        min[p] = tag[p] = INF;
        if (l == r)
            return;
        build(ls, l, mid), build(rs, mid + 1, r), push_up(p);
    }
    void modify(int p, int l, int r, int x, int y, int k)
    {
        if (x == l and r == y)
        {
            min[p] = std::min(min[p], k);
            tag[p] = std::min(tag[p], k);
            return;
        }
        push_down(p);
        if (x <= mid)
            modify(ls, l, mid, x, std::min(mid, y), k);
        if (mid < y)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y, k);
        push_up(p);
    }
    int query(int p, int l, int r, int x, int y)
    {
        if (x == l and r == y)
            return min[p];
        int res = INF;
        push_down(p);
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
    for (int x, y, k; m--;)
    {
        x = read(), y = read(), k = read();
        for (; top[x] != top[y]; T.modify(1, 1, n, dfn[top[x]], dfn[x], k), x = fa[top[x]])
            if (dfn[top[x]] < dfn[top[y]])
                std::swap(x, y);
        if (dfn[x] > dfn[y])
            std::swap(x, y);
        T.modify(1, 1, n, dfn[x] + 1, dfn[y], k);
    }
    for (int i = 1; i <= 2 * n - 2; i += 2)
    {
        int res = INF, x = edge[i].from, y = edge[i].to;
        // printf("%d %d\n", x, y);
        for (; top[x] != top[y]; res = std::min(res, T.query(1, 1, n, dfn[top[x]], dfn[x])), x = fa[top[x]])
            if (dfn[top[x]] < dfn[top[y]])
                std::swap(x, y);
        if (dfn[x] > dfn[y])
            std::swap(x, y);
        res = std::min(res, T.query(1, 1, n, dfn[x] + 1, dfn[y]));
        printf("%d\n", res == INF ? -1 : res);
    }
    return 0;
}