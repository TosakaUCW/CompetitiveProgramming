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

const int N = 2e5 + 5;

void solve()
{
    int n = read();
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++)
    {
        int u = read() - 1, v = read() - 1;
        g[u].pb(v), g[v].pb(u);
    }
    int r = read() - 1, t0 = read();
    
    
    int lg = std::__lg(n);
    vector<vector<int>> pa(n, vector<int>(lg + 1, -1));
    vector<int> dep(n);

    std::function<void(int, int)> dfs = [&](int u, int fa)
    {
        for (int i = 0; (1 << (i + 1)) <= dep[u]; i++)
            pa[u][i + 1] = pa[pa[u][i]][i];
        for (auto v : g[u])
            if (v ^ fa)
                pa[v][0] = u, dep[v] = dep[u] + 1, dfs(v, u);
    };
    dfs(r, -1);
    auto lca = [&](int x, int y)
    {
        if (dep[x] < dep[y]) std::swap(x, y);
        for (int i = lg; ~i; i--)
            if (dep[x] - dep[y] >= (1 << i)) 
                x = pa[x][i];
        if (x == y) return x;
        for (int i = lg; ~i; i--)
            if (pa[x][i] ^ pa[y][i])
                x = pa[x][i], y = pa[y][i];
        return pa[x][0];  
    };
    auto dis = [&](int x, int y)
    {
        int m = lca(x, y);
        return dep[x] + dep[y] - 2 * dep[m];
    };
    
    vector<vector<int>> buk(n);
    for (int i = 0; i < n; i++) buk[dep[i]].pb(i);
    
    vector<int> d(2 * n + 1);
    for (int i = 1; i < 2 * n + 1; i++)
    {
        d[i] = d[i - 1];
        if (i < n and !buk[i].empty())
        {
            int max = 0;
            int u = buk[i][0];
            for (auto v : buk[i])
                max = std::max(max, dis(u, v));
            d[i] = std::max(d[i] + 1, max);
        }
    }
    
    auto judge = [&](int t, int k)
    {
        return (d[t] + 1) / 2 <= i64(k) * (t - t0);
    };
    
    for (int k = 1; k <= n; k++)
    {
        int ans = 0;
        for (int l = t0 + 1, r = t0 + n; l <= r; )
        {
            int mid = l + r >> 1;
            if (judge(mid, k)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << ans << " \n"[k == n];
    }
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