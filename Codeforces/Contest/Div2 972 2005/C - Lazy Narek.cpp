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

const int inf = 1e9;

void solve() {
    const string t = "narek";

    int n = read(), m = read();

    vector<string> s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    std::array<int, 5> dp;
    dp.fill(-inf);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        auto ndp = dp;

        for (int x = 0; x < 5; x++) {
            int y = x;
            int res = dp[x];

            for (auto c : s[i]) {
                if (c == t[y]) {
                    y++;
                    if (y == 5) {
                        y = 0;
                        res += 5;
                    }
                } else if (t.find(c) != -1) {
                    res--;
                }
            }

            ndp[y] = max(ndp[y], res);

        }

        dp = ndp;
    }

    int ans = 0;
    for (int i = 0; i < 5; i++) {
        ans = max(ans, dp[i] - i);
    }
    cout << ans << "\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}