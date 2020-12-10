#include <stdio.h>
#include <algorithm>

#define ls (p << 1)
#define rs ((p << 1) | 1)

const int N = 2e5 + 5;

int n, m;
int head[N], num_egde;
int val[N];
int cnt, size[N], depth[N], fa[N], son[N], top[N], dfn[N], index[N];

struct Edge
{
    int next, to;
} edge[2 * N];
struct Node
{
    int l, r, val, lazy, max;
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
        if (v == fa[u])
            continue;
        dfs1(v, u);
        size[u] += size[v];
        if (size[v] > size[son[u]])
            son[u] = v;
    }
}

void dfs2(int u, int t)
{
    top[u] = t;
    dfn[u] = ++cnt;
    index[cnt] = u;
    if (son[u] == 0)
        return;
    dfs2(son[u], t);
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa[u] or v == son[u])
            continue;
        dfs2(v, v);
    }
}

void build(int p, int l, int r)
{
    tree[p].l = l, tree[p].r = r;
    if (l == r)
        tree[p].val = tree[p].max = 0;
    else
    {
        int mid = (l + r) / 2;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        tree[p].val = tree[ls].val + tree[rs].val;
        tree[p].max = std::max(tree[ls].max, tree[rs].max);
    }
}

void push_down(int p)
{
    tree[ls].val += tree[p].lazy * (tree[ls].r - tree[ls].l + 1);
    tree[rs].val += tree[p].lazy * (tree[rs].r - tree[rs].l + 1);
    tree[ls].max += tree[p].lazy;
    tree[rs].max += tree[p].lazy;
    tree[ls].lazy += tree[p].lazy;
    tree[rs].lazy += tree[p].lazy;
    tree[p].lazy = 0;
}

void update(int p, int x, int y, int k)
{
    if (tree[p].l > y or tree[p].r < x)
        return;
    if (x <= tree[p].l and tree[p].r <= y)
    {
        tree[p].val += (tree[p].r - tree[p].l + 1) * k;
        tree[p].max += k;
        tree[p].lazy += k;
    }
    else
    {
        if (tree[p].lazy)
            push_down(p);
        update(ls, x, y, k);
        update(rs, x, y, k);
        tree[p].val = tree[ls].val + tree[rs].val;
        tree[p].max = std::max(tree[ls].max, tree[rs].max);
    }
}

long long query(int p, int x, int y)
{
    if (x <= tree[p].l and tree[p].r <= y)
        return tree[p].max;
    if (tree[p].r < x or y < tree[p].l)
        return 0;
    if (tree[p].lazy)
        push_down(p);
    return std::max(query(ls, x, y), query(rs, x, y));
}

void update_path(int x, int y, int k)
{
    while (top[x] != top[y])
    {
        if (depth[top[x]] < depth[top[y]])
            std::swap(x, y);
        update(1, dfn[top[x]], dfn[x], k);
        x = fa[top[x]];
    }
    if (depth[x] > depth[y])
        std::swap(x, y);
    update(1, dfn[x], dfn[y], k);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        update_path(u, v, 1);
    }
    printf("%lld", query(1, 1, n));
    return 0;
}