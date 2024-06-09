#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ins insert
#define pb push_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
using std::swap;
using std::vector;
int read(int x = 0, bool f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int n;
int a[N];
vector<pii> g[N];
vector<int> G[N];
int f[N];
int fa[N], siz[N], dep[N], top[N], son[N], dfn[N], idx[N];
void dfs1(int u, int fa)
{
    ::fa[u] = fa, siz[u] = 1, dep[u] = dep[fa] + 1;
    for (auto [v, dis] : g[u])
        if (v ^ fa) f[v] = std::min(f[u], dis), dfs1(v, u), siz[u] += siz[v], son[u] = siz[v] > siz[son[u]] ? v : son[u];
}
void dfs2(int u)
{
    dfn[u] = ++dfn[0], idx[dfn[u]] = u, top[u] = u == son[fa[u]] ? top[fa[u]] : u;
    if (son[u]) dfs2(son[u]);
    for (auto [v, dis] : g[u]) if (v ^ son[u] and v ^ fa[u]) dfs2(v);
}
int LCA(int x, int y)
{
    for (; top[x] ^ top[y]; x = fa[top[x]]) if (dep[top[x]] < dep[top[y]]) swap(x, y);
    return dep[x] < dep[y] ? x : y;
}
int dp(int u)
{
    if (G[u].size() == 0) return f[u];
    int res = 0;
    for (auto v : G[u]) res += dp(v);
    G[u].clear();
    return std::min(res, f[u]);
}

int stk[N], end;
vector<int> h;
#define add(x, y) G[x].pb(y)

void ins(int x)
{
    if (end == 1) return stk[++end] = x, void();
    int lca = LCA(x, stk[end]);
    if (lca == stk[end]) return;
    while (end > 1 and dfn[stk[end - 1]] >= dfn[lca])
        add(stk[end - 1], stk[end]), --end;
    if (lca != stk[end]) add(lca, stk[end]), stk[end] = lca;
    stk[++end] = x;
}

void solve()
{
    n = read(), f[1] = LLONG_MAX;
    for (int i = 1, u, v, w; i < n; i++)
        u = read(), v = read(), w = read(),
        g[u].pb({v, w}), g[v].pb({u, w});
    dfs1(1, 0), dfs2(1);
    for (int T = read(); T--; h.clear())
    {
        for (int k = read(); k--; ) h.pb(read());
        std::sort(h.begin(), h.end(), [](int x, int y) { return dfn[x] < dfn[y]; });
        stk[end = 1] = 1;
        for (auto x : h) ins(x);
        while (end > 0) add(stk[end - 1], stk[end]), end--;
        printf("%lld\n", dp(1));
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("my.in", "r", stdin);
#endif
    solve();
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
    return 0;
}