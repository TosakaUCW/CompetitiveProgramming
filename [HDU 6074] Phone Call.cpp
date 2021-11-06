#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ins insert
#define pb push_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
using std::map;
using std::priority_queue;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::swap;
using std::unordered_map;
using std::unordered_set;
using std::vector;
int read(int x = 0, bool f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
int pow(int x, int k, int P, int res = 1)
{
    for (; k; k >>= 1, x = x * x % P)
        if (k & 1)
            res = res * x % P;
    return res;
}

const int N = 2e5 + 5;
const int P = 998244353;

int n, m;
vector<int> G[N];
int f[N], g[N], cost[N], cnt[N];
int siz[N], fa[N], dep[N], top[N], son[N];
struct Edge
{
    int a, b, c, d, w;
    void input() { a = read(), b = read(), c = read(), d = read(), w = read(); }
    bool friend operator<(Edge a, Edge b) { return a.w < b.w; }
} a[N];

void dfs1(int u, int fa)
{
    siz[u] = 1, dep[u] = dep[fa] + 1, ::fa[u] = fa, son[u] = 0;
    for (auto v : G[u])
        if (v ^ fa)
            dfs1(v, u), siz[u] += siz[v], son[u] = siz[v] > siz[son[u]] ? v : son[u];
}
void dfs2(int u)
{
    top[u] = u == son[fa[u]] ? top[fa[u]] : u;
    if (son[u])
        dfs2(son[u]);
    for (auto v : G[u])
        if (v ^ fa[u] and v ^ son[u])
            dfs2(v);
}
int LCA(int x, int y)
{
    for (; top[x] != top[y]; x = fa[top[x]])
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
    return dep[x] < dep[y] ? x : y;
}

int f_find(int x) { return x == f[x] ? x : f[x] = f_find(f[x]); }
int g_find(int x) { return x == g[x] ? x : g[x] = g_find(g[x]); }
void merge(int x, int y, int w)
{
    int fx = g_find(x), fy = g_find(y);
    if (fx ^ fy)
        g[fx] = fy, cnt[fy] += cnt[fx], cost[fy] += cost[fx] + w;
}
void up(int x, int y, int w)
{
    for (x = f_find(x); dep[x] > dep[y]; x = f_find(x))
        merge(x, fa[x], w), f[x] = fa[x];
}
void access(int x, int y, int w)
{
    int lca = LCA(x, y);
    up(x, lca, w), up(y, lca, w);
}

void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        f[i] = i, g[i] = i, cnt[i] = 1, cost[i] = 0, G[i].clear();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(),
        G[u].pb(v), G[v].pb(u);
    for (int i = 1; i <= m; i++)
        a[i].input();
    dfs1(1, 0), dfs2(1), std::sort(a + 1, a + 1 + m);

    for (int i = 1; i <= m; i++)
        access(a[i].a, a[i].b, a[i].w), access(a[i].c, a[i].d, a[i].w), merge(a[i].a, a[i].c, a[i].w);
    printf("%lld %lld\n", cnt[g_find(1)], cost[g_find(1)]);
}

signed main()
{
    for (int T = read(); T--; solve())
        ;
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
    return 0;
}