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
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int n = read();
    int k = read();
    double p; cin >> p;

    if (k > 165) {
        double ans = n / (1 - p);
        printf("%.12lf\n", ans);
        return;
    }

    vector<double> pw(n + 1);
    vector dp(k + 1, vector(n + 1, (double)(0.0)));

    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] / (1 - p);
    }
    for (int i = 0; i <= k; i++) {
        for (int j = n - 1; j >= 0; j--) {
            dp[i][j] = dp[i][j + 1] + pw[j + 1];
            if (i != 0) {
                dp[i][j] = min(dp[i][j], 1 + p * dp[i - 1][j] + (1 - p) * dp[i][j + 1]);
            }
        }
    }
    printf("%.12lf\n", dp[k][0]);
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}