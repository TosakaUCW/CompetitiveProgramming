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
    int n = read(), q = read();

    vector<int> las(n + 1), dp(n + 1);

    for (int i = 1; i <= n; i++) {
        int opt = read(), x = read();

        if (opt == 1) {
            las[i] = x;
            dp[i] = dp[i - 1] + 1;
        } else {
            las[i] = las[i - 1];
            dp[i] = (x + 1) > 2e18 / dp[i - 1] ? (i64)2e18 : dp[i - 1] * (x + 1);
        }
    }

    for (int k; q--; ) {
        k = read();
        while (1) {
            int pos = std::lower_bound(dp.begin(), dp.end(), k) - dp.begin();

            if (dp[pos] == k) {
                cout << las[pos] << " \n"[q == 0];
                break;
            }
            if (k % dp[pos - 1] == 0) {
                cout << las[pos - 1] << " \n"[q == 0];
                break;
            }
            k %= dp[pos - 1];
        }
    }
}

signed main() {
    for (int T = read(); T--; solve());
    return 0;
}