#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
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
int input() { char u, v; cin >> u >> v; return (u - 48) * 50 + v - 48; }

void solve() {
    int n = read(), l = read(), q = read();

    vector g(n + 1, std::bitset<2005>());
    for (int i = 1; i <= n; i++) g[i][i] = 1;

    vector t(l + 1, vector<int>(n + 1));
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= n; j++) {
            t[i][j] = input();
        }
    }

    vector<int> ans(q);
    vector qry(l + 1, vector<std::array<int, 3>>());
    for (int i = 0; i < q; i++) {
        int a = input(), b = input(), c = input();
        qry[c].pb({a, b, i});
    }

    auto add = [&](int a, int b) {
        if (g[a][b]) return;

        for (int i = 1; i <= n; i++) {
            if (g[i][a]) {
                g[i] |= g[b];
            }
        }
    };

    auto go = [&](const auto &p) {
        vector<int> buk(n + 1);
        int f = 0;
        for (int i = 1; i <= n; i++) {
            if (!buk[p[i]]) buk[p[i]] = 1;
            else if (f) return;
            else f = p[i];
        }

        if (!f) {
            for (int i = 1; i <= n; i++) {
                add(i, p[i]);
            }
        } else {
            int x = 0;
            for (int i = 1; i <= n; i++) {
                if (!buk[i]) x = i;
            }

            for (int i = 1; i <= n; i++) {
                if (p[i] == f) {
                    add(i, x);
                }
            }
        }
    };

    for (int i = 0; i <= l; i++) {
        go(t[i]); 

        for (auto [a, b, idx] : qry[i]) {
            ans[idx] = g[a][b];
        }
    }

    for (int x : ans) cout << x;
    puts("");
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}