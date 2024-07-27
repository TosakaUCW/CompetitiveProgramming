#include <bits/stdc++.h>
using i64 = long long;
#define int long long
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const i64 INF = 1LL << 60;

struct node 
{ 
    int cur; i64 dis; 
    bool friend operator < (node a, node b) { return a.dis > b.dis; }
};

void solve()
{
    int n = read(), m = read();
    i64 k = read();
    
    vector<bool> vis(2 * n + 5);
    vector<i64> dis(2 * n + 5, INF);
    std::priority_queue<node> Q;
    vector<vector<std::pair<int, i64>>> g(2 * n + 5);
    
    auto add = [&](int u, int v, i64 dis) { g[u].pb({v, dis}); };
    
    for (int i = 1, u, v, d; i <= m; i++)
        u = read(), v = read(), d = read(), 
        add(u, v, d), add(v, u, d);
        
    for (int i = 1; i <= n; i++)
        add(i, i + n + 1, k * i), add(i + n + 1, i, 0);
    
    for (int i = 0; i <= n; i++)
        for (int j = 0; (i | (1LL << j)) <= n; j++)
            if (!(i >> j & 1))
            {
                int u = i + n + 1;
                int v = (i | (1LL << j)) + n + 1;
                add(u, v, k * (1LL << j));
                add(v, u, 0);
            }
        
    dis[1] = 0, Q.push({1, 0});
    for (int u; !Q.empty(); )
    {
        u = Q.top().cur, Q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, dist] : g[u])
            if (dis[v] > dis[u] + dist)
                dis[v] = dis[u] + dist, Q.push({v, dis[v]});
    }
    for (int i = 2; i <= n; i++) cout << dis[i] << ' ';
    puts("");
    
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