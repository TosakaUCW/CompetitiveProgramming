#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read();

    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> sum(n + 1);

    using pii = std::pair<int, int>;
    vector<vector<pii>> g(n + 1);

    for (int i = 1; i <= n; i++) {
        a[i] = read();
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        b[i] = read();
        g[i].eb(b[i], a[i]);
        if (i >= 2) g[i].eb(i - 1, 0);
    }

    vector<int> dis(n + 1, 1e18);
    vector<int> vis(n + 1);

    auto dij = [&](int s) {
        std::priority_queue<pii> q;
        q.ep(0, s), dis[s] = 0;

        while (!q.empty()) {
            int u = q.top().second;
            q.pop();

            if (vis[u]) continue;
            vis[u] = 1;

            for (auto [v, w] : g[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.ep(-dis[v], v);
                }
            }
        }

    };
    dij(1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, sum[i] - dis[i]);
    }
    
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}