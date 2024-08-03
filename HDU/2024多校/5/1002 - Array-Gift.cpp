#include <bits/stdc++.h>
#define int long long
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
void solve() {
    // std::mt19937 rng(time(0));
    int n = read();
    // int n = rng() % 10 + 1;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        // a[i] = rng() % 10 + 1;
        // cout << a[i] << " \n"[i == n];
    }
    // std::sort(a.begin() + 1, a.end());

    int m = n, k = 0;
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!vis[i] and a[j] % a[i] == 0 and i != j) {
                vis[j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            k++;
            m--;
        }
    }

    int ans = m + 1;

    for (int i = 1; i <= n; i++) {
        int gcd = 0;
        for (int j = 1; j <= n; j++) {
            if (vis[j] or i == j) continue;
            gcd = std::__gcd(gcd, a[j]);
        }
        if (gcd >= a[i]) ans = m;
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;

        for (int j = 1; j <= n; j++) {
            if (vis[j]) continue;
            if (j == i) continue;
            int x = a[i] % a[j];
            // a[i] -> a[i] mod a[j]
            if (x == 0 or a[j] % x != 0) continue;
            bool flag = 1;
            for (int k = 1; k <= n; k++) {
                if (vis[k] or k == i or k == j) continue;

                if (a[k] % x != 0) flag = 0;
            }
            if (flag) ans = std::min(ans, m);
        }

        bool flag = 1;
        for (int j = 1; j <= n; j++) {
            if (vis[j] or i == j) continue;
            if (a[j] % a[i] != 0) flag = 0;
        }
        if (flag) ans = std::min(ans, m - 1);
    }

    cout << ans + k << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}