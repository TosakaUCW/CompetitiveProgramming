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

void solve() {
    int n = read();

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) b[i] = read();

    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        g[u].eb(v), g[v].eb(u);
    }

    int timer = 0;
    vector<int> dfin(n + 1), dfou(n + 1), idx(n + 1);
    vector<int> siz(n + 1), son(n + 1);
    [&](this auto&& dfs, int u, int fa) -> void {
        ++timer;
        dfin[u] = timer;
        idx[timer] = u;

        siz[u] = 1;
        for (int v : g[u]) {
            if (v == fa) continue;
            dfs(v, u);
            siz[u] += siz[v];

            if (siz[v] > siz[son[u]]) son[u] = v;
        }

        dfou[u] = timer;
    } (1, 0);

    int sub = 0;
    vector<int> ans(n + 1);
    vector<int> ca(n + 1), cb(n + 1);

    auto add = [&](int u) {
        int x = a[u], y = b[u];
        if (x and x != y and ca[x] >= cb[x]) sub++;
        if (y and x != y and ca[y] > cb[y]) sub--;
        ca[x]++, cb[y]++;
    };
    auto del = [&](int u) {
        int x = a[u], y = b[u];
        if (x and x != y and ca[x] > cb[x]) sub--;
        if (y and x != y and ca[y] >= cb[y]) sub++;
        ca[x]--, cb[y]--;
    };

    [&](this auto&& dfs, int u, int fa, int keep) -> void {
        for (int v : g[u]) {
            if (v == fa or v == son[u]) continue;
            dfs(v, u, 0);
        }
        if (son[u]) dfs(son[u], u, 1);
        for (int v : g[u]) {
            if (v == fa or v == son[u]) continue;
            for (int i = dfin[v]; i <= dfou[v]; i++) {
                add(idx[i]);
            }
        }
        add(u);
        ans[u] = (sub <= cb[0]);
        if (!keep) {
            for (int i = dfin[u]; i <= dfou[u]; i++) {
                del(idx[i]);
            }
        }
    } (1, 0, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i];
    }
    cout << "\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}