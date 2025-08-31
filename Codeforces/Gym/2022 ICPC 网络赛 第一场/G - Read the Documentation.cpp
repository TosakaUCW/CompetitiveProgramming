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

int x[5], s[105];
int dp[6][52][35][27][22];

void solve() {
    int n = read(), T = read();

    for (int i = 1; i <= 4; i++) {
        x[i] = x[i - 1] + read();
    }
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + read();
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int a = 0; a <= n / 2 + 1; a++) {
            for (int b = 0; b <= n / 3 + 1; b++) {
                for (int c = 0; c <= n / 4 + 1; c++) {
                    for (int d = 0; d <= n / 5 + 1; d++) {
                        if (a * x[1] + b * x[2] + c * x[3] + d * x[4] > T) break;

                        int res = dp[(i + 5) % 6][a][b][c][d];
                        if (a >= 1 and i >= 1) res = max(res, dp[(i + 4) % 6][a - 1][b][c][d] + s[i] - s[i - 1]);
                        if (b >= 1 and i >= 2) res = max(res, dp[(i + 3) % 6][a][b - 1][c][d] + s[i] - s[i - 2]);
                        if (c >= 1 and i >= 3) res = max(res, dp[(i + 2) % 6][a][b][c - 1][d] + s[i] - s[i - 3]);
                        if (d >= 1 and i >= 4) res = max(res, dp[(i + 1) % 6][a][b][c][d - 1] + s[i] - s[i - 4]);

                        dp[i % 6][a][b][c][d] = res;
                        ans = max(ans, res);
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}