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

int dp[61][2][2][2];

void solve() {
    int m = read(), L = read();

    vector<int> a(m);
    for (auto &x : a) x = read();

    memset(dp, 0, sizeof dp);

    dp[60][0][0][0] = 1;
    for (int i = 59; i >= 7; i--) {
        int w = (L >> i & 1);

        for (int o : {0, 1}) {
            for (int l : {0, 1}) {
                for (int x : {0, 1}) {
                    if (!dp[i + 1][o][l][x]) continue;

                    for (int y = 0; y < (o | w) + 1; y++) {
                        int no = o | (y < w);
                        int nl = y == 0 ? 0 : l ^ 1;
                        int nx = x ^ y;
                        dp[i][no][nl][nx] += dp[i + 1][o][l][x];
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 127; i++) {

        // high xor low = a[0]
        // high = a[0] xor low
        int d = (__builtin_popcount(i) ^ a[0]) & 1;

        for (int l : {0, 1}) {
            int ok = 1;
            for (int j = 1; j < m and ok; j++) {
                int k = i + j;
                if (k & 128) k = 128 * (l ^ 1) + (k & 127);
                int nd = (__builtin_popcount(k) ^ a[j]) & 1;
                ok &= (nd == d);
            }
            if (ok) {
                ans += dp[7][1][l][d];
                if (i <= (L & 127)) ans += dp[7][0][l][d];
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}