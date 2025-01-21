#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
// using namespace std::views;
// using namespace std::ranges;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
using std::ostream;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second
const int INF = 1e18;

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

    DSU dsu(n);

    vector<array<int, 3>> edges(m);
    vector dp(n, vector(n, vector(n, INF)));

    for (auto &[u, v, w] : edges) {
        u = read() - 1;
        v = read() - 1;
        w = read();
    }
    std::ranges::sort(edges, [&](auto x, auto y) {
        return x[2] < y[2];
    });
    
    for (int i = 0; i < n; i++) { 
        dp[0][i][i] = 0;
    }
    for (auto [u, v, w] : edges) {
        dp[0][u][v] = dp[0][v][u] = 1;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[0][i][j] = min(dp[0][i][j], dp[0][i][k] + dp[0][k][j]);
            }
        }
    }
            
    int id = 1;
    vector vals(n, 0);
    for (int p = 1; p <= m; p++) {
        auto [u, v, w] = edges[p - 1];

        if (dsu.same(u, v)) {
            continue;
        }

        dsu.merge(u, v);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[id][i][j] = min({
                    dp[id - 1][i][j],
                    dp[id - 1][i][u] + dp[id - 1][v][j],
                    dp[id - 1][i][v] + dp[id - 1][u][j]
                });
            }
        }

        vals[id] = w;
        id++;
    }

    for (int _ = 1; _ <= q; _++) {
        int a = read() - 1;
        int b = read() - 1;
        int k = read();

        int ans = m;
        for (int lo = 0, hi = n - 1; lo <= hi; ) {
            int mid = lo + hi >> 1;
            if (dp[mid][a][b] < k) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << vals[ans] << " \n"[_ == q];
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
