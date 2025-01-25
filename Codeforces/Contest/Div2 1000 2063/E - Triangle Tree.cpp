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

void solve() {
    int n = read();
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u = read() - 1;
        int v = read() - 1;
        g[u].eb(v), g[v].eb(u);
    }

    int ans = 0;

    vector<int> dep(n), siz(n);
    auto dfs = [&](this auto&& self, int u, int f) -> void {
        int cnt = 0, sum = 0;
        siz[u] = 1;
        for (int v : g[u]) {
            if (v == f) continue;
            dep[v] = dep[u] + 1;
            self(v, u);
            siz[u] += siz[v];

            cnt += siz[v] * sum;
            sum += siz[v];
        }
        ans -= 2 * (cnt + siz[u]) * dep[u];
        ans -= cnt;
    };
    dfs(0, -1);

    ranges::sort(dep);
    for (int i = 0; i < n; i++) {
        ans += dep[i] * (n + 1);
        ans += dep[i] * (n - 2 * i - 1);
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
