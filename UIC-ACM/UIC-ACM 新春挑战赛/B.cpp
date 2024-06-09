#include <bits/stdc++.h>
// #define int long long
#define pb push_back
using std::cin, std::cout, std::string;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e5 + 5;
const int INF = 1 << 30;
// const long long INF = 1LL << 60;
int n;
int fa[N], dep[N], siz[N], son[N], top[N], dp[N], fp[N];
std::vector<int> g[N];
void dfs1(int u, int fa)
{
    siz[u] = 1, ::fa[u] = fa, dep[u] = dep[fa] + 1, son[u] = 0;
    for (auto v : g[u]) if (v ^ fa) dfs1(v, u), siz[u] += siz[v], son[u] = siz[v] > siz[son[u]] ? v : son[u];
}
void dfs2(int u)
{
    top[u] = u == son[fa[u]] ? top[fa[u]] : u;
    if (son[u]) dfs2(son[u]);
    for (auto v : g[u]) if (v ^ son[u] and v ^ fa[u]) dfs2(v), dp[u] += dp[v] + siz[v];
}
void dfs3(int u, int sum)
{
    for (auto v : g[u]) if (v ^ fa[u]) fp[v] = fp[u] + sum + siz[u] - siz[v], dfs3(v, sum + siz[u] - siz[v]);
}
int LCA(int x, int y)
{
    for (; top[x] ^ top[y]; x = fa[top[x]])
        if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
    return dep[x] < dep[y] ? x : y;
}
void solve()
{
    n = read();
    for (int u, v, i = 1; i < n; i++)
        u = read(), v = read(),
        g[u].pb(v), g[v].pb(u);
    dfs1(1, 0), dfs2(1), dfs3(1, 0);
    int ans = 0, res = 0;
    puts("1");
    for (int m = read(); m--; )
    {
        int x = (read() ^ res + res) % n + 1, y = (read() ^ res + res) % n + 1;
        int lca = LCA(x, y);
        if (dep[x] < dep[y]) std::swap(x, y);
        int dis = 2 * dep[lca] - dep[x] - dep[y];
        int middle = dis / 2;
        int newx = x;
        for (; middle > dep[top[newx]] - dep[newx]; middle -= dep[top[newx]] - dep[newx], x = fa[top[x]]);
        for (; middle--; newx = fa[newx]);
        res = dp[x] + dp[y] + dp[1] - dp[lca] + fp[x] - fp[newx] + fp[newx] - fp[lca] + fp[y] - fp[lca];
        ans = ans ^ (res * res);
    }
    cout << ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    solve();
    return 0;
}