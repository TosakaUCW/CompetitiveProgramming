#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
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

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        g[u].eb(v), g[v].eb(u);
    }

    vector<int> vis(n + 1);
    vector<i64> ans;

    auto bfs = [&](int s) -> std::pair<i64, i64> {
        std::queue<int> q;
        q.push(s);

        i64 edge = 0, node = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();

            if (vis[u]) continue;
            vis[u] = 1;
            node++;

            for (auto v : g[u]) {
                if (vis[v]) continue;
                q.push(v), edge++;
            }
        }
        return {node, edge};
    };

    bool f = 1;
    i64 res = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;

        auto [node, edge] = bfs(i);

        if (edge != node * (node - 1) / 2) {
            f = 0;
            res += node * (node - 1) / 2 - edge;
        }
        ans.eb(node);
    }

    if (f) {
        std::sort(ans.begin(), ans.end());
        cout << ans[0] * ans[1] << '\n';
    } else {
        cout << res << '\n';
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}