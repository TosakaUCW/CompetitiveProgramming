#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;
const int M = N << 1;

int n, m, mm, nodecnt;
int root[N], ans[N];
int depth[N], size[N], son[N], fa[N], top[N];
int head[N], num_edge;
int ls[N * 80], rs[N * 80], max[N * 80], pos[N * 80];
int X[N], Y[N], Z[N], val[N];

struct Node
{
    int next, to;
} edge[M];

void add_edge(int u, int v) { edge[++num_edge] = Node{head[u], v}, head[u] = num_edge; }

void dfs1(int u, int fa)
{
    size[u] = 1, depth[u] = depth[fa] + 1, ::fa[u] = fa;
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

void push_up(int p)
{
    max[p] = std::max(max[ls[p]], max[rs[p]]);
    pos[p] = max[ls[p]] >= max[rs[p]] ? pos[ls[p]] : pos[rs[p]];
}

void insert(int p, int l, int r, int val, int delta)
{
    if (l == r)
        return max[p] += delta, pos[p] = max[p] ? l : 0, void();
    int mid = (l + r) >> 1;
    if (val <= mid)
        insert(ls[p] = ls[p] ? ls[p] : ++nodecnt, l, mid, val, delta);
    else
        insert(rs[p] = rs[p] ? rs[p] : ++nodecnt, mid + 1, r, val, delta);
    push_up(p);
}

int merge(int a, int b, int l, int r)
{
    if (!b)
        return a;
    if (!a)
        return b;
    if (l == r)
        return max[a] += max[b], pos[a] = max[a] ? l : 0, a;
    int mid = (l + r) >> 1;
    ls[a] = merge(ls[a], ls[b], l, mid);
    rs[a] = merge(rs[a], rs[b], mid + 1, r);
    return push_up(a), a;
}

void dfs3(int u)
{
    for (int i = head[u], v; i; i = edge[i].next)
        if (depth[v = edge[i].to] > depth[u])
            dfs3(v), root[u] = merge(root[u], root[v], 1, mm);
    ans[u] = pos[root[u]];
}

int main()
{
    n = read(), m = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    dfs1(1, 0), dfs2(1);
    for (int i = 1; i <= n; i++)
        root[i] = ++nodecnt;
    for (int i = 1; i <= m; i++)
        X[i] = read(), Y[i] = read(), val[i] = Z[i] = read();
    std::sort(val + 1, val + 1 + m);
    mm = std::unique(val + 1, val + 1 + m) - val - 1;
    for (int i = 1; i <= m; i++)
    {
        int x = X[i], y = Y[i], z = std::lower_bound(val + 1, val + 1 + mm, Z[i]) - val;
        int p = lca(x, y);
        insert(root[x], 1, mm, z, 1);
        insert(root[y], 1, mm, z, 1);
        insert(root[p], 1, mm, z, -1);
        if (fa[p])
            insert(root[fa[p]], 1, mm, z, -1);
    }
    dfs3(1);
    for (int i = 1; i <= n; i++)
        printf("%d\n", val[ans[i]]);
    return 0;
}