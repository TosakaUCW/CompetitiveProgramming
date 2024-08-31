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

    vector<int> a(n + 1);
    for (int i = 0; i < m; i++) {
        int l = read(), r = read();
        a[r] = l;
    }

    vector f(n + 1, vector<int>(n + 1, -1e9));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            int p = a[i] - 1, len = i - a[i] + 1;
            for (int k = 1; k < len; k++) {
                for (int j = 0; j <= p; j++) {
                    f[i][j + k] = max(f[i][j + k], f[p][j] + j * (len - k));
                }
            }
        } else {
            f[i][0] = f[i - 1][0];
            for (int j = 1; j <= i; j++) {
                f[i][j] = max(f[i - 1][j - 1], f[i - 1][j] + j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, f[n][i] + i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2);
    }
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}