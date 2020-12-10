#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;
const int M = N << 1;

int n, q;
int tmp[N], val[N], m;
int depth[N], fa[N], size[N], son[N], top[N];
int head[N], num_edge;

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

struct HJT_Tree
{
#define mid ((l + r) >> 1)
#define get(x) (x == 0 ? 0 : sum[x])
    int rt[N], L[N << 5], R[N << 5], sum[N << 5], nodecnt;
    int modify(int pre, int pos, int l = 1, int r = m)
    {
        int p = ++nodecnt;
        L[p] = L[pre], R[p] = R[pre], sum[p] = sum[pre];
        if (l == r)
            return sum[p]++, p;
        if (pos <= mid)
            L[p] = modify(L[pre], pos, l, mid);
        else
            R[p] = modify(R[pre], pos, mid + 1, r);
        return sum[p] = get(L[p]) + get(R[p]), p;
    }
    int query(int k, int a, int b, int c, int d, int l = 1, int r = m)
    {
        if (l == r)
            return l;
        int x = get(L[a]) + get(L[b]) - get(L[c]) - get(L[d]);
        if (x >= k)
            return query(k, L[a], L[b], L[c], L[d], l, mid);
        else
            return query(k - x, R[a], R[b], R[c], R[d], mid + 1, r);
    }
} T;

int rank(int x) { return std::lower_bound(tmp + 1, tmp + 1 + m, x) - tmp; }

void dfs1(int u, int fa)
{
    T.rt[u] = T.modify(T.rt[fa], rank(val[u])), depth[u] = depth[fa] + 1, size[u] = 1, ::fa[u] = fa;
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

int getans(int u, int v, int x, int k) { return tmp[T.query(k, T.rt[u], T.rt[v], T.rt[x], T.rt[fa[x]])]; }

int main()
{
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
        val[i] = tmp[i] = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    std::sort(tmp + 1, tmp + 1 + n), m = std::unique(tmp + 1, tmp + 1 + n) - tmp - 1;
    dfs1(1, 0), dfs2(1);
    for (int lastans = 0, u, v, k; q--;)
        u = read() ^ lastans, v = read(), k = read(), printf("%d\n", lastans = getans(u, v, lca(u, v), k));
    return 0;
}