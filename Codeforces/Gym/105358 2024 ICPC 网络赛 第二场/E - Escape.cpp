#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr, std::cin, std::cout, std::string, std::vector;
using std::max, std::min, std::swap;
int read(int x = 0, bool f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read(), m = read(), d = read();
    vector<vector<int>> g(n * 2 + 1);
    vector<int> f(n * 2 + 1, -1);
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();

        g[u].eb(v + n);
        g[v].eb(u + n);
        g[v + n].eb(u);
        g[u + n].eb(v);
    }

    std::queue<int> q;

    for (int k = read(); k--; ) {
        int u = read();
        f[u] = 0;
        q.ep(u);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();

        if (f[u] == d) continue;

        for (int v : g[u]) {
            if (f[v] == -1) {
                f[v] = f[u] + 1;
                q.ep(v);
            }
        }
    }
    
    using pii = std::pair<int, int>;

    std::queue<pii> Q;
    vector<int> pre(n * 2 + 1);
    Q.ep(1, 0);

    while (!Q.empty()) {
        auto [u, t] = Q.front(); Q.pop();

        for (int v : g[u]) {
            if (pre[v] or v == 1) continue;
            if (t + 1 >= f[v] and f[v] != -1) continue;

            Q.ep(v, t + 1);
            pre[v] = u;
        }
    }

    if (!pre[n] && !pre[n + n]) {
        puts("-1");
        return;
    }

    vector<int> ans[2];

    std::function<void(int, int)> go = [&](int now, int i) {
        if (now == 1) return;
        
        go(pre[now], i);

        ans[i].eb((now - 1) % n + 1);
    };

    if (pre[n]) go(n, 0);
    if (pre[n + n]) go(n + n, 1);

    if (!pre[n]) ans[0] = ans[1];
    if (!pre[n + n]) ans[1] = ans[0];

    if (ans[0].size() > ans[1].size()) {
        swap(ans[0], ans[1]);
    }

    std::cout << ans[0].size() << "\n1 ";
    for (auto x : ans[0]) cout << x << " ";
    puts("");
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}