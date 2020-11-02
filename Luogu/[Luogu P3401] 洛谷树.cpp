#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 3e4 + 5;
const int M = N << 1;

int n, q;
int a[N], b[N];
int head[N], num_edge;
int dfn[N], idx[N], top[N], fa[N], son[N], size[N], depth[N];

struct Node
{
    int next, to, dis;
} edge[M];
struct RES
{
    int x, y;
    RES friend operator+(RES a, RES b) { return RES{a.x + b.x, a.y + b.y}; }
};

void add_edge(int u, int v, int dis) { edge[++num_edge] = Node{head[u], v, dis}, head[u] = num_edge; }

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
            a[v] = a[u] ^ edge[i].dis, b[v] = edge[i].dis, dfs1(v, u), size[u] += size[v], son[u] = size[v] > size[son[u]] ? v : son[u];
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
    int lazy[11][N << 2], sum[2][11][N << 2];
    void push_up(int k, int p) { sum[0][k][p] = sum[0][k][ls] + sum[0][k][rs], sum[1][k][p] = sum[1][k][ls] + sum[1][k][rs]; }
    void push_down(int k, int p)
    {
        if (lazy[k][p])
        {
            std::swap(sum[0][k][ls], sum[1][k][ls]);
            std::swap(sum[0][k][rs], sum[1][k][rs]);
            lazy[k][ls] ^= 1, lazy[k][rs] ^= 1;
            lazy[k][p] = 0;
        }
    }
    void build(int k, int p, int l, int r)
    {
        if (l == r)
        {
            sum[a[idx[l]] >> k & 1][k][p] = 1;
            return;
        }
        build(k, ls, l, mid), build(k, rs, mid + 1, r), push_up(k, p);
    }
    void modify(int k, int p, int l, int r, int x, int y)
    {
        if (x == l and r == y)
        {
            std::swap(sum[0][k][p], sum[1][k][p]);
            lazy[k][p] ^= 1;
            return;
        }
        push_down(k, p);
        if (x <= mid)
            modify(k, ls, l, mid, x, std::min(mid, y));
        if (mid < y)
            modify(k, rs, mid + 1, r, std::max(mid + 1, x), y);
        push_up(k, p);
    }
    RES query(int k, int p, int l, int r, int x, int y)
    {
        if (l == x and r == y)
            return RES{sum[0][k][p], sum[1][k][p]};
        push_down(k, p);
        RES res = {0, 0};
        if (x <= mid)
            res = res + query(k, ls, l, mid, x, std::min(mid, y));
        if (mid < y)
            res = res + query(k, rs, mid + 1, r, std::max(mid + 1, x), y);
        return res;
    }
} T;

void modify(int x, int w)
{
    for (int k = 0; k <= 10; k++)
        if ((w ^ b[x]) >> k & 1)
            T.modify(k, 1, 1, n, dfn[x], dfn[x] + size[x] - 1);
    b[x] = w;
}

int query(int u, int v)
{
    int ans = 0;
    for (int k = 0; k <= 10; k++)
    {
        int x = u, y = v;
        RES res = {0, 0};
        for (; top[x] != top[y]; x = fa[top[x]])
        {
            if (dfn[top[x]] < dfn[top[y]])
                std::swap(x, y);
            res = res + T.query(k, 1, 1, n, dfn[top[x]], dfn[x]);
        }
        if (dfn[x] > dfn[y])
            std::swap(x, y);
        res = res + T.query(k, 1, 1, n, dfn[x], dfn[y]);
        ans += (1 << k) * res.x * res.y;
    }
    return ans;
}

signed main()
{
    n = read(), q = read();
    for (int i = 1, u, v, dis; i < n; i++)
        u = read(), v = read(), dis = read(), add_edge(u, v, dis), add_edge(v, u, dis);
    dfs1(1, 0), dfs2(1);
    for (int i = 0; i <= 10; i++)
        T.build(i, 1, 1, n);
    while (q--)
    {
        int opt = read(), u = read(), v = read();
        if (opt == 1)
            printf("%lld\n", query(u, v));
        else
            modify(depth[u] < depth[v] ? v : u, read());
    }
    return 0;
}