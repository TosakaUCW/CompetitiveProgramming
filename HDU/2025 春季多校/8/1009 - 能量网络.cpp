#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;

const int INF = 1 << 30;
using pii = pair<int, int>;

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

struct Beam { int x, y, z; };
struct Edge { int u, v, w; };

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n + 1), y(n + 1), z(n + 1);
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i] >> z[i];

    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) cin >> a[i] >> b[i];

    vector<Beam> c(m);
    for (int i = 0; i < m; i++) {
        c[i].x = x[a[i]] + x[b[i]];
        c[i].y = y[a[i]] + y[b[i]];
        c[i].z = z[a[i]] + z[b[i]];
    }

    vector<Edge> edges;  edges.reserve(3LL * m);

    vector<int> idx(m);
    iota(idx.begin(), idx.end(), 0);

    auto go = [&](auto get) {
        sort(idx.begin(), idx.end(), [&](int i, int j){ 
            return get(c[i]) < get(c[j]); 
        });

        for (int k = 0; k + 1 < m; k++) {
            int u = idx[k], v = idx[k + 1];
            int dx = llabs(c[u].x - c[v].x);
            int dy = llabs(c[u].y - c[v].y);
            int dz = llabs(c[u].z - c[v].z);
            edges.pb({u, v, min({dx, dy, dz})});
        }
    };
    go([](auto b) { return b.x; });
    go([](auto b) { return b.y; });
    go([](auto b) { return b.z; });

    sort(edges.begin(), edges.end(), [&](auto i, auto j) {
        return i.w < j.w;
    });
    DSU dsu(m);
    int ans = 0;
    int k = 0;
    for (auto &[u, v, w]: edges) {
        if (dsu.merge(u, v)) {
            ans += w;
            if (++k == m - 1) break;
        }
    }
    cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}