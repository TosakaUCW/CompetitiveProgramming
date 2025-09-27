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
const int inf = 1e18;

void solve() {
    int n = read(), m = read();
    int k = read(), T = read();

    vector v(n, vector(k + 1, 0ll));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            v[i][j] = read();
        }
    }

    vector t(m, 0ll);
    vector val(m, vector(n, 0ll));

    for (int i = 0; i < m; i++) {
        int k = read();
        t[i] = read();

        for (int j = 0; j < k; j++) {
            int x = read() - 1, y = read();
            val[i][x] = y;
        }
    }

    int maxS = 1 << n;
    vector dp(T + 1, vector(maxS, -inf));
    dp[0][0] = 0;


    vector ans(T + 1, 0ll);
    for (int i = 0; i < m; i++) {
        for (int p = 0; p + t[i] <= T; p++) {

            auto ndp = dp[p];
            int np = p + t[i];

            for (int s = 0; s < maxS; s++) {
                for (int j = 0; j < n; j++) {
                    if ((s >> j) & 1) continue;

                    int ns = s | (1 << j);
                    ndp[ns] = max(ndp[ns], ndp[s] + v[j][val[i][j]]);
                }
            }

            for (int s = 0; s < maxS; s++) {
                dp[np][s] = max(dp[np][s], ndp[s]);
            }
            ans[np] = max(ans[np], dp[np][maxS - 1]);
        }
    }
    
    for (int i = 0; i < n; i++) ans[0] += v[i][0];
    for (int i = 1; i <= T; i++) ans[i] = max(ans[i], ans[i - 1]);
    for (int i = 1; i <= T; i++) cout << ans[i] << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}