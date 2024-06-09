#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 3e5 + 5;
const int M = N << 1;

int n, q;
int head[N], num_edge, max_depth;
int size[N], depth[N], dfn[N], idx[N];

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
    int nodecnt, rt[N << 5], L[N << 5], R[N << 5], val[N << 5];
    void modify(int &p, int pre, int l, int r, int pos, int x)
    {
        p = ++nodecnt;
        L[p] = L[pre], R[p] = R[pre], val[p] = val[pre] + x;
        if (l < r)
        {
            if (pos <= mid)
                modify(L[p], L[pre], l, mid, pos, x);
            else
                modify(R[p], R[pre], mid + 1, r, pos, x);
        }
    }
    int query(int u, int v, int l, int r, int x, int y)
    {
        if (l == x and r == y)
            return val[v] - val[u];
        int res = 0;
        if (x <= mid)
            res += query(L[u], L[v], l, mid, x, std::min(mid, y));
        if (mid < y)
            res += query(R[u], R[v], mid + 1, r, std::max(mid + 1, x), y);
        return res;
    }
} T;

void dfs1(int u, int fa)
{
    size[u] = 1, depth[u] = depth[fa] + 1, max_depth = std::max(max_depth, depth[u]), dfn[u] = ++dfn[0], idx[dfn[u]] = u;
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
            dfs1(v, u), size[u] += size[v];
}

signed main()
{
    n = read(), q = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    dfs1(1, 0);
    for (int i = 1; i <= n; i++)
        T.modify(T.rt[dfn[idx[i]]], T.rt[dfn[idx[i]] - 1], 1, max_depth, depth[idx[i]], size[idx[i]] - 1);
    for (int res; q--; printf("%lld\n", res))
    {
        int a = read(), k = read();
        res = std::min(k, depth[a] - 1) * (size[a] - 1);
        int l = dfn[a] + 1, r = dfn[a] + size[a] - 1;
        res += T.query(T.rt[l - 1], T.rt[r], 1, max_depth, depth[a] + 1, std::min(max_depth, depth[a] + k));
    }
    return 0;
}