#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
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
// const int inf = 1e18;

void solve() {
    int n = read();

    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u = read();
        int v = read();

        g[u].eb(v), g[v].eb(u);
    }

    vector<int> vis(n + 1), used(n + 1);
    vector<array<int, 3>> ans;
    vector<int> p(n + 1, -1);

    while (1) {
        if (count(used.begin() + 1, used.end(), 0) == 0) break;
        vis.assign(n + 1, 0);

        auto dfs = [&](this auto&& self, int u, int fa) -> pii {
            pii res = {1, u};
            p[u] = fa;
            vis[u] = 1;

            for (int v : g[u]) {
                if (v == fa or used[v]) continue;
                auto t = self(v, u);
                t.first += 1;
                res = max(res, t);
            }

            return res;
        };

        for (int i = 1; i <= n; i++) {
            if (used[i] or vis[i]) continue;

            auto [d1, x] = dfs(i, -1);
            auto [d2, y] = dfs(x, -1);
            ans.pb({d2, max(x, y), min(x, y)});

            while (y != -1) {
                used[y] = 1;
                y = p[y];
            }
        }
    }

    ranges::sort(ans, [&](auto i, auto j) {
        if (i[0] != j[0]) return i[0] > j[0];
        if (i[1] != j[1]) return i[1] > j[1];
        return i[2] > j[2];
    });
    for (auto [x, y, z] : ans) {
        cout << x << " " << y << " " << z << " ";
    }
    cout << "\n";
}

signed main() {
    for (int T = read(); T--; solve());
    return 0;
}