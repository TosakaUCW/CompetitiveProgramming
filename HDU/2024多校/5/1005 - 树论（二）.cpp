#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
struct DSU 
{
    std::vector<int> f, siz;
    DSU() {}
    DSU(int n) { init(n); }
    void init(int n) { f.resize(n), std::iota(f.begin(), f.end(), 0), siz.assign(n, 1); }
    int find(int x) { while (x != f[x]) x = f[x] = f[f[x]]; return x; }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) 
    {
        x = find(x), y = find(y);
        if (x == y) return false;
        siz[x] += siz[y], f[y] = x;
        return true;
    }
    int size(int x) { return siz[find(x)]; }
};

void solve() {
    int n = read();

    DSU dsu(n + 1);

    using pii = std::pair<int, int>;
    vector<vector<pii>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        g[u].pb({v, i}), g[v].pb({u, i});
    }

    vector<int> dep(n + 1), par(n + 1), idx(n + 1);
    std::function<void(int, int)> dfs = [&](int u, int f) {
        for (auto [v, id] : g[u]) {
            if (v != f) {
                dep[v] = dep[u] + 1;
                par[v] = u;
                idx[v] = id;
                dfs(v, u);
            }
        }
    };
    dfs(1, 0);

    vector<int> ans(n + 1);
    for (int d = n / 2; d >= 1; d--) {
        int x = dsu.find(d);
        for (int j = d + d; j <= n; j += d) {
            int y = dsu.find(j);
            
            while (x != y) {
                if (dep[x] > dep[y]) std::swap(x, y);
                ans[idx[y]] = d;
                dsu.merge(par[y], y);
                y = dsu.find(y);
            }
        }
    }

    for (int i = 1; i <= n - 1; i++)
        cout << ans[i] << " \n"[i == n - 1];
}

signed main() {
    int size(256<<20); //256M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    for (int T = read(); T--; solve());
    // solve();
    exit(0);
    return 0;
}