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

    auto check = [&](int u) {
        int x = u;
        for (auto rt : g[u]) {
            if (g[rt].size() == 2) {
                x = rt;
                rt = g[rt][0] == u ? g[rt][1] : g[rt][0];
            }
            for (auto p : g[rt]) {
                if (p == x) continue;
                if (g[p].size() != 1) return false;
            }
        }
        return true;
    };

    for (int u = 1; u <= n; u++) {
        if (g[u].size() != 2) continue;
        if (check(u)) {
            puts("Yes");
            return;
        } 
    }

    puts("No");

}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}