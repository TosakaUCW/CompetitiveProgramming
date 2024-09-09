#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read(), m = read();


    vector<int> l(n), r(n), t(n);
    for (int i = 0; i < n; i++) {
        l[i] = read();
        r[i] = read();
        t[i] = read();
    }

    vector<int> dp(m + 1, -1);
    dp[1] = m;
    for (int i = n - 1; i >= 0; i--) {
        vector<int> ndp(m + 1, -1);
        for (int j = 1; j <= m; j++) {
            if (dp[j] >= j) {
                int L = max(l[i], j);
                int R = min(r[i], dp[j]);

                if (R - L + 1 >= t[i]) {
                    ndp[L] = max(ndp[L], R - t[i]);
                    ndp[L + t[i]] = max(ndp[L + t[i]], R);
                }
            }
        }
        dp = std::move(ndp);
    }

    for (int i = 1; i <= m; i++) {
        if (dp[i] >= i - 1) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}