#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read(), m = read();

    vector<int> vis(n + 1);
    for (int i = 1; i <= m; i++) {
        vis[read()] = 1;
    }

    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        g[u].pb(v), g[v].pb(u);
    }

    int ans = 0;
    vector<int> siz(n + 1);

    std::function<void(int, int)> dfs = [&](int u, int fa) {
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs(v, u);
            siz[u] += siz[v];
        }

        siz[u] += !vis[u];

        if (vis[u]) {
            ans += (siz[u] + 1) / 2;
            if (siz[u] & 1) vis[fa] = 1;
            siz[u] = 0;
        }
    };

    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            dfs(i, 0);
            break;
        }
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}