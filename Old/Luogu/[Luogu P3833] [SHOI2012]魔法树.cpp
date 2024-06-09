#include <stdio.h>
#include <algorithm>
#include <iostream>

typedef long long ll;

const ll N = 1e5 + 5;
const ll M = N << 1;

ll n, m;
ll head[N], num_edge;
ll dfn[N], idx[N], top[N], son[N], fa[N], depth[N], size[N];

struct Node
{
    ll next, to;
} edge[M];

void add_edge(ll u, ll v) { edge[++num_edge] = Node{head[u], v}, head[u] = num_edge; }

ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

void dfs1(ll u, ll fa)
{
    ::fa[u] = fa, size[u] = 1, depth[u] = depth[fa] + 1;
    for (ll i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
            dfs1(v, u), size[u] += size[v], son[u] = size[v] > size[son[u]] ? v : son[u];
}

void dfs2(ll u)
{
    dfn[u] = ++dfn[0], idx[dfn[u]] = u, top[u] = u == son[fa[u]] ? top[fa[u]] : u;
    if (son[u])
        dfs2(son[u]);
    for (ll i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa[u] and v != son[u])
            dfs2(v);
}

struct Segment_Tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) / 2)
    ll tag[N << 2], sum[N << 2];
    void push_up(ll p) { sum[p] = sum[ls] + sum[rs]; }
    void push_down(ll p, ll l, ll r)
    {
        if (tag[p])
        {
            sum[ls] += tag[p] * (mid - l + 1), sum[rs] += tag[p] * (r - mid);
            tag[ls] += tag[p], tag[rs] += tag[p];
            tag[p] = 0;
        }
    }
    void modify(ll p, ll l, ll r, ll x, ll y, ll k)
    {
        if (x == l and r == y)
        {
            sum[p] += k * (r - l + 1), tag[p] += k;
            return;
        }
        push_down(p, l, r);
        if (x <= mid)
            modify(ls, l, mid, x, std::min(mid, y), k);
        if (mid < y)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y, k);
        push_up(p);
    }
    ll query(ll p, ll l, ll r, ll x, ll y)
    {
        if (x == l and r == y)
            return sum[p];
        ll res = 0;
        push_down(p, l, r);
        if (x <= mid)
            res += query(ls, l, mid, x, std::min(mid, y));
        if (mid < y)
            res += query(rs, mid + 1, r, std::max(mid + 1, x), y);
        return res;
    }
} T;

signed main()
{
    n = read();
    for (ll i = 1, u, v; i < n; i++)
        u = read() + 1, v = read() + 1, add_edge(u, v), add_edge(v, u);
    dfs1(1, 0), dfs2(1);
    for (ll m = read(), x, y, k; m--;)
    {
        char opt;
        std::cin >> opt;
        if (opt == 'Q')
        {
            x = read() + 1;
            printf("%lld\n", T.query(1, 1, n, dfn[x], dfn[x] + size[x] - 1));
        } // query
        else
        {
            x = read() + 1, y = read() + 1, k = read();
            for (; top[x] != top[y]; T.modify(1, 1, n, dfn[top[x]], dfn[x], k), x = fa[top[x]])
                if (dfn[top[x]] < dfn[top[y]])
                    std::swap(x, y);
            if (dfn[x] > dfn[y])
                std::swap(x, y);
            T.modify(1, 1, n, dfn[x], dfn[y], k);
        } // add
    }
    return 0;
}