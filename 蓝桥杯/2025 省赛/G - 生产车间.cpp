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
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();
    
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        g[u].eb(v), g[v].eb(u);
    }

    using dp = bitset<1001>;

    auto dfs = [&](auto self, int u, int fa) -> dp {
        dp f;
        f[0] = 1;
        if (g[u].size() == 1 and u != 1) f[a[u]] = 1;

        for (int v : g[u]) {
            if (v == fa) continue;

            auto g = self(self, v, u);
            auto nf = f;
            for (int i = 0; i <= a[u]; i++) {
                if (!f[i]) continue;
                for (int j = 0; i + j <= a[u]; j++) {
                    if (!g[j]) continue;
                    nf[i + j] = 1;
                }
            }

            f = move(nf);
        }
        return f;
    };

    auto res = dfs(dfs, 1, 0);
    for (int i = a[1]; i >= 0; i--) {
        if (res[i]) {
            cout << i << '\n';
            break;
        }
    }
}

signed main() {
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    // int T; cin >> T;
    int T = 1;
    for (; T--; solve());
    // solve();
    return 0;
}