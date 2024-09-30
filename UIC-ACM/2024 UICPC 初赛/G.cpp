#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr, std::cin, std::cout, std::string, std::vector;
using std::max, std::min, std::swap;
int read(int x = 0, bool f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 310;
int n, m;
int dp[N][N];
string s;

void solve() {
    cin >> s >> m;
    n = s.size();
    s = ' ' + s;

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            dp[i][j] = j - i + 1;

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            if (l == 2) {
                if (s[i] == 'o' and s[j] == 'f')
                    dp[i][j] = 0;
            } else {
                for (int k = i; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                if (s[i] == 'o') {
                    for (int k = i + 1; k <= j; k++) {
                        if (s[k] == 'f' and !dp[i + 1][k - 1])
                            dp[i][j] = min(dp[i][j], max(dp[k + 1][j] - m, 0LL));
                    }
                }
            }
        }
    }

    cout << dp[1][n];
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}