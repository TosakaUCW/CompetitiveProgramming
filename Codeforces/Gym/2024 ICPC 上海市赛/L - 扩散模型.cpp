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
    int n = read();
    int m = read();
    int k = read();

    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int k = read(); k--; ) {
            int v = read();
            g[i].eb(v);
        }
    }

    vector<int> tag(n + 1);
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        tag[v] = 1;
    }

    vector<int> flag(n + 1);
    for(int i = 0;i < k;++i) {
        int v = read();
        flag[v] = 1;
    }

    vector<int> dp(n + 1, -1);
    [&](this auto&& self, int u) {
        if (flag[u]) { dp[u] = 0; return; }
        if (g[u].empty()) return;

        bool f = 1;
        int sum = 0, id = 0;
        for (int v : g[u]) {
            self(v);
            if (dp[v] < 0) {
                f = 0;
            } else {
                sum += dp[v];
                if (tag[v] and (!id or dp[id] > dp[v])) {
                    id = v;
                }
            }
        }

        if (f) {
            dp[u] = sum;
            if (id) cmin(dp[u], dp[id] + 1);
        } else {
            if (id) dp[u] = dp[id] + 1;
        }
    } (1);
    cout << dp[1] << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}