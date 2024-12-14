#include <bits/stdc++.h>
using i64 = long long;
#define int i64
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
using std::ostream;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

const int inf = 1e18;

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
    int n = read();
    int m = read();

    vector<vector<int>> g(n + 1);
    std::set<pii> s;

    for (int i = 1; i <= m; i++) {
        int u = read();
        int v = read();
        int c = read();

        if (u > v) swap(u, v);
        if (c) {
            g[u].eb(v), g[v].eb(u);
        } else {
            s.ep(u, v);
        }
    }


    vector<int> path;


    auto check = [&]() {
        int m = path.size();
        DSU dsu(m);

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int u = path[i];
                int v = path[j];
                if (u > v) swap(u, v);
                if (s.find({u, v}) == s.end()) continue;

                dsu.merge(i, j);
            }
        }

        for (int i = 1; i < m; i++) {
            if (!dsu.same(0, i)) {
                return 0;
            }
        }
        return 1;
    };

    int ans = 0;
    vector<int> vis(n + 1);

    auto dfs = [&](this auto&& self, int u, int p) -> void {
        vis[u] = 1;
        path.eb(u);

        if (p > 1) ans += check();
        if (p < 4) {
            for (int v : g[u]) {
                if (vis[v]) continue;
                self(v, p + 1);
            }
        }
        vis[u] = 0;
        path.pop_back();
    };

    for (int i = 1; i <= n; i++) {
        dfs(i, 1);
    }

    cout << ans / 2 + n;
    
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}