#include <bits/stdc++.h>
// using i64 = long long;
// #define int i64
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

using pii = std::pair<int, int>;

const int inf = 1e9;

void solve() {
    int n = read();

    vector<int> par(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++) {
        int p = read();
        par[i] = p;
        g[p].eb(i);
    }

    vector<int> dep(n + 1);

    vector<pii> leaf;

    auto dfs = [&](auto&& self, int u) -> void {
        for (int v : g[u]) {
            dep[v] = dep[u] + 1;
            self(self, v);
        }
        if (g[u].empty()) {
            leaf.eb(dep[u], u);
        }
    };
    dfs(dfs, 1);

    std::sort(leaf.begin(), leaf.end());

    // for (auto [d, u] : leaf) {
    //     cerr << d << " " << u << "\n";
    // }

    int ans = 0;
    vector<int> vis(n + 1);
    for (auto [_, u] : leaf) {
        int res = 0;
        for (int v = u; par[v] != 0; v = par[v]) {
            // v -> par[v]
            res++;
            // cout << "vis" << v << " " << par[v] << "\n";
            if (vis[v]) break;
            vis[v] = 1;
            ans = max(ans, res);
        }
    }

    cout << ans << '\n';
}    

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}