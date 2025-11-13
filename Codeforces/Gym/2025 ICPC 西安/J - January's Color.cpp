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
#define fi first
#define se second
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
template <class T> bool cmin(T &a, T b) { return (b < a) ? (a = b, true) : false; }
template <class T> bool cmax(T &a, T b) { return (a < b) ? (a = b, true) : false; }
using pii = pair<int, int>;
using tup = tuple<int, int, int>;
const int inf = 1e18;
const double eps = 1e-9;

void solve() {
    int n = read(), q = read();

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        adj[u].eb(v), adj[v].eb(u);
    }

    vector<int> dfin(n + 1), dfou(n + 1);
    int timer = 0;

    vector<int> f(n + 1);
    vector<int> g(n + 1);
    vector<int> sum(n + 1);

    [&](this auto&& dfs, int u, int fa) -> void {
        dfin[u] = ++timer;
        f[u] = a[u];
        if (fa) {
            adj[u].erase(ranges::find(adj[u], fa));
        }

        vector<int> t;
        for (int v : adj[u]) {
            dfs(v, u);
            t.eb(f[v]);
        }
        dfou[u] = timer;

        if (adj[u].empty()) return;
        int m = adj[u].size();

        auto pre = t;
        for (int i = 1; i < m; i++) cmin(pre[i], pre[i - 1]);
        auto suf = t;
        for (int i = m - 2; i >= 0; i--) cmin(suf[i], suf[i + 1]);

        for (int i = 0; i < m; i++) {
            int v = adj[u][i];
            g[v] = inf;
            if (i > 0) cmin(g[v], pre[i - 1]);
            if (i < m - 1) cmin(g[v], suf[i + 1]);
        }

        ranges::sort(t);
        cmin(f[u], t[0] + t[1]);
        
    } (1, 0);

    [&](this auto&& dfs, int u) -> void {
        for (int v : adj[u]) {
            sum[v] = g[v] + sum[u];
            dfs(v);
        }
    } (1);

    for (int i = 1; i <= q; i++) {
        int x = read(), y = read();
        int res = -1;
        if (dfin[y] <= dfin[x] and dfou[x] <= dfou[y]) {
            res = sum[x] - sum[y];
        }
        cout << res << '\n';
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}