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

struct Linear_Basis {
    #define B 30
    int val[B], cnt;
    Linear_Basis() {
        for (int op = 0; op < B; op++)
            val[op] = 0;
        cnt = 0;
    }
    Linear_Basis operator +(Linear_Basis y) {
        Linear_Basis temp;
        for (int op = 0, w; op < B; op++) {
            if (val[op]) {
                w = val[op];
                for (int i = op; i >= 0; i--) {
                    if (w & (1 << i))
                        if (!temp.val[i]) {
                            temp.val[i] = w;
                            ++ temp.cnt;
                            break;
                        }
                        else
                            w ^= temp.val[i];
                }
            }
            if (y.val[op]) {
                w = y.val[op];
                for (int i = op; i >= 0; i--) {
                    if (w & (1 << i))
                        if (!temp.val[i]) {
                            temp.val[i] = w;
                            ++ temp.cnt;
                            break;
                        }
                        else
                            w ^= temp.val[i];
                }
            }
        }
        return temp;
    }
    int ins(int x) {
        for (int op = B - 1; op >= 0; op--)
            if (x & (1 << op)) {
                if (val[op])
                    x ^= val[op];
                else {
                    val[op] = x;
                    ++cnt;
                    break;
                }
            }
        return x;
    }
    int ask(int x) {
        int res = 0;
        for (int i = 0; i < B; i ++)
            for (int j = i - 1; j >= 0; j --)
                if (val[i] & (1 << j))
                    val[i] ^= val[j];
        for (int op = 0; op < B; op++)
            if (val[op]) {
                if (x & 1)
                    res ^= val[op];
                x >>= 1;
            }
        return (x ? -1 : res);
    }
    #undef B
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    vector<int> fa(n + 1);
    auto dfs = [&](auto self, int u) -> void {
        for (auto v : g[u]) {
            if (v == fa[u]) continue;
            fa[v] = u;
            self(self, v);
        }
    };
    dfs(dfs, 1);

    vector<Linear_Basis> a(n + 1);

    while (m--) {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1) {
            for (int u = x; u; u = fa[u]) {
                if (!a[u].ins(y)) break;
            }
        } else {
            cout << a[x].ask(y) << '\n';
        }

    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}