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

    vector<int> bad(k + 1), used(k + 1);
    for (int i = 1; i <= n; i++) {
        bad[read()] = 1;
    }

    int ans = 0;

    using pii = std::pair<int, int>;
    #define fi first
    #define se second
    std::map<pii, int> mp;

    vector<int> f(k + 1);
    vector<vector<int>> g(k + 1);

    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        if (bad[u] and bad[v]) {
            ans++;
            continue;
        }
        g[u].eb(v);
        g[v].eb(u);

        if (u > v) swap(u, v);
        if (u != v) mp[{u, v}]++;
        else f[u]++;
        // mp[{v, u}]++;
    }

    
    for (int i = 1; i <= k; i++) {
        if (bad[i]) continue;
        for (int v : g[i]) {
            if (bad[v]) {
                f[i]++;
            }
        }
        // f[i] += mp[{i, i}];
    }

    int res = 0;
    for (auto [it, cnt] : mp) {
        auto [u, v] = it;
        if (!bad[u] and !bad[v])
            res = max(res, f[u] + f[v] + cnt);
        else 
            res = max(res, f[u] + f[v]);
    }

    std::sort(f.begin() + 1, f.end());
    res = max(res, f[k] + f[k - 1]);

    cout << ans + res << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}