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

struct Node {
    int x1, x2, y;
};

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
    int n = read(), m = read(), k = read();

    vector<Node> a(k);
    for (auto &[x1, x2, y] : a) {
        x1 = read(), x2 = read(), y = read();
    }

    ranges::sort(a, [&](auto i, auto j) {
        return i.y < j.y;
    });

    if (n == 1) {
        cout << "YES\n";
        return;
    }
    if (m > 2 * k + 1) {
        cout << "NO\n";
        return;
    }

    vector<vector<pii>> b(m + 1);
    for (auto [x1, x2, y] : a) {
        b[y].eb(x1, x2);
    }

    for (int i = 1; i + 1 <= m; i++) {
        if (b[i].size() + b[i + 1].size() == 0) {
            cout << "NO\n";
            return;
        }
    }

    for (auto &v : b) {
        v.eb(-inf, 0);
        v.eb(n + 1, inf);
        ranges::sort(v);
    }

    vector<set<int>> g;
    map<array<int, 3>, int> id;
    vector<map<int, int>> b1(m + 1);
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        auto &v = b[i];
        for (int j = 0; j + 1 < v.size(); j++) {
            int l = v[j].se + 1;
            int r = v[j + 1].fi - 1;
            if (l > r) continue;

            b1[i][l] = r;
            id[{i, l, r}] = cnt++;
            g.eb();

            if (i) {
                auto &v1 = b1[i - 1];
                auto it1 = v1.lower_bound(l);
                auto it2 = v1.upper_bound(r);

                if (it1 != v1.begin() and prev(it1)->second >= l) {
                    it1--;
                }

                for (; it1 != it2; it1++) {
                    auto [l1, r1] = *it1;
                    int lc = max(l, l1);
                    int rc = min(r, r1);
                    if (rc - lc + 1 > 1) {
                        cout << "NO\n";
                        return;
                    }

                    int u = id[{i, l, r}];
                    int v = id[{i - 1, l1, r1}];
                    g[u].insert(v);
                    g[v].insert(u);
                }
            }
        }
    }

    DSU dsu(cnt + 1);
    for (int u = 0; u < cnt; u++) {
        for (auto v : g[u]) {
            g[v].erase(u);
            if (!dsu.merge(u, v)) {
                cout << "NO\n";
                return;
            }
        }
    }

    if (dsu.size(0) == cnt) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}