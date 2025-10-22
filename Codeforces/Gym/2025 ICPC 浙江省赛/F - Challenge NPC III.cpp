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
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
using tup = tuple<int, int, int>;
const int inf = 1e18;

void solve() {
    int n = read(), m = read(), k = read();

    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) c[i] = read();

    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        g[u].eb(v);
    }

    auto bfs = [&](int col) -> bool {
        queue<tup> q;
        vector vis(n + 1, vector(2, 0));

        for (int i = 1; i <= n; i++) {
            if (c[i] != col) continue;
            q.ep(i, 0, i);
            vis[i][0] = 1;
        }

        while (!q.empty()) {
            auto [u, d, s] = q.front(); q.pop();

            if (d >= k - 1) continue;
            for (auto v : g[u]) {
                if (c[v] == col and v != s) return 0;

                if (!vis[v][0]) {
                    vis[v][0] = s;
                    q.ep(v, d + 1, s);
                } else if (!vis[v][1] and vis[v][0] != s) {
                    vis[v][1] = s;
                    q.ep(v, d + 1, s);
                }
            }
        }
        return 1;
    };

    for (int i = 1; i <= 50; i++) {
        if (!bfs(i)) { cout << "NO\n"; return; }
    }
    cout << "YES\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}