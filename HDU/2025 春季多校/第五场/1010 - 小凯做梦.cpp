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

    vector<vector<pii>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        w &= 1;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }

    vector col(n + 1, 0);

    auto dfs = [&](auto self, int u, int fa) -> void {
        for (auto [v, w] : g[u]) {
            if (v == fa) continue;
            col[v] = col[u] ^ w;
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);

    int n0 = 0, n1 = 0;
    for (int i = 1; i <= n; i++) {
        if (col[i] == 0) {
            n0++;
        } else {
            n1++;
        }
    }
    int ans = n0 * n0 * n0 + n1 * n1 * n1;

    cout << ans << '\n';
}

/*
1 1 3

1 1 1 
2 2 2
3 3 3

0 1 1
0 0 0
1 1 0
1 0 1

x y z
*/

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}