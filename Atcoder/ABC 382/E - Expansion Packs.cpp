#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read();
    int m = read();

    // int ans = 0;
    vector<double> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = read() * 1.0 / 100;
    }

    vector<double> dp(n + m + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        vector<double> ndp(n + 1 + m);
        ndp[0] = dp[0] * (1 - a[i]);
        for (int j = 1; j <= i; j++) {
            ndp[j] = dp[j] * (1 - a[i]) + dp[j - 1] * a[i];
        }
        dp = std::move(ndp);
    }

    // for (int i = 0; i <= n; i++) {
    //     cout << dp[i] << " \n"[i == n];
    // }

    vector<double> f(m + n + 1);

    for (int i = 0; i <= m; i++) {
        double t = 1;
        for (int j = 1; j < i; j++) {
            t += dp[j] * f[i - j];
        }
        f[i] = t / (1 - dp[0]);
    }

    // cout << f[m];
    printf("%.16f", f[m]);
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}