#include <bits/stdc++.h>
using i64 = long long;
using ull = unsigned long long;
using i128 = __int128;
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
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int n = read();

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        a[i] = read();
        b[i] = read();
    }

    auto ta = a, tb = b;
    ranges::sort(ta);
    ranges::sort(tb);
    for (auto &x : a) x = ranges::lower_bound(ta, x) - ta.begin();
    for (auto &x : b) x = ranges::lower_bound(tb, x) - tb.begin();

    vector<int> deg(2 * n);
    vector<vector<pii>> g(2 * n);
    for (int i = 0; i < n; i++) {
        int u = a[i];
        int v = b[i] + n;

        deg[u]++, deg[v]++;
        g[u].eb(v, i);
        g[v].eb(u, i);
    }

    int s = 0;
    while (s < 2 * n and deg[s] % 2 != 1) s++;
    if (s == 2 * n) {
        s = 0;
        while (!deg[s]) s++;
    }

    int cnt = 0;
    for (int i = 0; i < 2 * n; i++) cnt += deg[i] % 2;

    if (cnt > 2) {
        cout << "NO\n";
        return;
    }

    vector<int> ans;
    vector<int> cur(2 * n);
    vector<int> vis(n);
    auto dfs = [&](this auto &&self, int u) -> void {
        for (int &k = cur[u]; k < g[u].size(); k++) {
            auto [v, i] = g[u][k];
            if (!vis[i]) {
                vis[i] = 1;
                self(v);
                ans.eb(i);
            }
        }
    };
    dfs(s);

    if (ans.size() != n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto x : ans) {
        cout << x + 1 << " \n"[x == ans.back()];
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}