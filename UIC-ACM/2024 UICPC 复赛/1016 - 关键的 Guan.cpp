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

void solve() {
    int n = read(), m = read(), k = read();

    vector<int> c(m + 1), r(m + 1);
    vector<vector<int>> g(m + 1);

    for (int i = 1; i <= m; i++) {
        c[i] = read();
        g[i].resize(c[i] + 1);
        for (int j = 1; j <= c[i]; j++) {
            g[i][j] = read();
        }

        char ch; cin >> ch;
        r[i] = ch == 'x' ? 0 : 1;
    }

    int ans = 0;
    for (int S = 0; S < (1 << n); S++) {
        bool f = 1;
        for (int i = 1; i <= m; i++) {
            int cnt = 0;
            for (int j = 1; j <= c[i]; j++) {
                if ((S >> (g[i][j] - 1)) & 1) {
                    cnt++;
                }
            }

            if (cnt >= k and !r[i] or cnt < k and r[i]) {
                f = 0;
                break;
            }
        }

        if (f) ++ans;
    }

    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}