#include <bits/stdc++.h>
using i64 = long long;
#define int i64
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

void solve()
{
    int n = read();
    vector<int> a(n + 1), dep(n + 1);
    vector<vector<int>> g(n + 1);
    vector<vector<i64>> f(n + 1, vector<i64>(n + 1, 0));
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i < n; i++) g[read()].pb(i + 1);
    
    i64 ans = 0;
    
    std::function<void(int)> dfs = [&](int u)
    {
        if (g[u].empty()) return void(f[u][dep[u]] = 1e9);
        i64 sum = 0;
        for (auto v : g[u])
        {
            dep[v] = dep[u] + 1, dfs(v), sum += a[v];
            
            for (int j = dep[u]; j <= n; j++)
                f[u][j] += f[v][j];
        }
        
        for (int i = dep[u] + 1; i <= n and a[u] > sum; i++)
        {
            int t = std::min(a[u] - sum, f[u][i]);
            ans += t * (i - dep[u]);
            f[u][i] -= t, sum += t;
        }
        
        f[u][dep[u]] += sum - a[u];
    };
    
    dep[1] = 1, dfs(1);
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}