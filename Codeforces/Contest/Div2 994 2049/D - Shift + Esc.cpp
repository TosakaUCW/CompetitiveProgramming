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
    int k = read();

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            a[i][j] = read();
        }
    }
    
    vector dp(m, vector<int>(m, INF));

    for (int s = 0; s < m; s++) {
        dp[0][s] = k * s + a[0][s % m];
    }

    for (int j = 1; j < m; j++) {
        for (int s = 0; s < m; s++) {
            if (dp[j - 1][s] + a[0][(j + s) % m] < dp[j][s]) {
                dp[j][s] = dp[j - 1][s] + a[0][(j + s) % m];
            }
        }
    }

    for (int i = 1; i < n; i++) {

        vector ndp(m, vector<int>(m, INF));
        vector pre(m, INF);

        for (int j = 0; j < m; j++) {
            for (int s = 0; s < m; s++) {
                if (dp[j][s] < pre[j]) {
                    pre[j] = dp[j][s];
                }
            }
        }

        for (int s = 0; s < m; s++) {
            for (int j = 0; j < m; j++) {
                int val = a[i][(j + s) % m];
                if (j == 0) {
                    ndp[j][s] = min(ndp[j][s], pre[j] + k * s + val);
                } else {
                    ndp[j][s] = min({
                        ndp[j][s], 
                        pre[j] + k * s + val, 
                        ndp[j - 1][s] + val
                    });
                }
            }
        }

        dp = std::move(ndp);
    }
        
    int ans = INF;
    for (int s = 0; s < m; s++) {
        ans = min(ans, dp[m - 1][s]);
    }
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
