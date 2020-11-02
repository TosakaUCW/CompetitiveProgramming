#include <stdio.h>
#include <algorithm>
#include <iostream>

const int N = 1e5 + 5;
const int M = N << 1;

int n, m;
int head[N], num_edge;
int dfn[N], idx[N], top[N], size[N], depth[N], son[N], fa[N];

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
#define mid ((l + r) / 2)
    int max[N << 2], tag[N << 2];
    void push_up(int p) { max[p] = depth[max[ls]] < depth[max[rs]] ? max[ls] : max[rs]; }
    void push_down(int p)
    {
        if (!tag[p])
            return;
        int k = tag[p];
        tag[p] = 0;
        max[ls] = depth[k] > depth[max[ls]] ? k : max[ls];
        max[rs] = depth[k] > depth[max[rs]] ? k : max[rs];
        tag[ls] = depth[k] > depth[tag[ls]] ? k : max[ls];
        tag[rs] = depth[k] > depth[tag[rs]] ? k : max[rs];
    }
    void modify(int p, int l, int r, int x, int y, int k)
    {
        // printf("[%d,%d] [%d,%d]\n", l, r, x, y);
        if (x == l and y == r)
        {
            max[p] = depth[k] > depth[max[p]] ? k : max[p];
            tag[p] = depth[k] > depth[tag[p]] ? k : tag[p];
            return;
        }
        push_down(p);
        if (depth[k] > depth[max[ls]] and x <= mid)
            modify(ls, l, mid, x, std::min(mid, y), k);
        if (depth[k] > depth[max[rs]] and mid < y)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y, k);
        push_up(p);
    }
    int query(int p, int l, int r, int x, int y)
    {
        if (x == l and y == r)
            return max[p];
        push_down(p);
        if (x <= mid)
            return query(ls, l, mid, x, std::min(mid, y));
        else
            return query(rs, mid + 1, r, std::max(mid + 1, x), y);
    }
} T;

int main()
{
    n = read(), m = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    dfs1(1, 0), dfs2(1), T.modify(1, 1, n, dfn[1], dfn[1] + size[1] - 1, 1);
    while (m--)
    {
        char opt;
        int x;
        std::cin >> opt >> x;
        if (opt == 'Q')
            printf("%d\n", T.query(1, 1, n, dfn[x], dfn[x]));
        else
            T.modify(1, 1, n, dfn[x], dfn[x] + size[x] - 1, x);
    }
    return 0;
}