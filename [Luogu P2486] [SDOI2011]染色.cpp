#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;
const int M = N << 1;

int n, m, a[N];
int head[N], num_edge;
int dfn[N], idx[N], top[N], size[N], son[N], fa[N], depth[N];
int LC, RC;

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
#define tag(p) (t[p].tag)
#define lc(p) (t[p].lc)
#define rc(p) (t[p].rc)
#define sum(p) (t[p].sum)
    struct node
    {
        int l, r, sum, tag, lc, rc;
    } t[N << 2];
    void push_up(int p)
    {
        lc(p) = lc(ls);
        rc(p) = rc(rs);
        sum(p) = sum(ls) + sum(rs);
        if (rc(ls) == lc(rs))
            sum(p)--;
    }
    void push_down(int p)
    {
        if (tag(p))
        {
            tag(ls) = tag(rs) = tag(p);
            sum(ls) = sum(rs) = 1;
            lc(ls) = rc(ls) = lc(rs) = rc(rs) = lc(p);
            tag(p) = 0;
        }
    }
    void build(int p, int l, int r)
    {
        t[p].l = l, t[p].r = r, t[p].sum = t[p].tag = 0;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(ls, l, mid), build(rs, mid + 1, r);
    }
    void modify(int p, int l, int r, int k)
    {
        if (t[p].l == l and t[p].r == r)
        {
            t[p].sum = t[p].tag = 1;
            lc(p) = rc(p) = k;
            return;
        }
        push_down(p);
        int mid = (t[p].l + t[p].r) >> 1;
        if (r <= mid)
            modify(ls, l, r, k);
        else if (l > mid)
            modify(rs, l, r, k);
        else
            modify(ls, l, mid, k), modify(rs, mid + 1, r, k);
        push_up(p);
    }
    int query(int p, int l, int r, int L, int R)
    {
        if (t[p].l == L)
            LC = lc(p);
        if (t[p].r == R)
            RC = rc(p);
        if (t[p].l == l and t[p].r == r)
            return sum(p);
        push_down(p);
        int mid = (t[p].l + t[p].r) >> 1;
        if (r <= mid)
            return query(ls, l, r, L, R);
        if (l > mid)
            return query(rs, l, r, L, R);
        else
        {
            int res = query(ls, l, mid, L, R) + query(rs, mid + 1, r, L, R);
            if (rc(ls) == lc(rs))
                res--;
            return res;
        }
        push_up(p);
    }
} T;

int query(int x, int y)
{
    int res = 0, s1 = -1, s2 = -1;
    for (; top[x] != top[y]; x = fa[top[x]])
    {
        if (dfn[top[x]] < dfn[top[y]])
            std::swap(x, y), std::swap(s1, s2);
        res += T.query(1, dfn[top[x]], dfn[x], dfn[top[x]], dfn[x]);
        if (RC == s1)
            res--;
        s1 = LC;
    }
    if (dfn[x] < dfn[y])
        std::swap(x, y), std::swap(s1, s2);
    res += T.query(1, dfn[y], dfn[x], dfn[y], dfn[x]);
    if (LC == s2)
        res--;
    if (RC == s1)
        res--;
    return res;
}

void modify(int x, int y, int k)
{
    for (; top[x] != top[y]; T.modify(1, dfn[top[x]], dfn[x], k), x = fa[top[x]])
        if (dfn[top[x]] < dfn[top[y]])
            std::swap(x, y);
    if (dfn[x] > dfn[y])
        std::swap(x, y);
    T.modify(1, dfn[x], dfn[y], k);
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    dfs1(1, 0), dfs2(1), T.build(1, 1, n);
    for (int i = 1; i <= n; i++)
        T.modify(1, dfn[i], dfn[i], a[i]);
    for (char opt; m--;)
    {
        std::cin >> opt;
        if (opt == 'Q')
        {
            int x = read(), y = read();
            printf("%d\n", query(x, y));
        }
        else
        {
            int x = read(), y = read(), k = read();
            modify(x, y, k);
        }
    }
    return 0;
}