#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int n = read();

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        adj[u].eb(v), adj[v].eb(u);
    }

    vector f(n + 1, vector(3, 0ll));

    // 1 -, 2 +

    auto dfs = [&](this auto&& dfs, int u, int fa) -> void {

        int g = 0;
        int mx = 0;

        for (int v : adj[u]) if (v != fa) {
            dfs(v, u);
            g += f[v][0];

            if (!mx or f[v][1] - f[v][0] > f[mx][1] - f[mx][0]) {
                mx = v;
            }
        }

        f[u][0] = g, f[u][1] = g - a[u], f[u][2] = g + a[u];

        for (int v : adj[u]) if (v != fa) {
            int now = g - f[v][0];

            f[u][1] = max(f[u][1], now + f[v][1]);
            f[u][2] = max(f[u][2], now + f[v][2]);

            f[u][0] = max(f[u][0], now + f[v][1] + a[u]);
            f[u][0] = max(f[u][0], now + f[v][2] - a[u]);

            if (mx and mx != v) {
                f[u][0] = max(f[u][0], now + f[v][2] + (f[mx][1] - f[mx][0]));
            }
        }
    };

    dfs(1, 0);

    cout << f[1][0] << '\n';
}



signed main() {
    solve();
    return 0;
}