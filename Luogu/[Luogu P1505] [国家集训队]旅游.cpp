#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e6 + 5;
const int M = N << 1;
const int INF = 2147483647;

int n, m, a[N];
int head[N], num_edge;
int dfn[N], idx[N], top[N], fa[N], son[N], depth[N], size[N];

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
    ::fa[u] = fa, size[u] = 1, depth[u] = depth[fa] + 1;
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
            dfs1(v, u), size[u] += size[v], son[u] = size[v] > size[son[u]] ? v : son[u], a[v] = edge[i].dis;
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
    int max[N], min[N], sum[N], tag[N];
    void push_up(int p)
    {
        sum[p] = sum[ls] + sum[rs];
        max[p] = std::max(max[ls], max[rs]);
        min[p] = std::min(min[ls], min[rs]);
    }
    void push_down(int p)
    {
        if (tag[p])
        {
            sum[ls] = -sum[ls], sum[rs] = -sum[rs];
            int lmax = max[ls], lmin = min[ls], rmax = max[rs], rmin = min[rs];
            max[ls] = -lmin, min[ls] = -lmax, max[rs] = -rmin, min[rs] = -rmax;
            tag[ls] ^= 1, tag[rs] ^= 1;
            tag[p] = 0;
        }
    }
    void build(int p, int l, int r)
    {
        if (l == r)
        {
            sum[p] = max[p] = min[p] = a[idx[l]];
            return;
        }
        build(ls, l, mid), build(rs, mid + 1, r), push_up(p);
    }
    void modify_cover(int p, int l, int r, int x, int y, int k)
    {
        if (x == l and r == y)
        {
            sum[p] = max[p] = min[p] = k;
            return;
        }
        push_down(p);
        if (x <= mid)
            modify_cover(ls, l, mid, x, std::min(mid, y), k);
        if (mid < y)
            modify_cover(rs, mid + 1, r, std::max(mid + 1, x), y, k);
        push_up(p);
    }
    void modify_reverse(int p, int l, int r, int x, int y)
    {
        if (x == l and r == y)
        {
            tag[p] ^= 1;
            sum[p] = -sum[p];
            int pmax = max[p], pmin = min[p];
            max[p] = -pmin, min[p] = -pmax;
            return;
        }
        push_down(p);
        if (x <= mid)
            modify_reverse(ls, l, mid, x, std::min(mid, y));
        if (mid < y)
            modify_reverse(rs, mid + 1, r, std::max(mid + 1, x), y);
        push_up(p);
    }
    int query_sum(int p, int l, int r, int x, int y)
    {
        if (x == l and r == y)
            return sum[p];
        push_down(p);
        int res = 0;
        if (x <= mid)
            res += query_sum(ls, l, mid, x, std::min(mid, y));
        if (mid < y)
            res += query_sum(rs, mid + 1, r, std::max(mid + 1, x), y);
        return res;
    }
    int query_max(int p, int l, int r, int x, int y)
    {
        if (x == l and r == y)
            return max[p];
        push_down(p);
        int res = -INF;
        if (x <= mid)
            res = std::max(res, query_max(ls, l, mid, x, std::min(mid, y)));
        if (mid < y)
            res = std::max(res, query_max(rs, mid + 1, r, std::max(mid + 1, x), y));
        return res;
    }
    int query_min(int p, int l, int r, int x, int y)
    {
        if (x == l and r == y)
            return min[p];
        push_down(p);
        int res = INF;
        if (x <= mid)
            res = std::min(res, query_min(ls, l, mid, x, std::min(mid, y)));
        if (mid < y)
            res = std::min(res, query_min(rs, mid + 1, r, std::max(mid + 1, x), y));
        return res;
    }
} T;

int main()
{
    n = read();
    for (int i = 1, u, v, dis; i < n; i++)
        u = read() + 1, v = read() + 1, dis = read(), add_edge(u, v, dis), add_edge(v, u, dis);
    dfs1(1, 0), dfs2(1), T.build(1, 1, n), m = read();
    for (char opt[10]; m--;)
    {
        // printf("segment:");
        // for (int i = 1; i <= n * 4; i++)
        //     printf("%d ", T.sum[i]);
        // puts("");
        scanf("%s", opt + 1);
        if (opt[1] == 'C')
        {
            int x = read(), k = read();
            if (depth[edge[2 * x].to] > depth[edge[2 * x - 1].to])
                x = edge[2 * x].to;
            else
                x = edge[2 * x - 1].to;
            T.modify_cover(1, 1, n, dfn[x], dfn[x], k);
        }
        else if (opt[1] == 'N')
        {
            int x = read() + 1, y = read() + 1;
            for (; top[x] != top[y]; T.modify_reverse(1, 1, n, dfn[top[x]], dfn[x]), x = fa[top[x]])
                if (dfn[top[x]] < dfn[top[y]])
                    std::swap(x, y);
            if (dfn[x] > dfn[y])
                std::swap(x, y);
            T.modify_reverse(1, 1, n, dfn[x] + 1, dfn[y]);
        }
        else if (opt[1] == 'S')
        {
            int x = read() + 1, y = read() + 1, res = 0;
            for (; top[x] != top[y]; res += T.query_sum(1, 1, n, dfn[top[x]], dfn[x]), x = fa[top[x]])
                if (dfn[top[x]] < dfn[top[y]])
                    std::swap(x, y);
            if (dfn[x] > dfn[y])
                std::swap(x, y);
            res += T.query_sum(1, 1, n, dfn[x] + 1, dfn[y]);
            printf("%d\n", res);
        }
        else if (opt[2] == 'A')
        {
            int x = read() + 1, y = read() + 1, res = -INF;
            for (; top[x] != top[y]; res = std::max(res, T.query_max(1, 1, n, dfn[top[x]], dfn[x])), x = fa[top[x]])
                if (dfn[top[x]] < dfn[top[y]])
                    std::swap(x, y);
            if (dfn[x] > dfn[y])
                std::swap(x, y);
            res = std::max(res, T.query_max(1, 1, n, dfn[x] + 1, dfn[y]));
            printf("%d\n", res);
        }
        else
        {
            int x = read() + 1, y = read() + 1, res = INF;
            for (; top[x] != top[y]; res = std::min(res, T.query_min(1, 1, n, dfn[top[x]], dfn[x])), x = fa[top[x]])
                if (dfn[top[x]] < dfn[top[y]])
                    std::swap(x, y);
            if (dfn[x] > dfn[y])
                std::swap(x, y);
            res = std::min(res, T.query_min(1, 1, n, dfn[x] + 1, dfn[y]));
            printf("%d\n", res);
        }
    }
    return 0;
}
/*
3
2 0 9
1 0 8
8
17 8 9 0 8 0 0 0 0 0 0 0
SUM 1 0
8
17 8 9 0 8 0 0 0 0 0 0 0
C 2 7
16 7 9 0 7 0 0 0 0 0 0 0
SUM 1 2
16
16 7 9 0 7 0 0 0 0 0 0 0
SUM 1 0
7
16 7 9 0 7 0 0 0 0 0 0 0
MAX 1 2
9
16 7 9 0 7 0 0 0 0 0 0 0
C 1 8
15 7 8 0 7 0 0 0 0 0 0 0
MAX 1 2
8
15 7 8 0 7 0 0 0 0 0 0 0
MIN 1 0
7

*/