#include <bits/stdc++.h>
#define int long long
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
const int N = 1e6 + 5;
const int INF = 1e18;
int n, m, a[N];
void solve()
{
    n = read(), m = read();
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) c[i] = read();
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<pii>> b(m + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read(), b[j].pb({a[i][j], i});
    vector<vector<int>> rk(n + 1, vector<int>(m + 1));
    vector<vector<int>> dec(n + 1, vector<int>(m + 1));
    for (int j = 1; j <= m; j++)
    {
        std::sort(b[j].begin(), b[j].end());
        for (int i = 0; i < n; i++)
        {
            auto [x, id] = b[j][i];
            rk[id][j] = i + 1;
            dec[i + 1][j] = id;
        }
    }

    int ans = INF;
    vector<int> vis(n + 1, 0);
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, INF));
    std::priority_queue<tuu, vector<tuu>, std::greater<tuu>> Q;
    vis[1] = 1;
    for (int j = 1; j <= m; j++) dist[1][j] = 0, Q.push({dist[1][j], 1, j});
    while (!Q.empty())
    {
        auto [w, x, t] = Q.top(); Q.pop();
        // cout << w << x << t << '\n';
        if (dist[x][t] < w) continue;
        if (x == n) ans = std::min(ans, w + c[n]);
        if (rk[x][t] < n)
        {
            int z = dec[rk[x][t] + 1][t];
            if (w < dist[z][t])
                dist[z][t] = w, Q.push({dist[z][t], z, t});
        }
        if (rk[x][t] > 1)
        {
            int z = dec[rk[x][t] - 1][t];
            if (w + a[x][t] - a[z][t] < dist[z][t])
                dist[z][t] = w + a[x][t] - a[z][t], Q.push({dist[z][t], z, t});
        }
        if (!vis[x])
        {
            vis[x] = 1;
            for (int j = 1; j <= m; j++)
                if (w + c[x] < dist[x][j])
                    dist[x][j] = w + c[x], Q.push({dist[x][j], x, j});
        }
    }
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("E.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}