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

struct DSU {
    std::vector<int> f, siz;
    DSU() {}
    DSU(int n) { init(n); }
    void init(int n) { f.resize(n), std::iota(f.begin(), f.end(), 0), siz.assign(n, 1); }
    int find(int x) { while (x != f[x]) x = f[x] = f[f[x]]; return x; }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        siz[x] += siz[y], f[y] = x;
        return true;
    }
    int size(int x) { return siz[find(x)]; }
};


void solve() {
    int n = read(), m = read();

    DSU dsu(n + 1);

    for (int i = 1; i <= n; i++) {
        dsu.siz[i] = read();
    }

    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        g[u].eb(v);
        g[v].eb(u);
    }

    vector<int> nod(n + 1), del(n + 1), ans(n + 1);

    for (int i = 1; i <= n; i++) nod[i] = read();

    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i - 1];

        int u = nod[n - i + 1];
        for (auto v : g[u]) {
            if (!del[v]) continue;
            dsu.merge(u, v);
            ans[i] = max(ans[i], dsu.size(u));
        }

        ans[i] = max(ans[i], dsu.size(u));
        del[u] = 1;
    }

    for (int i = n - 1; i >= 1; i--) {
        cout << ans[i] << "\n";
    }
    puts("0");
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}