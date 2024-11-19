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

const int inf = 1e18 + 7;
using pii = std::pair<int, int>;
#define fi first
#define se second

struct lichao {
    int n;
    vector<int> x;
    vector<pii> t;

    lichao(vector<int> _x) {
        x = _x;
        n = x.size();
        t.assign(n * 4, {0, inf});
    }

    int calc(int p, int i, int l, int r) {
        auto [kk, bb] = t[i];
        int res = kk * x[p] + bb;
        if (r > l) {
            int m = (l + r) / 2;
            if (p <= m) {
                res = min(res, calc(p, 2 * i + 1, l, m));
            } else {
                res = min(res, calc(p, 2 * i + 2, m + 1, r));
            }
        }
        return res;
    }

    int calc(int p) {
        if (p >= n) return inf;
        return calc(p, 0, 0, n - 1);
    }

    void add(int k, int b, int i, int l, int r) {
        auto [kk, bb] = t[i];
        if (k * x[l] + b <= kk * x[l] + bb &&
            k * x[r] + b <= kk * x[r] + bb) {
            t[i] = {k, b};
            return;
        }
        if (k * x[l] + b >= kk * x[l] + bb &&
            k * x[r] + b >= kk * x[r] + bb) {
            return;
        }
        int m = (l + r) / 2;
        add(k, b, 2 * i + 1, l, m);
        add(k, b, 2 * i + 2, m + 1, r);
    }

    void add(int k, int b) {
        add(k, b, 0, 0, n - 1);
    }
};


void solve() {
    int n = read();
    int k = read();

    vector<int> a(k), b(k);
    for (int i = 0; i < k; i++) {
        b[i] = read();
    }
    for (int i = 0; i < k; i++) {
        a[i] = read();
    }

    vector<vector<int>> x(k);
    vector<vector<int>> w(k);

    for (int i = 0; i < k; i++) {
        int p = read();

        x[i].resize(p);
        w[i].resize(p - 1);
        for (int j = 0; j < p; j++) {
            x[i][j] = read() - 1;
            if (j < p - 1) w[i][j] = read();
        }
    }

    vector<pii> t;
    vector<vector<pii>> g(n);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < x[i].size(); j++) {
            t.eb(i, j);
            g[x[i][j]].eb(b[i], t.size() - 1);
        }
    }

    vector<lichao> tt;
    for (int i = 0; i < n; i++) {
        std::sort(g[i].begin(), g[i].end());
        vector<int> x;
        for (auto [b, _] : g[i]) {
            x.eb(b);
        }
        tt.eb(x);
    }

    int nn = t.size();
    vector<int> dis(nn + n, inf);

    std::set<pii> pq;
    for (auto [_, i] : g[0]) {
        dis[i] = 0;
        pq.ep(0, i);
    }

    vector<int> cur(n, 0);

    while (!pq.empty()) {
        auto p = pq.begin();
        auto [d, v] = *p;
        pq.erase(p);

        if (v < nn) {
            auto [i, j] = t[v];

            if (j + 1 < x[i].size()) {
                int nd = d + w[i][j];
                int u = v + 1;
                if (nd < dis[u]) {
                    pq.erase({dis[u], u});
                    dis[u] = nd;
                    pq.ep(dis[u], u);
                }
            }

            int f = x[i][j];
            if (cur[f] < g[f].size()) {
                int u = f + nn;
                pq.erase({dis[u], u});
                tt[f].add(a[i], d);
                dis[u] = tt[f].calc(cur[f]);
                pq.ep(dis[u], u);
            }

        } else {
            v -= nn;

            int u = g[v][cur[v]].se;

            int nd = tt[v].calc(cur[v]);
            if (nd < dis[u]) {
                pq.erase({dis[u], u});
                dis[u] = nd;
                pq.ep(dis[u], u);
            }

            cur[v]++;

            if (cur[v] < g[v].size()) {
                dis[nn + v] = tt[v].calc(cur[v]);
                pq.ep(dis[nn + v], nn + v);
            }
        }
    }

    for (int i = 1; i < n; i++) {
        int res = inf;
        for (auto [_, j] : g[i]) {
            res = min(res, dis[j]);
        }
        cout << res << " ";
    }
    cout << "\n";
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}