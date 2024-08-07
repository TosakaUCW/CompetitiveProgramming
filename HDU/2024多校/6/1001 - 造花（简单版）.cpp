#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read();

    vector<vector<int>> g(n + 1);

    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        g[u].pb(v), g[v].pb(u);
    }

    bool flag = 0;
    int rt = 0;

    for (int u = 1; u <= n; u++) {
        if (g[u].size() != 2) continue;

        bool f = 1;

        int rt1 = g[u][0], rt2 = g[u][1];
        int x = 0, y = 0;

        if (g[rt1].size() == 2) {
            x = rt1;
            rt1 = g[rt1][0] == u ? g[rt1][1] : g[rt1][0];
        }
        if (g[rt2].size() == 2) {
            y = rt2;
            rt2 = g[rt2][0] == u ? g[rt2][1] : g[rt2][0];
        }

        for (int p : g[rt1]) {
            if (p == x or p == u) continue;
            if (g[p].size() != 1) {
                f = 0;
                break;
            }
        }
        for (int p : g[rt2]) {
            if (p == y or p == u) continue;
            if (g[p].size() != 1) {
                f = 0;
                break;
            }
        }

        if (f == 1) {
            flag = 1;
            break;
        } 

        // cout << u << rt1 << rt2 << '\n';
    }

    puts(flag ? "Yes" : "No");

}

/*
*/

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}