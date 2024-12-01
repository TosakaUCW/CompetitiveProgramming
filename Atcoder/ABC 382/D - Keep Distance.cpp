#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read();
    int m = read();

    int ans = 0;
    vector<int> a(n + 1);
    auto dfs1 = [&](auto&& self, int now) {
        if (now == n + 1) {
            ans++;
            return;
        }

        if (now == 1) {
            for (int i = 1; i <= m; i++) {
                a[now] = i;
                if (i + (n - now) * 10 <= m) self(self, now + 1);
            }
        } else {
            for (int i = max(1, a[now - 1] + 10); i <= m; i++) {
                a[now] = i;
                if (i + (n - now) * 10 <= m) self(self, now + 1);
            }    
        }
    };
    dfs1(dfs1, 1);
    a.assign(n + 1, 0);
    cout << ans << '\n';

    auto dfs2 = [&](auto&& self, int now) {
        if (now == n + 1) {
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " \n"[i == n];
            }
            return;
        }

        if (now == 1) {
            for (int i = 1; i <= m; i++) {
                a[now] = i;
                if (i + (n - now) * 10 <= m) self(self, now + 1);
            }
        } else {
            for (int i = max(1, a[now - 1] + 10); i <= m; i++) {
                a[now] = i;
                if (i + (n - now) * 10 <= m) self(self, now + 1);
            }    
        }
    };

    dfs2(dfs2, 1);
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}