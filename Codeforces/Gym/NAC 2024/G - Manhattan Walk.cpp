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
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int r = read(), c = read(), p = read();

    vector dp(r + 1, vector<double>(c + 1));

    for (int i = r; i >= 1; i--) {
        for (int j = c; j >= 1; j--) {
            if (i == r and j == c) {
                dp[i][j] = 0;
            } else if (i == r) {
                dp[i][j] = 0.25 * p + dp[i][j + 1];
            } else if (j == c) {
                dp[i][j] = 0.25 * p + dp[i + 1][j];
            } else {
                auto a = dp[i][j + 1], b = dp[i + 1][j];
                if (a > b) swap(a, b);

                if (a + p <= b) {
                    dp[i][j] = 0.25 * p + a;
                } else {
                    dp[i][j] = (p - b + a) * 0.5 / p * b
                                + 0.5 * a
                                + (b - a) * 0.5 / p * (a + b) * 0.5;
                }
            }
        }
    }

    printf("%.10lf\n", dp[1][1]);
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}