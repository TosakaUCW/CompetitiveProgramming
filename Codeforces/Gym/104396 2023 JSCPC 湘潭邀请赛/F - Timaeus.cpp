#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap;
using std::array;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int A = read(), B = read();
    double P = read(), Q = read();
    P /= 100, Q /= 100;

    std::cout << std::fixed << std::setprecision(15);


    if (B == 1) {
        double x = A * (P * 2 + (1 - P) * 1);
        double y = A * (1.0 / (1 - Q));
        cout << max(x, y);
        return;
    }

    vector<double> dp(A + 1);
    for (int i = B; i <= A; i++) {
        dp[i] = max(
            P * (dp[i - B] + 2) + (1 - P) * (dp[i - B] + 1),
            Q * (dp[i - B + 1] + 1) + (1 - Q) * (dp[i - B] + 1)
        );
        // cout << dp[i] << "\n";
    }

    cout << dp[A] << "\n";
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}