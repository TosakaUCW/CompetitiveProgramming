#include <stdio.h>
#include <algorithm>

typedef long long ll;

const int N = 4e5 + 5;
const int M = 8e5 + 5;

int n, m;
int cnt, dfn[N], begin[N], end[N];
int num_edge, head[N];
int col[N];

class Segment_Tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)

  private:
    struct Node
    {
        ll status;
        bool tag;
    } t[N << 2];
    void push_up(int p) { t[p].status = t[ls].status | t[rs].status; }
    void push_down(int p)
    {
        if (t[p].tag)
        {
            t[p].tag = false;
            t[ls].status = t[rs].status = t[p].status;
            t[ls].tag = t[rs].tag = true;
        }
    }

  public:
    void build(int p, int l, int r)
    {
        if (l == r)
        {
            t[p].status = 1LL << col[dfn[l]];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        push_up(p);
    }
    void modify(int p, int l, int r, int x, int y, int val)
    {
        if (x <= l and r <= y)
        {
            t[p].status = 1LL << val;
            t[p].tag = true;
            return;
        }
        push_down(p);
        int mid = (l + r) >> 1;
        if (x <= mid)
            modify(ls, l, mid, x, y, val);
        if (mid < y)
            modify(rs, mid + 1, r, x, y, val);
        push_up(p);
    }
    ll query(int p, int l, int r, int x, int y)
    {
        if (x <= l and r <= y)
            return t[p].status;
        push_down(p);
        int mid = (l + r) >> 1;
        if (y <= mid)
            return query(ls, l, mid, x, y);
        if (mid < x)
            return query(rs, mid + 1, r, x, y);
        return query(ls, l, mid, x, y) | query(rs, mid + 1, r, x, y);
    }
} T;

struct Edge
{
    int next, to;
} edge[M];

void add_edge(int u, int v)
{
    edge[++num_edge].next = head[u];
    edge[num_edge].to = v;
    head[u] = num_edge;
}

void dfs(int u, int fa)
{
    dfn[++cnt] = u;
    begin[u] = cnt;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v != fa)
            dfs(v, u);
    }
    end[u] = cnt;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &col[i]);
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    dfs(1, 0);
    T.build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int opt, v;
        scanf("%d%d", &opt, &v);
        if (opt == 1)
        {
            int c;
            scanf("%d", &c);
            T.modify(1, 1, n, begin[v], end[v], c);
        }
        else
        {
            ll ans = T.query(1, 1, n, begin[v], end[v]);
            printf("%d\n", __builtin_popcountll(ans));
        }
    }
    return 0;
}