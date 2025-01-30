#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }

/*
[a1, a2, ... , an]
[a2 - a1, a3 - a2, ... , an - an-1]
[a3 - 2a2 + a1, a4 - 2a3 + a2, ... an - 2an-1 + an-2]
a1 - a2 - a3 - a4 + an
*/

void solve() {
    int n = read();
    vector<int> l(n), r(n), a(n);
    for (int i = 0; i < n; i++) {
        l[i] = read(), r[i] = read();
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u = read() - 1;
        int v = read() - 1;
        g[u].eb(v), g[v].eb(u);
    }

    int ans = 0;

    auto dfs = [&](this auto&& self, int u, int fa) -> void {
        int mx = l[u];
        for (int v : g[u]) {
            if (v == fa) continue;
            self(v, u);
            mx = max(mx, a[v]);
        }

        a[u] = min(mx, r[u]);
        for (int v : g[u]) {
            if (v == fa) continue;
            ans += max(0ll, a[v] - a[u]);
        }
    };
    dfs(0, -1);

    cout << ans + a[0] << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
