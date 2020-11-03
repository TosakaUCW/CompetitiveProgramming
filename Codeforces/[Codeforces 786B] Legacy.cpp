#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

using ll = long long;

const ll N = 4e5 + 5;
const ll M = 3e6 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll n, m, s;
ll head[N], num_edge;
ll ls[N], rs[N];
ll rt1, rt2, node_cnt;
ll dis[N];
bool vis[N];

struct Node
{
    ll next, to, dis;
} edge[M];
struct data
{
    ll cur, dis;
    bool friend operator<(data a, data b) { return a.dis > b.dis; };
};

std::priority_queue<data> Q;

void add_edge(ll u, ll v, ll dis) { edge[++num_edge] = Node{head[u], v, dis}, head[u] = num_edge; }

void build(ll &p, ll l, ll r, ll opt)
{
    if (l == r)
    {
        p = l;
        return;
    }
    ll mid = (l + r) >> 1;
    p = ++node_cnt;
    build(ls[p], l, mid, opt), build(rs[p], mid + 1, r, opt);
    if (opt == 0)
        add_edge(p, ls[p], 0), add_edge(p, rs[p], 0);
    else
        add_edge(ls[p], p, 0), add_edge(rs[p], p, 0);
}

void update(ll &p, ll l, ll r, ll x, ll y, ll u, ll dis, ll opt)
{
    if (x <= l and r <= y)
    {
        if (opt == 0)
            add_edge(u, p, dis);
        else
            add_edge(p, u, dis);
        return;
    }
    ll mid = (l + r) >> 1;
    if (x <= mid)
        update(ls[p], l, mid, x, y, u, dis, opt);
    if (mid < y)
        update(rs[p], mid + 1, r, x, y, u, dis, opt);
}

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

void dijkstra(ll s)
{
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0, Q.push(data{s, 0});
    while (!Q.empty())
    {
        ll u = Q.top().cur;
        Q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (ll i = head[u], v; i; i = edge[i].next)
            if (dis[v = edge[i].to] > dis[u] + edge[i].dis)
            {
                dis[v] = dis[u] + edge[i].dis;
                if (!vis[v])
                    Q.push(data{v, dis[v]});
            }
    }
}

signed main()
{
    n = read(), m = read(), s = read();
    node_cnt = n;
    build(rt1, 1, n, 0), build(rt2, 1, n, 1);
    for (ll u, v, dis, l, r, opt; m--;)
    {
        opt = read();
        if (opt == 1)
            v = read(), u = read(), dis = read(), add_edge(v, u, dis);
        if (opt == 2)
            v = read(), l = read(), r = read(), dis = read(), update(rt1, 1, n, l, r, v, dis, 0);
        if (opt == 3)
            v = read(), l = read(), r = read(), dis = read(), update(rt2, 1, n, l, r, v, dis, 1);
    }
    dijkstra(s);
    for (ll i = 1; i <= n; i++)
        printf("%lld ", dis[i] == INF ? -1 : dis[i]);
    return 0;
}