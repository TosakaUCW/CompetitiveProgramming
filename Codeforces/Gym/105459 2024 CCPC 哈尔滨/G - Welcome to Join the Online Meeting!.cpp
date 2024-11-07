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
    int n = read(), m = read(), k = read();

    vector<int> bad(n + 1);
    for (int i = 1; i <= k; i++) {
        int x = read();
        bad[x] = 1;
    }

    vector<int> vis(n + 1);
    vector<vector<int>> g(n + 1);

    using pii = std::pair<int, int>;

    int timer = 0;
    vector<int> idx(n + 1);
    vector<vector<int>> ans(n + 1);

    std::function<void(int)> dfs = [&](int u) {

        vis[u] = 1;
        if (bad[u]) return;

        for (int v : g[u]) {
            if (!vis[v]) {
                idx[++timer] = u;
                break;
            }
        }

        for (int v : g[u]) {
            if (!vis[v]) {

                ans[u].eb(v);
                dfs(v);
            }
        }
    };

    for (int i = 1; i <= m; i++) {
        int u = read();
        int v = read();
        g[u].eb(v);
        g[v].eb(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!bad[i]) {
            dfs(i);
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
    cout << timer << '\n';
    for (int i = 1; i <= timer; i++) {
        int u = idx[i];
        cout << u << ' ' << ans[u].size();

        for (int v : ans[u]) {
            cout << ' ' << v;
        }
        puts("");
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}