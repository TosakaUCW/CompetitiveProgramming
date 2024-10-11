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
    int n = read();

    vector<string> s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int la = s[i].size();
            int lb = s[j].size();

            vector dp(la + 1, vector<int>(lb + 1));

            for (int x = la - 1; x >= 0; x--) {
                for (int y = lb - 1; y >= 0; y--) {

                    if (s[i][x] == s[j][y]) {
                        dp[x][y] = 1 + dp[x + 1][y + 1];
                    }

                    ans = max(ans, dp[x][y]);
                }
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