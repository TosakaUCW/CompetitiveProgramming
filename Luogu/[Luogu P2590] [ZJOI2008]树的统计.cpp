#include <stdio.h>
#include <algorithm>

#define ls (p << 1)
#define rs ((p << 1) | 1)

const int N = 2e5 + 5;
const int INF = 2147483647;

int n, m;
int head[N], num_egde;
int root, val[N];
int cnt, size[N], depth[N], fa[N], son[N], top[N], dfn[N], index[N];

struct Edge
{
    int next, to;
} edge[2 * N];
struct Node
{
    int l, r, val, max;
} tree[4 * N];

void add_edge(int u, int v)
{
    edge[++num_egde].next = head[u];
    edge[num_egde].to = v;
    head[u] = num_egde;
}

void dfs1(int u, int father)
{
    depth[u] = depth[father] + 1;
    fa[u] = father;
    size[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (fa[u] == v)
            continue;
        dfs1(v, u);
        size[u] += size[v];
        if (son[u] == 0 or size[v] > size[son[u]])
            son[u] = v;
    }
}

void dfs2(int u, int t)
{
    top[u] = t;
    dfn[u] = ++cnt;
    index[cnt] = u;
    if (son[u] == 0)
    {
        return;
    }
    dfs2(son[u], t);
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (fa[u] == v or son[u] == v)
            continue;
        dfs2(v, v);
    }
}

void build(int p, int l, int r)
{
    tree[p].l = l, tree[p].r = r;
    if (l == r)
        tree[p].val = val[index[l]], tree[p].max = val[index[l]];
    else
    {
        int mid = (l + r) / 2;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        tree[p].val = tree[ls].val + tree[rs].val;
        tree[p].max = std::max(tree[ls].max, tree[rs].max);
    }
}

void update(int p, int x, int k)
{
    if (tree[p].l == tree[p].r)
    {
        tree[p].val = tree[p].max = k;
    }
    else
    {
        int mid = (tree[p].l + tree[p].r) / 2;
        if (x <= mid)
            update(ls, x, k);
        else
            update(rs, x, k);
        tree[p].val = tree[ls].val + tree[rs].val;
        tree[p].max = std::max(tree[ls].max, tree[rs].max);
    }
}

long long query_sum(int p, int x, int y)
{
    if (x <= tree[p].l and tree[p].r <= y)
        return tree[p].val;
    if (tree[p].r < x or y < tree[p].l)
        return 0;
    return query_sum(ls, x, y) + query_sum(rs, x, y);
}

long long query_max(int p, int x, int y)
{
    if (x <= tree[p].l and tree[p].r <= y)
        return tree[p].max;
    if (tree[p].r < x or y < tree[p].l)
        return -INF;
    return std::max(query_max(ls, x, y), query_max(rs, x, y));
}

long long qsum(int x, int y)
{
    long long ans = 0;
    int fx = top[x], fy = top[y];
    while (fx != fy)
    {
        if (depth[fx] >= depth[fy])
        {
            ans += query_sum(1, dfn[fx], dfn[x]);
            x = fa[fx];
        }
        else
        {
            ans += query_sum(1, dfn[fy], dfn[y]);
            y = fa[fy];
        }
        fx = top[x], fy = top[y];
    }
    if (dfn[x] <= dfn[y])
        ans += query_sum(1, dfn[x], dfn[y]);
    else
        ans += query_sum(1, dfn[y], dfn[x]);
    return ans;
}

long long qmax(int x, int y)
{
    long long ans = -INF;
    int fx = top[x], fy = top[y];
    while (fx != fy)
    {
        if (depth[fx] >= depth[fy])
        {
            ans = std::max(ans, query_max(1, dfn[fx], dfn[x]));
            x = fa[fx];
        }
        else
        {
            ans = std::max(ans, query_max(1, dfn[fy], dfn[y]));
            y = fa[fy];
        }
        fx = top[x], fy = top[y];
    }
    if (dfn[x] <= dfn[y])
        ans = std::max(ans, query_max(1, dfn[x], dfn[y]));
    else
        ans = std::max(ans, query_max(1, dfn[y], dfn[x]));
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &val[i]);
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    scanf("%d", &m);
    while (m--)
    {
        int x, y;
        char opt[10];
        scanf("%s%d%d", opt, &x, &y);
        if (opt[1] == 'M')
            printf("%lld\n", qmax(x, y));
        else if (opt[1] == 'S')
            printf("%lld\n", qsum(x, y));
        else
            update(1, dfn[x], y);
    }
    return 0;
}