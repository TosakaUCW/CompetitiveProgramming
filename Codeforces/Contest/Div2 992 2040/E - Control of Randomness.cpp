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
using std::ostream;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

const int inf = 1e18;

void solve() {
    int n = read();
    int q = read();

    vector<vector<int>> g(n + 1);

    for (int i = 1; i < n; i++) {
        int u = read();
        int v = read();
        g[u].eb(v), g[v].eb(u);
    }

    vector dp(n + 1, vector(n + 1, inf));

    auto dfs = [&](auto&& self, int u, int fa) -> void {
        int d = g[u].size();
        for (auto v : g[u]) {
            if (v == fa) continue;

            if (u == 1) {
                fill(dp[v].begin(), dp[v].end(), 1);
            } else {
                for (int p = 0; p <= n; p++) {
                    dp[v][p] = dp[fa][p] + 2 * d;
                    if (p) {
                        dp[v][p] = min(dp[v][p], dp[fa][p - 1] + 2);
                    }
                }
            }

            self(self, v, u);
        }

        // cerr << dp[u] << '\n';
    };

    fill(dp[1].begin(), dp[1].end(), 0);
    dfs(dfs, 1, 0);

    while (q--) {
        int u = read();
        int k = read();
        cout << dp[u][k] << '\n';
    }

}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}