#include <bits/stdc++.h>
using i64 = long long;
#define int long long

#define pb push_back
using std::max, std::min;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read(), k = read();
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();

    int m = (n - 1) % k + 1;
    
    auto judge = [&](int x) {
        vector<int> dp(m + 1, -1e9);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int j = (i - 1) % k + 1;
            if (j > m) continue;
            dp[j] = max(dp[j], dp[j - 1] + (a[i] >= x ? 1 : -1));
        }
        return dp[m] > 0;
    };

    int ans = 1;
    for (int L = 1, R = 1e9; L <= R; ) {
        int mid = L + R >> 1;
        if (judge(mid)) ans = mid, L = mid + 1;
        else R = mid - 1;
    }
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}