#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
using ull = unsigned long long;

void solve() {
    int n = read(), m = read();
    int d = read() + 1, q = read();

    vector<ull> val(d), ha(n);
    std::mt19937_64 rng(std::random_device{}());
    for (int i = 0; i < d; i++) val[i] = rng();

    vector g(d, vector(n, vector<int> {}));
    vector rt(d, vector<int>(n));

    for (int i = 0; i < d; i++) {
        for (int u = 0; u < n; u++) {
            rt[i][u] = u;
            ha[u] += u * val[i];
            g[i][u].pb(u);
        }
    }

    std::unordered_map<ull, int> cnt;

    int ans = 0;

    auto add = [&](ull ha) {
        ans += cnt[ha];
        cnt[ha]++;
    };
    auto dec = [&](ull ha) {
        ans -= cnt[ha] - 1;
        cnt[ha]--;
        if (cnt[ha] == 0) cnt.erase(ha);
    };

    for (int u = 0; u < n; u++) add(ha[u]);

    auto merge = [&](int u, int v, int k) {
        u = rt[k][u];
        v = rt[k][v];

        if (u == v) {
            return;
        }

        if (g[k][v].size() > g[k][u].size()) {
            std::swap(u, v);
        }

        for (int x : g[k][v]) {
            g[k][u].pb(x);
            rt[k][x] = u;
            dec(ha[x]);
            ha[x] += val[k] * (u - v);
            add(ha[x]);
        }
        g[k][v].clear();
    };

    for (int t = 1; t <= m + q; t++) {
        int u = read() - 1, v = read() - 1;

        if (t > m) { 
            int k = read() - 1;
            merge(u, v, k);
            cout << ans << '\n';
        }
        else {
            for (int k = 0; k < d; k++) {
                merge(u, v, k);
            }
        }
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}