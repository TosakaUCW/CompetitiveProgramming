#include <bits/stdc++.h>
using i64 = long long;
using ull = unsigned long long;
using i128 = __int128;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int n = read();
    vector<int> a(n), b(n);
    for (int &x : a) x = read();
    for (int &x : b) x = read();

    struct Edge { int u, v, dir, used; };
    vector<Edge> e(n);

    vector<vector<int>> g(2 * n + 1);
    for (int i = 0; i < n; i++) {
        e[i].u = a[i];
        e[i].v = b[i];
        
        // if (a[i] == b[i]) {
        //     continue;
        // }

        g[a[i]].eb(i);
        g[b[i]].eb(i);
    }

    vector<int> vis1(2 * n + 1);
    vector<int> vis2(2 * n + 1);

    int rt;
    bool f;
    set<int> s;

    auto dfs1 = [&](this auto&& dfs1, int u) -> void {
        vis1[u] = 1;
        for (int id : g[u]) {
            auto &[x, y, dir, used] = e[id];
            if (used) continue;
            used = 1;
            int v = x ^ y ^ u;
            if (!vis1[v]) {
                dir = (x == u ? 0 : 1);
                dfs1(v);
            } else {
                f |= (v == rt);
                dir = (x == u ? 0 : 1);
            }
        }
    };

    auto dfs2 = [&](this auto&& dfs2, int u) -> void {
        vis2[u] = 1;
        for (int id : g[u]) {
            s.ep(id);
            int v = e[id].u ^ e[id].v ^ u;
            if (!vis2[v] and v != rt) {
                dfs2(v);
            }
        }
    };


    for (int u = 1; u <= 2 * n; u++) {
        if (vis1[u]) continue;
        
        rt = u, f = 1;
        dfs1(u);
        if (f and g[u].size() >= 2) {
            s.clear();
            int id = g[u][0];
            int v = e[id].u ^ e[id].v ^ u;
            dfs2(v);
            for (auto id : s) {
                e[id].dir ^= 1;
            }
        }
    }

    for (int i = 0; i < n; i++) if (e[i].dir) swap(a[i], b[i]);
    int ans = set<int>(a.begin(), a.end()).size() + set<int>(b.begin(), b.end()).size();
    cout << ans << '\n';
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; i++) cout << b[i] << " \n"[i == n - 1];
}

signed main() {
    for (int T = read(); T--; ) solve();
    return 0;
}
