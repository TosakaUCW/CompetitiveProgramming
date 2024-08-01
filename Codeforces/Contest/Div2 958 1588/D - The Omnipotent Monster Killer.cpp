#include <bits/stdc++.h>
using i64 = long long;
// #define int long long
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::min, std::max, std::cin, std::cout, std::string, std::vector;

i64 read(i64 x = 0, i64 f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}


void solve()
{
    int n = read();
    vector<i64> a(n + 1);
    vector<vector<int>> g(n + 1);
    vector<vector<i64>> f(n + 1, vector<i64>(26));
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        g[u].pb(v);
        g[v].pb(u);
    }
    const int m = 25;
    const i64 INF = 1LL << 62;
    std::function<void(int, int)> dfs = [&](int u, int fa)
    {
        for (int i = 1; i <= m; i++) f[u][i] = 1LL * i * a[u];
        for (auto v : g[u])
        {
            if (v == fa) continue;
            dfs(v, u);
            for (int i = 1; i <= m; i++)
            {
                i64 mn = INF;
                for (int j = 1; j <= m; j++)
                {
                    if (i == j) continue;
                    mn = min(mn, f[v][j]);
                }
                f[u][i] += mn;
            }
        }
    };
    dfs(1, 0);
    i64 ans = INF;
    for (int i = 1; i <= m; i++) ans = min(ans, f[1][i]);
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}