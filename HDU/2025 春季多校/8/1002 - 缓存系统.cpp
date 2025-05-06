#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;

const int INF = 1ll << 60;

void solve() {
    int n, m, X;
    cin >> n >> m >> X;

    vector prev(n, vector(m + 1, 0ll));
    vector pres(n, vector(m + 1, 0ll));

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int s, a;
            cin >> s >> a;

            prev[i][j] = prev[i][j - 1] + s;
            pres[i][j] = pres[i][j - 1] + a;
            ans += a;
        }
    }

    vector dp(X + 1, -INF);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        vector ndp(X + 1, -INF);

        for (int k = 0; k <= m; ++k) {
            int v = prev[i][k];
            int w = pres[i][k];
            for (int x = v; x <= X; ++x) {
                if (dp[x - v] != -INF)
                    ndp[x] = max(ndp[x], dp[x - v] + w);
            }
        }
        dp = move(ndp);
    }

    int res = 0;
    for (int i = 0; i <= X; i++) {
        res = max(res, dp[i]);
    }

    cout << ans - res << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}