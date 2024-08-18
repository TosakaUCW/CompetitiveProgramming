#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::max, std::min;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read();

    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++) {
        g[read()].pb(i);
    }

    using pii = std::pair<int, int>;
    vector<pii> ans(n + 1);
    vector<int> dp(n + 1);
    int timer = 0;

    std::function<void(int)> dfs = [&](int u) {
        dp[u] = u;
        for (int v : g[u]) dfs(v), dp[u] = min(dp[u], dp[v]);
    };
    
    std::function<void(int)> dfs1 = [&](int u) {
        ans[u].second = timer++;
        std::sort(g[u].begin(), g[u].end(), [&](int x, int y) { return dp[x] < dp[y]; });
        for (int v : g[u]) dfs1(v);
    };
    std::function<void(int)> dfs2 = [&](int u) {
        ans[u].first = timer++;
        std::reverse(g[u].begin(), g[u].end());
        for (int v : g[u]) dfs2(v);
    };

    dfs(1);
    dfs1(1);
    timer = 0;
    dfs2(1);

    for (int i = 1; i <= n; i++) {
        auto [x, y] = ans[i];
        x = n - x, y = n - y;
        cout << x << ' ' << y << " \n"[i == n];
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}