#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>

const int N = 3e5 + 5;
const int M = N << 1;

int n, m;
int head[N], num_edge;
int dfn[N], idx[N], top[N], son[N], fa[N], size[N], depth[N];
int a[2][N], cnt;

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
#define mid ((l + r) >> 1)
    int max[N << 2], tag[N << 2];
    void push_up(int p) { max[p] = std::max(max[ls], max[rs]); }
    void push_down(int p)
    {
        if (tag[p])
        {
            max[ls] = max[rs] = max[p];
            tag[ls] = tag[rs] = tag[p];
            tag[p] = 0;
        }
    }
    void modify(int p, int l, int r, int x, int y, int k)
    {
        if (x == l and r == y)
        {
            max[p] = tag[p] = k;
            return;
        }
        push_down(p);
        if (x <= mid)
            modify(ls, l, mid, x, std::min(mid, y), k);
        if (mid < y)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y, k);
        push_up(p);
    }
    int query(int p, int l, int r, int x, int y)
    {
        if (x == l and r == y)
            return max[p];
        int res = 0;
        push_down(p);
        if (x <= mid)
            res = std::max(res, query(ls, l, mid, x, std::min(mid, y)));
        if (mid < y)
            res = std::max(res, query(rs, mid + 1, r, std::max(mid + 1, x), y));
        return res;
    }
} T;

int main()
{
    n = read(), m = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    dfs1(1, 0), dfs2(1);
    for (char opt; m--;)
    {
        std::cin >> opt;
        if (opt == 'Q')
        {
            int res = 0, x = read(), y = read();
            for (; top[x] != top[y]; res = std::max(res, T.query(1, 1, n, dfn[top[x]], dfn[x])), x = fa[top[x]])
                if (dfn[top[x]] < dfn[top[y]])
                    std::swap(x, y);
            if (dfn[x] > dfn[y])
                std::swap(x, y);
            res = std::max(res, T.query(1, 1, n, dfn[x] + 1, dfn[y]));
            if (res)
                puts("No");
            else
                puts("Yes");
        }
        else if (opt == 'C')
        {
            a[0][++cnt] = read(), a[1][cnt] = read();
            if (a[0][cnt] < a[1][cnt])
                std::swap(a[0][cnt], a[1][cnt]);
            T.modify(1, 1, n, dfn[a[0][cnt]], dfn[a[0][cnt]], 1);
        }
        else
        {
            int x = read();
            T.modify(1, 1, n, dfn[a[0][x]], dfn[a[0][x]], 0);
        }
    }
    return 0;
}