#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;
const int M = N << 1;

int n, m, a[N];
int head[N], num_edge;
int dfn[N], idx[N], top[N], size[N], depth[N], fa[N], son[N];

struct Node
{
    int next, to, dis, from;
} edge[M];

void add_edge(int u, int v, int dis) { edge[++num_edge] = Node{head[u], v, dis, u}, head[u] = num_edge; }

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
            dfs1(v, u), size[u] += size[v], a[v] = edge[i].dis, son[u] = size[v] > size[son[u]] ? v : son[u];
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
    int max[N << 2];
    void push_up(int p) { max[p] = std::max(max[ls], max[rs]); }
    void build(int p, int l, int r)
    {
        if (l == r)
        {
            max[p] = a[idx[l]];
            return;
        }
        build(ls, l, mid), build(rs, mid + 1, r), push_up(p);
    }
    void modify(int p, int l, int r, int x, int y, int k)
    {
        if (l == x and r == y)
        {
            max[p] = k;
            return;
        }
        if (x <= mid)
            modify(ls, l, mid, x, std::min(mid, y), k);
        if (mid < y)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y, k);
        push_up(p);
    }
    int query(int p, int l, int r, int x, int y)
    {
        if (l == x and r == y)
            return max[p];
        int res = 0;
        if (x <= mid)
            res = std::max(res, query(ls, l, mid, x, std::min(mid, y)));
        if (mid < y)
            res = std::max(res, query(rs, mid + 1, r, std::max(x, mid + 1), y));
        return res;
    }
} T;

int query(int x, int y)
{
    int res = 0;
    for (; top[x] != top[y]; res = std::max(res, T.query(1, 1, n, dfn[top[x]], dfn[x])), x = fa[top[x]])
        if (dfn[top[x]] < dfn[top[y]])
            std::swap(x, y);
    if (dfn[x] > dfn[y])
        std::swap(x, y);
    res = std::max(res, T.query(1, 1, n, dfn[x] + 1, dfn[y]));
    return res;
}

int main()
{
    n = read();
    for (int i = 1, u, v, dis; i < n; i++)
        u = read(), v = read(), dis = read(), add_edge(u, v, dis), add_edge(v, u, dis);
    dfs1(1, 0), dfs2(1), T.build(1, 1, n);
    for (char opt[10]; 1;)
    {
        scanf("%s", opt + 1);
        if (opt[1] == 'D')
            break;
        int x = read(), y = read();
        if (opt[1] == 'C')
        {
            x <<= 1;
            if (depth[edge[x].from] > depth[edge[x].to])
                x = edge[x].from;
            else
                x = edge[x].to;
            T.modify(1, 1, n, dfn[x], dfn[x], y);
        }
        else
        {
            if (x == y)
                puts("0");
            else
                printf("%d\n", query(x, y));
        }
    }
    return 0;
}