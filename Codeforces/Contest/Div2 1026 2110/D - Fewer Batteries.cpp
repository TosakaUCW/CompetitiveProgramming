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
    int m = read();

    vector<int> b(n);
    for (int &x : b) x = read();

    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; i++) {
        int u = read() - 1;
        int v = read() - 1;
        int w = read();
        adj[u].eb(v, w);
    }

    auto judge = [&](int lim) -> bool {
        vector<int> f(n, -1);
        f[0] = min(lim, b[0]);
        for (int u = 0; u < n; u++) {
            for (auto [v, w] : adj[u]) {
                if (f[u] >= w) {
                    f[v] = max(f[v], min(lim, f[u] + b[v]));
                }
            }
        }
        return f[n - 1] != -1;
    };

    int ans = -1;
    for (int L = 0, R = 1e18; L <= R; ) {
        int mid = L + R >> 1;
        if (judge(mid)) ans = mid, R = mid - 1;
        else L = mid + 1;
    }
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}