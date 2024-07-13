#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 5e6 + 5;
const int P = 1e9 + 7;

void solve()
{
    int n = read(), m = read();
    vector<vector<int>> g(n + 1);
    vector<int> dep(n + 1), vis(n + 1);
    for (int i = 1, u, v; i <= m; i++)
        u = read(), v = read(), g[u].pb(v), g[v].pb(u);
        
    std::function<void(int)> dfs = [&](int u)
    {
        vis[u] = 1;
        for (auto v : g[u])
            if (!vis[v]) dep[v] = dep[u] + 1, dfs(v);
    };    
        
    for (int i = 1; i <= n; i++)
        if (!vis[i]) dep[i] = 0, dfs(i);
    i64 ans = 0;
    for (int i = 1; i <= n; i++) ans += dep[i];
    cout << ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}