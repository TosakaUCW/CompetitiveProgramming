#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <math.h>

const int N = 1e5 + 5;
const int M = N << 1;

int n, m;
int a[N];
int head[N], num_edge;
int dfn[N], top[N], size[N], son[N], fa[N], idx[N], depth[N];

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
#define mid ((l + r) / 2)
    int sum[N << 2], tag[N << 2];
    void push_up(int p) { sum[p] = sum[ls] + sum[rs]; }
    void push_down(int p, int l, int r)
    {
        if (tag[p] == -1)
            return;
        tag[ls] = tag[rs] = tag[p];
        sum[ls] = (mid - l + 1) * tag[p];
        sum[rs] = (r - mid) * tag[p];
        tag[p] = -1;
    }
    void build(int p, int l, int r)
    {
        tag[p] = -1;
        if (l == r)
            return;
        build(ls, l, mid), build(rs, mid + 1, r), push_up(p);
    }
    void modify(int p, int l, int r, int x, int y, int k)
    {
        if (l == x and r == y)
        {
            tag[p] = k, sum[p] = (r - l + 1) * k;
            return;
        }
        push_down(p, l, r);
        if (x <= mid)
            modify(ls, l, mid, x, std::min(mid, y), k);
        if (mid < y)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y, k);
        push_up(p);
    }
} T;

int main()
{
    n = read();
    for (int i = 2, x; i <= n; i++)
        x = read() + 1, add_edge(x, i), add_edge(i, x);
    dfs1(1, 0), dfs2(1), T.build(1, 1, n);
    for (m = read(); m--;)
    {
        char opt[10];
        scanf("%s", opt);
        int x = read() + 1, ans = T.sum[1];
        if (opt[0] == 'i')
        {
            int y = 1;
            for (; top[x] != top[y]; T.modify(1, 1, n, dfn[top[x]], dfn[x], 1), x = fa[top[x]])
                if (dfn[top[x]] < dfn[top[y]])
                    std::swap(x, y);
            if (dfn[x] > dfn[y])
                std::swap(x, y);
            T.modify(1, 1, n, dfn[x], dfn[y], 1);
        }
        else
            T.modify(1, 1, n, dfn[x], dfn[x] + size[x] - 1, 0);
        ans = abs(ans - T.sum[1]);
        printf("%d\n", ans);
    }
    return 0;
}