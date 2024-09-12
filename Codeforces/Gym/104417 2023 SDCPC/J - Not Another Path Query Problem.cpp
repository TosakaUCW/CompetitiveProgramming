#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap;
using std::cin, std::cout, std::string, std::vector;
i64 read(i64 x = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return x;
}

void solve() {
    int n = read(), m = read(), q = read();
    int V = read();

    using pii = std::pair<int, int>;
    #define fi first
    #define se second

    vector<vector<pii>> g(n + 1);

    while (m--) {
        int u = read(), v = read();
        int w = read();

        g[u].eb(v, w);
        g[v].eb(u, w);
    }

    vector<int> ans(q);
    vector<pii> qry(q);
    for (auto &[x, y] : qry) {
        x = read(), y = read();
    }

    auto check = [&](int V) {
        int cnt = 0;
        vector<int> bel(n + 1);

        std::function<void(int, int)> bfs = [&](int s, int V) {
            std::queue<int> q;
            q.push(s), bel[s] = ++cnt;

            while (!q.empty()) {
                int u = q.front(); q.pop();

                for (auto [v, dis] : g[u]) {
                    if (bel[v] or (dis & V) != V) continue;
                    bel[v] = bel[u];
                    q.push(v);
                }
            }
        };

        for (int i = 1; i <= n; i++) {
            if (!bel[i]) {
                bfs(i, V);
            }
        }

        for (int i = 0; i < q; i++) {
            auto &[x, y] = qry[i];
            ans[i] |= (bel[x] == bel[y]);
        }
    };

    if (V == 0LL) {
        check(0);
    } else {
        for (int t = V; t < (1LL << 60); t += t & (-t)) {
            check(t);
        }
    }

    for (auto x : ans) {
        puts(x ? "Yes" : "No");
    }
}

signed main() {
    solve();
    return 0;
}