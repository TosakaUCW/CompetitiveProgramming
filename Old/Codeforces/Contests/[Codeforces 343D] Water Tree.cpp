#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 5e5 + 5;
const int M = N << 1;

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
    int val[N << 2], tag[N << 2];
    void push_down(int p)
    {
        if (tag[p] != -1)
            val[ls] = val[rs] = tag[ls] = tag[rs] = tag[p], tag[p] = -1;
    }
    void modify(int p, int l, int r, int x, int y, int k)
    {
        if (l == x and r == y)
        {
            val[p] = tag[p] = k;
            return;
        }
        push_down(p);
        if (x <= mid)
            modify(ls, l, mid, x, std::min(mid, y), k);
        if (mid < y)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y, k);
    }
    int query(int p, int l, int r, int x)
    {
        if (l == x and r == x)
            return val[p];
        push_down(p);
        if (x <= mid)
            return query(ls, l, mid, x);
        else
            return query(rs, mid + 1, r, x);
    }
} T;

int main()
{
    n = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    dfs1(1, 0), dfs2(1);
    for (int i = 1; i <= n * 4; i++)
        T.tag[i] = -1;
    for (m = read(); m--;)
    {
        int opt = read(), x = read();
        if (opt == 1)
            T.modify(1, 1, n, dfn[x], dfn[x] + size[x] - 1, 1);
        else if (opt == 2)
        {
            for (; top[x] != 1; x = fa[top[x]])
                T.modify(1, 1, n, dfn[top[x]], dfn[x], 0);
            T.modify(1, 1, n, 1, dfn[x], 0);
        }
        else
            printf("%d\n", T.query(1, 1, n, dfn[x]));
    }
    return 0;
}