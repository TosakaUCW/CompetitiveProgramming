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
using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    int n, k;
    cin >> n >> k;

    vector a(n + 1, vector(k + 1, 0ll));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> a[i][j];
        }
    }

    vector dp(n + 1, vector(k + 1, 0ll));
    vector g(n + 1, vector(k + 1, 0ll));
    for (int j = 1; j <= k; j++) {
        dp[1][j] = a[1][j];

        g[1][j] = max(g[1][j - 1], dp[1][j]);
    }

    for (int i = 2; i <= n; i++) {

        for (int j = 1; j <= k; j++) {
            dp[i][j] = g[i - 1][j] + a[i][j];
            g[i][j] = max(g[i][j - 1], dp[i][j]);
        }
    }


    cout << g[n][k] << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}
