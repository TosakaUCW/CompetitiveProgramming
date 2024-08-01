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

    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();

    vector<vector<int>> g(n + 1);

    for (int i = 2; i <= n; i++) {
        int p = read();
        g[p].pb(i);
    }

    std::function<bool(int, i64)> dfs = [&](int u, i64 val) {
        bool res = 1;

        if (g[u].empty()) return a[u] >= val;

        for (int v : g[u]) {
            i64 nval = std::min(0LL, a[u] - val);

            nval = val - nval;
            nval = std::min(i64(2e9), nval);

            res &= dfs(v, nval);
        }

        return res;

    };

    int res = -1;
    for (i64 L = a[1], R = 2e9; L <= R; ) {
        i64 mid = L + R >> 1;

        // cout << L << ' ' << R << '\n';

        a[1] -= mid;
        if (dfs(1, 0)) res = mid, L = mid + 1;
        else R = mid - 1;
        a[1] += mid;
    }

    cout << res << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}