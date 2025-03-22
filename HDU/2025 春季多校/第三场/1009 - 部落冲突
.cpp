#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second
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
    int n, q;
    cin >> n >> q;

    vector<int> f(n + 1), g(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) f[i] = g[i] = a[i] = i;
    DSU dsu(n + 1);

    while (q--) {
        int opt; cin >> opt;
        int x, y;
        if (opt == 1) {
            cin >> x >> y;
            x = g[x], y = g[y];

            dsu.merge(x, y);
        } else if (opt == 2) {
            cin >> x >> y;
            y = g[y];

            a[x] = dsu.find(y);
        } else if (opt == 3) {
            cin >> x >> y;
            x = g[x], y = g[y];

            swap(g[f[x]], g[f[y]]);
            swap(f[x], f[y]);
        } else {
            cin >> x;
            cout << f[dsu.find(a[x])] << '\n';
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    return 0;
}
