#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <iostream>

const int N = 1e5 + 5;
const int M = N << 1;

int n, a[N];
int head[N], num_edge;
int fa[N], son[N], top[N], size[N], depth[N], idx[N], dfn[N];

struct Node
{
    int next, to, dis;
} edge[M];

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
    ::fa[u] = fa, depth[u] = depth[fa] + 1, size[u] = 1;
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
            dfs1(v, u), a[v] = edge[i].dis, size[u] += size[v], son[u] = size[v] > size[son[u]] ? v : son[u];
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
#define mid ((l + r) / 2)
#define val(p) (val[p])
#define tag_cov(p) (cov[p])
#define tag_add(p) (add[p])
    int cov[N << 2], add[N << 2], val[N << 2];
    void push_up(int p) { val(p) = std::max(val(ls), val(rs)); }
    void push_down(int p, int l, int r)
    {
        if (tag_cov(p) >= 0)
        {
            val(ls) = val(rs) = tag_cov(ls) = tag_cov(rs) = tag_cov(p);
            tag_add(ls) = tag_add(rs) = 0;
            tag_cov(p) = -1;
        }
        if (tag_add(p))
        {
            val(ls) += tag_add(p);
            val(rs) += tag_add(p);
            tag_add(ls) += tag_add(p);
            tag_add(rs) += tag_add(p);
            tag_add(p) = 0;
        }
    }
    void build(int p, int l, int r)
    {
        tag_cov(p) = -1;
        if (l == r)
        {
            val(p) = a[idx[l]];
            return;
        }
        build(ls, l, mid), build(rs, mid + 1, r), push_up(p);
    }
    void modify_add(int p, int l, int r, int x, int y, int k)
    {
        if (x == l and r == y)
        {
            val(p) += k, tag_add(p) += k;
            return;
        }
        push_down(p, l, r);
        if (x <= mid)
            modify_add(ls, l, mid, x, std::min(mid, y), k);
        if (mid < y)
            modify_add(rs, mid + 1, r, std::max(mid + 1, x), y, k);
        push_up(p);
    }
    void modify_cov(int p, int l, int r, int x, int y, int k)
    {
        if (x == l and r == y)
        {
            val[p] = tag_cov(p) = k, tag_add(p) = 0;
            return;
        }
        push_down(p, l, r);
        if (x <= mid)
            modify_cov(ls, l, mid, x, std::min(mid, y), k);
        if (mid < y)
            modify_cov(rs, mid + 1, r, std::max(mid + 1, x), y, k);
        push_up(p);
    }
    int query(int p, int l, int r, int x, int y)
    {
        if (x == l and r == y)
            return val(p);
        push_down(p, l, r);
        int res = 0;
        if (x <= mid)
            res = std::max(res, query(ls, l, mid, x, std::min(mid, y)));
        if (mid < y)
            res = std::max(res, query(rs, mid + 1, r, std::max(mid + 1, x), y));
        return res;
    }
} T;

int main()
{
    n = read();
    for (int i = 1, u, v, dis; i < n; i++)
        u = read(), v = read(), dis = read(), add_edge(u, v, dis), add_edge(v, u, dis);
    dfs1(1, 0), dfs2(1), T.build(1, 1, n);
    while (1)
    {
        char opt[10];
        scanf("%s", opt);
        if (opt[1] == 't')
            break;
        else if (opt[1] == 'h')
        {
            int k = read(), w = read();
            int x = edge[k * 2].to, y = edge[k * 2 - 1].to;
            if (fa[y] == x)
                std::swap(x, y);
            T.modify_cov(1, 1, n, dfn[x], dfn[x], w);
        } // change
        else if (opt[1] == 'o')
        {
            int x = read(), y = read(), k = read();
            for (; top[x] != top[y]; T.modify_cov(1, 1, n, dfn[top[x]], dfn[x], k), x = fa[top[x]])
                if (dfn[top[x]] < dfn[top[y]])
                    std::swap(x, y);
            if (dfn[x] > dfn[y])
                std::swap(x, y);
            T.modify_cov(1, 1, n, dfn[x] + 1, dfn[y], k);
        } // cover
        else if (opt[1] == 'd')
        {
            int x = read(), y = read(), k = read();
            for (; top[x] != top[y]; T.modify_add(1, 1, n, dfn[top[x]], dfn[x], k), x = fa[top[x]])
                if (dfn[top[x]] < dfn[top[y]])
                    std::swap(x, y);
            if (dfn[x] > dfn[y])
                std::swap(x, y);
            T.modify_add(1, 1, n, dfn[x] + 1, dfn[y], k);
        } // add
        else
        {
            int x = read(), y = read(), res = 0;
            for (; top[x] != top[y]; res = std::max(res, T.query(1, 1, n, dfn[top[x]], dfn[x])), x = fa[top[x]])
                if (dfn[top[x]] < dfn[top[y]])
                    std::swap(x, y);
            if (dfn[x] > dfn[y])
                std::swap(x, y);
            res = std::max(res, T.query(1, 1, n, dfn[x] + 1, dfn[y]));
            printf("%d\n", res);
        } // max
    }
    return 0;
}