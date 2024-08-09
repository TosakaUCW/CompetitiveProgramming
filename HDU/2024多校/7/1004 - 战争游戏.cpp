#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read(), s = read();
    int r1 = read(), r2 = read();

    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        g[u].pb(v), g[v].pb(u);
    }

    if (r2 <= 2 * r1) {
        puts("Kangaroo_Splay");
        return;
    }

    int D = 0;
    vector<int> dp(n + 1);
    std::function<void(int, int)> dfs = [&](int u, int fa) {
        for (int v : g[u]) {
            if (v == fa) continue;
            dfs(v, u);
            D = std::max(D, dp[u] + dp[v] + 1);
            dp[u] = std::max(dp[u], dp[v] + 1);
        }
    };
    dfs(1, 0);

    if (D + 1 <= 2 * r1 + 1) {
        puts("Kangaroo_Splay");
    }
    else {
        puts("General_Kangaroo");
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}