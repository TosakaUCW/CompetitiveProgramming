#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int inf = 1e9;

void solve() {
    int n = read(), m = read(), K = read();

    vector a(n + 1, vector<int>(m + 1));
    vector b(n + 1, vector<int>(m + 1, inf));
    vector f(K + 1, inf);

    for (int i = 1; i <= n; i++) {
        int x = 0;
        for (int j = 1; j <= m; j++) {
            a[i][j] = read();
            x += a[i][j];
        }

        b[i][x] = 0;
        for (int j = 1; j <= m; j++) {
            int y = 0;
            for (int k = j; k <= m; k++) {
                y += a[i][k];
                b[i][x - y] = min(b[i][x - y], k - j + 1);
            }
        }
    }

    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = K; j >= 0; j--) {
            f[j] += b[i][0];

            for (int k = j - 1; k >= 0; k--) {
                f[j] = min(f[j], f[k] + b[i][j - k]);
            }
        }
    }

    int ans = inf;
    for (int i = 0; i <= K; i++) {
        ans = min(ans, f[i]);
    }

    cout << ans;
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}