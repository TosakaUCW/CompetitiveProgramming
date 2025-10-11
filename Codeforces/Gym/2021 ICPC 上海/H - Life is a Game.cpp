#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
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
    int q = read();

    vector<int> a(n * 2 + 1);
    for (int i = 1; i <= n; i++) a[i] = read();
    
    vector<tuple<int, int, int>> edge(m);
    for (auto &[u, v, w] : edge) {
        u = read(), v = read(), w = read();
    }
    ranges::sort(edge, [&](auto i, auto j) {
        return get<2>(i) < get<2>(j);
    });

    int tot = n;
    DSU dsu(2 * n + 1);
    vector f(2 * n + 1, vector(25, 0ll));
    auto need = f;
    for (auto [u, v, w] : edge) {
        u = dsu.find(u);
        v = dsu.find(v);
        if (u == v) continue;

        tot++;
        a[tot] = a[u] + a[v];
        dsu.merge(tot, u), dsu.merge(tot, v);
        f[u][0] = f[v][0] = tot;
        need[u][0] = w - a[u];
        need[v][0] = w - a[v];
    }
    n = tot;
    f[n][0] = n;
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i <= n; i++) {
            f[i][j] = f[f[i][j - 1]][j - 1];
            need[i][j] = max(need[i][j - 1], need[f[i][j - 1]][j - 1]);
        }
    }

    while (q--) {
        int x = read(), k = read();
        for (int i = 20; i >= 0; i--) {
            if (need[x][i] <= k) x = f[x][i];
        }
        cout << k + a[x] << '\n';
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}