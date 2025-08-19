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
    int n = read(), k = read();

    vector<int> w(n + 1);
    vector<int> c(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) w[i] = read();
    for (int i = 1; i <= n; i++) c[i] = read();
    for (int i = 1; i < n; i++) {
        int x = read(), y = read();
        g[x].eb(y), g[y].eb(x);
    }

    vector<set<int>> s(n + 1);
    int ans = 0;

    auto color = [&](this auto&& self, int u, int fa) -> void {
        c[u] = c[fa];
        for (int v : g[u]) {
            if (v == fa) continue;
            if (c[v]) continue;
            self(v, u);
        }
    };

    auto dfs = [&](this auto&& self, int u, int fa) -> void {
        vector<int> a;

        for (auto v : g[u]) {
            if (v == fa) continue;
            self(v, u);
            if (s[u].size() < s[v].size()) {
                swap(s[u], s[v]);
            }
            for (auto x : s[v]) {
                if (s[u].contains(x)) {
                    a.eb(x);
                } else {
                    s[u].insert(x);
                }
            }
        }

        ranges::sort(a);
        a.erase(unique(a.begin(), a.end()), a.end());

        if (a.size() > 1 or (a.size() == 1 and c[u] and a[0] != c[u])) {
            ans += w[u];
        }

        if (c[u]) {
            s[u].insert(c[u]);
        } else if (!a.empty()) {
            c[u] = a[0];
        } else if (!s[u].empty()) {
            c[u] = *s[u].begin();
        }

        if (c[u]) {
            for (auto v : g[u]) {
                if (v == fa) continue;
                if (c[v]) continue;
                color(v, u);
            }
        }
    };
    dfs(1, 0);

    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
        if (!c[i]) c[i] = 1;
        cout << c[i] << " \n"[i == n];
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}