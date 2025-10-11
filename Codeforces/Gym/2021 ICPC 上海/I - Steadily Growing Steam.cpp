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

const int M = 3000;

void solve() {
    int n = read();
    int k = read();

    vector<pii> a(n);
    for (auto &[v, t] : a) {
        v = read(), t = read();
    }

    vector dp(M + 1000, vector(k + 1, -inf));
    dp[0][0] = 0;
    for (auto [v, t] : a) {
        auto ndp = dp;

        for (int w = 0; w <= M; w++) {
            for (int j = 0; j <= k; j++) {

                // if (dp[w][j] == -inf) continue;

                auto upd = [&](int nw, int nj) -> void {
                    nw = abs(nw);
                    ndp[w][j] = max(ndp[w][j], dp[nw][nj] + v);
                };

                upd(w - t, j);
                upd(w + t, j);
                if (j >= 1) upd(w - 2 * t, j - 1);
                if (j >= 1) upd(w + 2 * t, j - 1);
            }
        }

        dp = move(ndp);
    }

    int ans = 0;
    for (int j = 0; j <= k; j++) {
        ans = max(ans, dp[0][j]);
    }
    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}