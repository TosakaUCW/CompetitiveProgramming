#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
// using namespace std::views;
// using namespace std::ranges;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
using std::ostream;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second
const int INF = 1e18;

void solve() {
    int n = read();
    int m = read();
    int q = read();

    vector<array<int, 3>> edges(m);
    vector dp(m + 1, vector(n, vector(n, INF)));

    for (auto &[u, v, w] : edges) {
        u = read() - 1;
        v = read() - 1;
        w = read();
    }
    std::ranges::sort(edges, [&](auto x, auto y) {
        return x[2] < y[2];
    });
    
    for (int i = 0; i < n; i++) { 
        dp[0][i][i] = 0;
    }
    for (auto [u, v, w] : edges) {
        dp[0][u][v] = dp[0][v][u] = 1;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[0][i][j] = min(dp[0][i][j], dp[0][i][k] + dp[0][k][j]);
            }
        }
    }
            
    for (int p = 1; p <= m; p++) {
        auto [u, v, _] = edges[p - 1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[p][i][j] = min({
                    dp[p - 1][i][j],
                    dp[p - 1][i][u] + dp[p - 1][v][j],
                    dp[p - 1][i][v] + dp[p - 1][u][j]
                });
            }
        }
    }

    for (int _ = 1; _ <= q; _++) {
        int a = read() - 1;
        int b = read() - 1;
        int k = read();

        int ans = m - 1;
        for (int lo = 0, hi = m - 1; lo <= hi; ) {
            int mid = lo + hi >> 1;
            if (dp[mid + 1][a][b] < k) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << edges[ans][2] << " \n"[_ == q];
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
