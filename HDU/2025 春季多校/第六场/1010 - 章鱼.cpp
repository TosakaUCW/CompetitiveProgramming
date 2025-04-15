#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    int n; cin >> n;
    
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }

    vector<int> ans(n + 1);
    vector<int> siz(n + 1);

    auto dfs = [&](auto self, int u, int fa) -> void {
        siz[u] = 1;

        vector<int> a;
        for (int v : g[u]) {
            if (v == fa) continue;
            self(self, v, u);
            siz[u] += siz[v];
            a.eb(siz[v]);
        }
        a.eb(n - siz[u]);

        int tot = 0;
        int res = 0;
        for (auto x : a) {
            res += x * tot;
            tot += x;
        }
        ans[u] += res + n; // rt: u
        // cout << u << ' ' << res << '\n';

        for (int v : g[u]) {
            if (v != fa) {
                int k = siz[v];
                ans[u] += k * (res - (k * (n - k - 1)));
                ans[u] += k * (n - k);
                // cout << u << ' ' << k * (res - (k * (n - k - 1))) << '\n';
            } else {
                int k = n - siz[u];
                ans[u] += k * (res - (k * (n - k - 1)));
                ans[u] += k * (n - k);
                // cout << u << ' ' << k * (res - (k * (n - k - 1))) << '\n';
            }
        }
        // ans[u] += n * (n - 1);
    };
    dfs(dfs, 1, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}