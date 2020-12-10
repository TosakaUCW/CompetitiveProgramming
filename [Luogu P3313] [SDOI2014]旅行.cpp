#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;
const int M = N << 1;

int n, m;
int head[N], num_edge;
int fa[N], son[N], top[N], dfn[N], idx[N], size[N], depth[N];
int w[N], c[N];
int T[N], node_cnt;

struct Node
{
    int next, to;
} edge[M];
struct Segment_tree_Node
{
    int lson, rson, val, sum;
#define mid ((l + r) >> 1)
#define ls(p) tree[p].lson
#define rs(p) tree[p].rson
#define val(p) tree[p].val
#define sum(p) tree[p].sum
} tree[N * 24];

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
        if ((v = edge[i].to) != son[u] and v != fa[u])
            dfs2(v);
}

void push_up(int p)
{
    val(p) = std::max(val(ls(p)), val(rs(p)));
    sum(p) = sum(ls(p)) + sum(rs(p));
}

void modify(int &p, int x, int l, int r, int k)
{
    if (!p)
        p = ++node_cnt;
    if (l == r)
    {
        val(p) = sum(p) = k;
        return;
    }
    if (x <= mid)
        modify(ls(p), x, l, mid, k);
    else
        modify(rs(p), x, mid + 1, r, k);
    push_up(p);
}

void remove(int &p, int x, int l, int r)
{
    if (!p)
        return;
    if (l == r)
    {
        val(p) = sum(p) = 0;
        return;
    }
    if (x <= mid)
        remove(ls(p), x, l, mid);
    else
        remove(rs(p), x, mid + 1, r);
    push_up(p);
}

int query_sum(int &p, int l, int r, int x, int y)
{
    if (!p)
        return 0;
    if (x <= l and r <= y)
        return sum(p);
    int res = 0;
    if (x <= mid)
        res += query_sum(ls(p), l, mid, x, y);
    if (mid < y)
        res += query_sum(rs(p), mid + 1, r, x, y);
    return res;
}

int query_max(int &p, int l, int r, int x, int y)
{
    if (!p)
        return 0;
    if (x <= l and r <= y)
        return val(p);
    int res = 0;
    if (x <= mid)
        res = std::max(res, query_max(ls(p), l, mid, x, y));
    if (mid < y)
        res = std::max(res, query_max(rs(p), mid + 1, r, x, y));
    return res;
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        w[i] = read(), c[i] = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    dfs1(1, 0), dfs2(1);
    for (int i = 1; i <= n; i++)
        modify(T[c[idx[i]]], i, 1, n, w[idx[i]]);
    for (char opt[5]; m--;)
    {
        // for (int i = 1; i <= n * 4; i++)
        //     printf("%d ", tree[i].sum);
        // puts("");
        scanf("%s", opt);
        if (opt[1] == 'C')
        {
            int x = read(), k = read();
            remove(T[c[x]], dfn[x], 1, n);
            c[x] = k;
            modify(T[c[x]], dfn[x], 1, n, w[x]);
        }
        else if (opt[1] == 'W')
        {
            int x = read(), k = read();
            remove(T[c[x]], dfn[x], 1, n);
            w[x] = k;
            modify(T[c[x]], dfn[x], 1, n, w[x]);
        }
        else if (opt[1] == 'S')
        {
            int x = read(), y = read(), k = c[x], res = 0;
            for (; top[x] != top[y]; res += query_sum(T[k], 1, n, dfn[top[x]], dfn[x]), x = fa[top[x]])
                if (dfn[top[x]] < dfn[top[y]])
                    std::swap(x, y);
            if (dfn[x] > dfn[y])
                std::swap(x, y);
            res += query_sum(T[k], 1, n, dfn[x], dfn[y]);
            printf("%d\n", res);
        }
        else
        {
            int x = read(), y = read(), k = c[x], res = 0;
            for (; top[x] != top[y]; res = std::max(res, query_max(T[k], 1, n, dfn[top[x]], dfn[x])), x = fa[top[x]])
                if (dfn[top[x]] < dfn[top[y]])
                    std::swap(x, y);
            if (dfn[x] > dfn[y])
                std::swap(x, y);
            res = std::max(res, query_max(T[k], 1, n, dfn[x], dfn[y]));
            printf("%d\n", res);
        }
    }
    return 0;
}