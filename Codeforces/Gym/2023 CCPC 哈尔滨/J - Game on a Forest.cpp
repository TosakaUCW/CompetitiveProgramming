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
#define fi first
#define se second
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
template <class T> bool cmin(T &a, T b) { return (b < a) ? (a = b, true) : false; }
template <class T> bool cmax(T &a, T b) { return (a < b) ? (a = b, true) : false; }
using pii = pair<int, int>;
using tup = tuple<int, int, int>;
const int inf = 1e18;
const double eps = 1e-9;

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

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();

        g[u].eb(v), g[v].eb(u);
        dsu.merge(u, v);
    }

    auto sg = [&](int x) { return !x ? 0 : 2 - x % 2; };
    int SG = 0;
    for (int i = 1; i <= n; i++) {
        if (dsu.find(i) == i) {
            SG ^= sg(dsu.size(i));
        }
    }

    int ans = 0;
    vector<int> siz(n + 1);
    auto dfs = [&](this auto&& dfs, int u, int fa) -> void {
        siz[u] = 1;
        int tSG = 0;
        for (int v : g[u]) {
            if (v == fa) continue;
            dfs(v, u);
            siz[u] += siz[v];
            tSG ^= sg(siz[v]);
        }

        int all = dsu.size(u);
        int sub = siz[u];

        tSG ^= sg(all - sub);
        if ((SG ^ tSG) == 0) ans++;

        if (fa != 0 and (SG ^ sg(sub) ^ sg(all - sub)) == 0) {
            ans++;
        }
    };

    for (int i = 1; i <= n; i++) {
        if (dsu.find(i) == i) {
            SG ^= sg(dsu.size(i));
            dfs(i, 0);
            SG ^= sg(dsu.size(i));
        }
    }
    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}