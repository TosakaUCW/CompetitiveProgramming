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

    vector<std::array<int, 2>> a(m);
    for (int i = 0; i < m; i++) {
        int l = read(), r = read();
        a[i] = {l, r};
    }
    std::sort(a.begin(), a.end());

    vector f(n + 1, vector<int>(n + 1, -1e9));
    f[0][0] = 0;


    for (int l = 1, j = 0; l <= n; l++) {
        if (j < m and a[j][0] == l) {
            int r = a[j][1], i = j++;

            for (; j < m and a[j][0] <= r; j++) {
                r = max(r, a[j][1]);
            }

            int L = l, R = r;

            for (int k = i; k < j; k++) {
                L = max(L, a[k][0]);
                R = min(R, a[k][1]);
            }

            if (L >= R) {
                cout << "-1\n";
                return;
            }

            int p = L - 1, len = R - L + 1;
            f[p][0] = f[l - 1][0];

            for (int j = 1; j <= p; j++) {
                f[p][j] = f[l - 1][j] + j * (L - l);
            }

            for(int k = 1; k < len; ++ k) {
                for(int j = 0; j <= p; ++ j) {
                    f[R][j + k] = max(f[R][j + k], f[p][j] + j * (len - k));
                }
            }
            for(int j = 1; j <= r; ++ j) {
                if(j - r + R >= 0)
                    f[r][j] = f[R][j - r + R];
            }

            l = r;

        } else {
            f[l][0] = f[l - 1][0];
            for (int j = 1; j <= l; j++) {
                f[l][j] = max(f[l - 1][j - 1], f[l - 1][j] + j);
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