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
const int M = N << 5;

#define mid (l + r >> 1)

int nodecnt, rt[N];
int ls[M], rs[M];
i64 tr[M], tag[M];

i64 dp[N][2];

void update(int &p, int l, int r, int x, i64 y)
{
    if (!p) p = ++nodecnt;
    tr[p] = y;
    if (l == r) return;
    if (x <= mid) update(ls[p], l, mid, x, y);
    else update(rs[p], mid + 1, r, x, y);
}

void pushdown(int p)
{
    if (ls[p]) tr[ls[p]] += tag[p], tag[ls[p]] += tag[p];
    if (rs[p]) tr[rs[p]] += tag[p], tag[rs[p]] += tag[p];
    tag[p] = 0;
}

int merge(int u, int v, int l, int r, i64 &dp)
{
    if (!u or !v) return u + v;
    if (l == r) dp = std::max(dp, tr[u] + tr[v]);
    
    pushdown(u), pushdown(v);
    tr[u] = std::max(tr[u], tr[v]);
    ls[u] = merge(ls[u], ls[v], l, mid, dp);
    rs[u] = merge(rs[u], rs[v], mid + 1, r, dp);
    return u;
}

void solve()
{
    int n = read();
    
    vector<vector<int>> g(n + 1);
    vector<int> col(n + 1), val(n + 1);
    for (int i = 1; i <= n; i++) col[i] = read();
    for (int i = 1; i <= n; i++) val[i] = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), g[u].pb(v), g[v].pb(u);
    
    std::function<void(int, int)> dfs = [&](int u, int fa)
    {
        dp[u][0] = dp[u][1] = 0;
        
        for (int v : g[u])
            if (v != fa)
                dfs(v, u), 
                dp[u][0] += dp[v][1];
        
        update(rt[u], 1, n, col[u], val[u]);
        
        for (int v : g[u])
            if (v != fa)
                tr[rt[v]] -= dp[v][1], tag[rt[v]] -= dp[v][1],
                rt[u] = merge(rt[u], rt[v], 1, n, dp[u][1]);
                
        dp[u][1] += dp[u][0];
        tr[rt[u]] += dp[u][0], tag[rt[u]] += dp[u][0];
    };
        
    dfs(1, 0);
    cout << dp[1][1] << '\n';
    
    for (int i = 0; i <= nodecnt; i++) ls[i] = rs[i] = tr[i] = tag[i] = 0;
    for (int i = 0; i <= n; i++) rt[i] = 0;
    nodecnt = 0;
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