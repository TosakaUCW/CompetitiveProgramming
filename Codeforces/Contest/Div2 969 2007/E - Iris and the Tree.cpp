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
    int n = read(), w = read();

    vector<int> p(n);
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        p[i] = read();
        p[i]--;
        g[p[i]].eb(i);
    }

    int timer = 0;

    vector<vector<int>> f(n);
    vector<int> cnt(n);

    std::function<void(int)> dfs = [&](int u) {
        timer++;
        for (int v : g[u]) {
            f[v].eb(timer - 1), cnt[timer - 1]++;
            dfs(v);
            f[v].eb(timer - 1), cnt[timer - 1]++;
        }
    };
    dfs(0);

    int sum = 0, tot = n;
    for (int i = 1; i < n; i++) {
        int x = read(), y = read();
        x--, sum += y;

        for (auto j : f[x]) {
            cnt[j]--;
            if (cnt[j] == 0) {
                tot--;
            }
        }

        cout << (w - sum) * tot + 2 * sum << " \n"[i == n - 1];
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}