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
    int n = read(), m = read();
    int x = read(), y = read();

    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u = read();
        int v = read();
        g[u].eb(v);
        g[v].eb(u);
    }

    vector<vector<int>> bad;

    int ed;
    vector<int> path;
    auto dfs = [&](this auto&& dfs, int u, int fa) -> bool {
        path.eb(u);
        if (u == ed) return 1;
        for (int v : g[u]) {
            if (v == fa) continue;
            if (dfs(v, u)) return 1;
        }
        path.pop_back();
        return 0;
    };

    for (int i = 1; i <= m; i++) {
        int a = read();
        int b = read();

        ed = b;
        dfs(a, -1);

        int siz = path.size();
        if (bad.size() < siz) {
            bad.resize(siz);
        }
        for (int j = 0; j < siz; j++) {
            bad[j].eb(path[j]);
        }
        path.clear();
    }

    vector<int> valid(n + 1);
    vector<int> q; q.eb(x);
    vector<int> ban(n + 1);
    vector<int> was(n + 1, -1);

    for (int t = 0; ; t++) {
        if (t < bad.size()) {
            for (auto u : bad[t]) ban[u] = 1;
        }

        vector<int> cand;
        for (auto u : q) {
            if (valid[u] or ban[u] or was[u] == t) continue;
            was[u] = t;
            bool f = 0;
            for (auto v : g[u]) f |= valid[v];
            if (t and !f) continue;
            cand.eb(u);
        }

        q.clear();
        if (t < bad.size()) {
            for (auto u : bad[t]) {
                ban[u] = 0;
                valid[u] = 0;
                q.eb(u);    
            }
        }

        for (auto u : cand) {
            valid[u] = 1;
            for (auto v : g[u]) {
                if (!valid[v]) q.eb(v);
            }
        }

        if (valid[y]) {
            cout << t + 1 << '\n';
            return;
        }
        if (t > bad.size() and q.empty()) {
            cout << "-1\n";
            return;
        }
    }
}

signed main() {
    for (int T = read(); T--; ) solve();
    return 0;
}
