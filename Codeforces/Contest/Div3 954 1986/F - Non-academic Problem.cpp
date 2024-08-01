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

struct EBCC
{
    int n;
    vector<vector<int>> adj;
    vector<int> stk, dfn, low, bel;
    int cur, cnt;
    EBCC() {}
    EBCC(int n) { init(n); }
    void init(int n)
    {
        this->n = n;
        adj.assign(n, {}), dfn.assign(n, -1);
        low.resize(n), bel.assign(n, -1);
        stk.clear(), cur = cnt = 0;
    }
    void addEdge(int u, int v) { adj[u].push_back(v), adj[v].push_back(u); }
    void dfs(int x, int p)
    {
        dfn[x] = low[x] = cur++, stk.push_back(x);
        for (auto y : adj[x])
        {
            if (y == p) continue;
            if (dfn[y] == -1)
                dfs(y, x), low[x] = std::min(low[x], low[y]);
            else if (bel[y] == -1)
                low[x] = std::min(low[x], dfn[y]);
        }
        if (dfn[x] == low[x])
        {
            int y;
            do { y = stk.back(), bel[y] = cnt, stk.pop_back(); } while (y != x);
            cnt++;
        }
    }
    std::vector<int> work() { return dfs(0, -1), bel; }
    struct Graph
    {
        int n;
        vector<pii> edges;
        vector<int> siz, cnte;
    };
    Graph compress()
    {
        Graph g; g.n = cnt;
        g.siz.resize(cnt), g.cnte.resize(cnt);
        for (int i = 0; i < n; i++)
        {
            g.siz[bel[i]]++;
            for (auto j : adj[i])
            {
                if (bel[i] < bel[j]) g.edges.emplace_back(bel[i], bel[j]);
                else if (i < j) g.cnte[bel[i]]++;
            }
        }
        return g;
    }
};

const int N = 2e5 + 5;

void solve()
{
    int n = read(), m = read();
    EBCC g(n);
    for (int i = 0; i < m; i++)
    {
        int u = read(), v = read();
        g.addEdge(u - 1, v - 1);
    }
    g.work();
    auto f = g.compress();
    vector<vector<int>> adj(f.n);
    for (auto [u, v] : f.edges)
        adj[v].pb(u), adj[u].pb(v);
        
    vector<int> siz(f.n);
    i64 ans = 0;
    std::function<void(int, int)> dfs = [&](int u, int fa)
    {
        siz[u] = f.siz[u];
        for (auto v : adj[u])
        {
            if (v == fa) continue;
            dfs(v, u), siz[u] += siz[v];
            ans = std::max(ans, 1LL * siz[v] * (n - siz[v]));
        }
    };
    dfs(0, -1);
    ans = 1LL * n * (n - 1) / 2 - ans;
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