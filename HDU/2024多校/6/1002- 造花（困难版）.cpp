#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector, std::cerr;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
struct DSU 
{
    std::vector<int> f, nodecnt, edgecnt;
    DSU() {}
    DSU(int n) { init(n); }
    void init(int n) { f.resize(n), std::iota(f.begin(), f.end(), 0), 
                        nodecnt.assign(n, 1), edgecnt.assign(n, 0); }
    int find(int x) { while (x != f[x]) x = f[x] = f[f[x]]; return x; }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) 
    {
        x = find(x), y = find(y);
        if (x == y) {
            edgecnt[x]++;
            return false;
        }
        nodecnt[x] += nodecnt[y];
        edgecnt[x] += edgecnt[y] + 1;
        f[y] = x;
        return true;
    }
    int nodesiz(int x) { return nodecnt[find(x)]; }
    int edgesiz(int x) { return edgecnt[find(x)]; }
};

void solve(int T) {
    int n = read(), m = read();
    
    vector<std::pair<int, int>> edge;
    vector<vector<int>> g(n + 1);
    vector<int> d(n + 1);

    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        g[u].pb(v), g[v].pb(u);
        edge.emplace_back(u, v);
        d[u]++, d[v]++;
    }

    vector<int> check, ans;

    for (auto [u, v] : edge) {
        int x = 0, y = 0;
        for (auto k : g[u]) {
            if (k == v) continue;
            x = k; break;
        }
        for (auto k : g[v]) {
            if (k == u) continue;
            y = k; break;
        }
        if (x > 0 and y > 0) {
            check.pb(u);
            check.pb(v);
            check.pb(x);
            if (x != y) check.pb(y);
            break;
        }
    }

    for (auto u : check) {

        DSU dsu(n + 1);
        vector<int> d(n + 1);

        for (auto [x, y] : edge) {
            if (x == u or y == u) continue;
            dsu.merge(x, y);
            d[x]++, d[y]++;
        }

        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            if (dsu.nodesiz(i) != dsu.edgesiz(i) + 1) {
                flag = 0;
                break;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (i == u) continue;
            if (d[i] == 1) dsu.nodecnt[dsu.find(i)]--;
        }
        for (int i = 1; i <= n; i++) {
            if (i == u) continue;
            if (dsu.nodesiz(i) > 1) {
                flag = 0;
                break;
            }
        }

        if (flag) ans.pb(u);
    }


    if (check.empty()) {
        for (int i = 1; i <= n; i++) cout << i << " \n"[i == n];
    }
    else if (ans.empty()) cout << "-1\n";
    else {
        std::sort(ans.begin(), ans.end());
        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }
}

signed main() {
    for (int T = read(); T--; solve(T));
    // solve();
    return 0;
}