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
    int m = read();
    int s = read();
    int t = read();

    vector<vector<int>> g(n + 1);
    vector<pii> edge(m);
    for (auto &[u, v] : edge) {
        u = read(), v = read();
        g[u].eb(v), g[v].eb(u);
    }

    set<pii> path;
    vector<int> tag(n + 1);
    auto print = [&]() -> void {
        cout << "Yes\n";
        for (auto &[u, v] : edge) {
            if (tag[u]) swap(u, v);
            if (path.find({v, u}) != path.end()) swap(u, v);
            cout << u << " " << v << "\n";
        }
    };

    {
        auto it = find(g[s].begin(), g[s].end(), t);
        if (it == g[s].end()) {
            tag[s] = tag[t] = 1;
            print();
            return;
        } else {
            swap(*it, *g[s].begin());
        }
    }

    if (m == n - 1) {
        cout << "No\n";
        return;
    }

    queue<int> q; q.ep(s);
    vector<int> fa(n + 1);
    while (!q.empty() and path.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (v == fa[u]) continue;
            if (fa[v]) {
                path.ep(u, v);
                for (int p = u; p; p = fa[p]) {
                    tag[p] = 1;
                    path.ep(fa[p], p);
                }
                for (int p = v; !tag[p]; p = fa[p]) {
                    tag[p] = 1;
                    path.ep(p, fa[p]);
                }
                break;
            }
            fa[v] = u, q.ep(v);
        }
    }

    if (!tag[t]) {
        tag[t] = 1;
        path.ep(t, s);
    }
    print();
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}