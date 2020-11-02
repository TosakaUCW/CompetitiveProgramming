#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>

const int N = 1e6 + 5;
const int M = N << 1;

int n, m;
int head[N], num_edge;

int fa[N], son[N], size[N], depth[N], dfn[N], idx[N], top[N];

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
    ::fa[u] = fa, depth[u] = depth[fa] + 1, size[u] = 1;
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
            dfs1(v, u), size[u] += size[v], son[u] = size[v] > size[son[u]] ? v : son[u];
}

void dfs2(int u)
{
    dfn[u] = ++dfn[0], idx[dfn[u]] = u, top[u] = u == son[fa[u]] ? top[fa[u]] : u;
    if (!son[u])
        return;
    dfs2(son[u]);
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa[u] and v != son[u])
            dfs2(v);
}

struct Segment_Tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
    int tag[N << 2], sum[N << 2];
    void push_up(int p) { sum[p] = sum[ls] + sum[rs]; }
    void push_down(int p, int l, int r)
    {
        if (!tag[p])
            return;
        int mid = (l + r) >> 1;
        sum[ls] += tag[p] * (mid - l + 1), sum[rs] += tag[p] * (r - mid);
        tag[ls] += tag[p], tag[rs] += tag[p], tag[p] = 0;
    }
    void build(int p, int l, int r)
    {
        if (l == r)
        {
            sum[l] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(ls, l, mid), build(rs, mid + 1, r), push_up(p);
    }
    void modify(int p, int l, int r, int x, int y, int k)
    {
        if (x <= l and r <= y)
        {
            sum[p] += (r - l + 1) * k, tag[p] += k;
            return;
        }
        push_down(p, l, r);
        int mid = (l + r) >> 1;
        if (x <= mid)
            modify(ls, l, mid, x, std::min(mid, y), k);
        if (mid < y)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y, k);
        push_up(p);
    }
    int query(int p, int l, int r, int x, int y)
    {
        if (x <= l and r <= y)
            return sum[p];
        push_down(p, l, r);
        int res = 0, mid = (l + r) >> 1;
        if (x <= mid)
            res += query(ls, l, mid, x, std::min(mid, y));
        if (mid < y)
            res += query(rs, mid + 1, r, std::max(mid + 1, x), y);
        return res;
    }
} T;

void modify(int x, int y)
{
    for (; top[x] != top[y]; T.modify(1, 1, n, dfn[top[x]], dfn[x], 1), x = fa[top[x]])
        if (depth[top[x]] < depth[top[y]])
            std::swap(x, y);
    if (x == y)
        return;
    if (depth[x] < depth[y])
        std::swap(x, y);
    T.modify(1, 1, n, dfn[y] + 1, dfn[x], 1);
}

int main()
{
    n = read(), m = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    dfs1(1, 0), dfs2(1), T.build(1, 1, n);
    while (m--)
    {
        char opt;
        int x, y;
        std::cin >> opt >> x >> y;
        if (opt == 'P')
            modify(x, y);
        else
            printf("%d\n", T.query(1, 1, n, dfn[fa[x] == y ? x : y], dfn[fa[x] == y ? x : y]));
    }
    return 0;
}